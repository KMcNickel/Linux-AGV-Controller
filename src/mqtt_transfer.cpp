#include <stdio.h>
#include <mosquitto.h>
#include <stdlib.h>
#include <string>
#include <unistd.h>

#include "spdlog/spdlog.h"
#include "mosquitto.h"
#include "include/mqtt_transfer.h"

void MqttTransfer::setupMQTT(std::string id, std::string addr, int port, std::string deviceName)
{
    spdlog::debug("Configuring MQTT for {0} with broker address: {1} and port: {2:d}", deviceName, addr, port);
    address = addr;
    portNum = port;
    devName = deviceName;

    mosquitto_lib_init();

    mqttClient = mosquitto_new(id.c_str(), true, this);
    mosquitto_connect_callback_set(mqttClient, brokerConnected);
    mosquitto_message_callback_set(mqttClient, messageReceived);
    mosquitto_disconnect_callback_set(mqttClient, brokerDisconnected);

    loggerLevelSetCallback.callback = setLogLevelByMQTT;
    loggerLevelSetCallback.handle = NULL;
    loggerLevelSetCallback.topic = devName + "/logger/level";
    loggerLevelSetCallback.qos = MqttTransfer::QOS_1_AT_LEAST_ONCE;
    addCallback(&loggerLevelSetCallback);

    commStatusTopic = devName + "/online";
    int8_t stat = -1;
    int rc = mosquitto_will_set(mqttClient, commStatusTopic.c_str(), sizeof(int8_t), &stat, QOS_2_EXACTLY_ONCE, true);
    switch(rc)
    {
        case MOSQ_ERR_SUCCESS:
            spdlog::info("Set MQTT will");
            break;
        case MOSQ_ERR_INVAL:
            spdlog::error("Unable to set MQTT will due to invalid parameters");
            break;
        case MOSQ_ERR_NOMEM:
            spdlog::error("Unable to set MQTT will due to an out of memory condition");
            break;
        case MOSQ_ERR_PAYLOAD_SIZE:
            spdlog::error("Unable to set MQTT will due to the payload length is too large");
            break;
        case MOSQ_ERR_MALFORMED_UTF8:
            spdlog::error("Unable to set MQTT will due to the topic is not valid UTF-8");
            break;
    }
}

bool MqttTransfer::connectBroker()
{
    int rc;

    spdlog::info("Setting up connection to MQTT Broker");

    rc = mosquitto_connect(mqttClient, address.c_str(), portNum, keepalive);
    if(rc != 0)
    {
        spdlog::error("Unable to connect to MQTT broker at {0}:{1:d}", address, portNum);
        if(rc == MOSQ_ERR_INVAL) spdlog::error("An argument was invalid");
        else if(rc == MOSQ_ERR_ERRNO) spdlog::error("Errno {0:d} was reported", errno);
        return false;
    }

    rc = mosquitto_loop_start(mqttClient);
    if(rc != 0)
    {
        spdlog::error("Unable to start MQTT loop");
        if(rc == MOSQ_ERR_INVAL) spdlog::error("An argument was invalid");
        else if(rc == MOSQ_ERR_NOT_SUPPORTED) spdlog::error("Threads are not supported");
        return false;
    }

    spdlog::info("MQTT Broker connecting...");
    return true;
}

bool MqttTransfer::shutdownMQTT()
{
    int rc;

    spdlog::info("Shutting down MQTT Client");
    int8_t stat = 0;
    mosquitto_publish(mqttClient, NULL, commStatusTopic.c_str(), sizeof(int8_t), &stat, QOS_2_EXACTLY_ONCE, true);
    sleep(1);
    rc = mosquitto_disconnect(mqttClient);
    if(rc != 0)
    {
        spdlog::error("Unable to disconnect MQTT client");
        if(rc == MOSQ_ERR_INVAL)
        {
            spdlog::error("An argument was invalid");
            return false;
        }
        else if(rc == MOSQ_ERR_NO_CONN) spdlog::error("The broker is not connected");
    }

    rc = mosquitto_loop_stop(mqttClient, false);
    if(rc != 0)
    {
        spdlog::error("Unable to stop MQTT loop");
        if(rc == MOSQ_ERR_INVAL)
        {
            spdlog::error("An argument was invalid");
            return false;
        }
        else if(rc == MOSQ_ERR_NOT_SUPPORTED) spdlog::error("Threads are not supported");
    }

    mosquitto_destroy(mqttClient);

    spdlog::info("MQTT Client shut down");
    return true;
}

void MqttTransfer::addCallback(mqttReceiveCallback_t * callback)
{
    int rc;

    spdlog::debug("Adding MQTT Transfer Receive Callback");
    if(isConnected)
    {
        rc = mosquitto_subscribe(mqttClient, NULL, callback->topic.c_str(), callback->qos);
        if(rc != MOSQ_ERR_SUCCESS)
        {
            spdlog::error("Unable to subscribe to topic");
            switch(rc)
            {
                case MOSQ_ERR_INVAL:
                    spdlog::error("An argument was invalid");
                    break;
                case MOSQ_ERR_NOMEM:
                    spdlog::error("An out of memory condition has occurred");
                    break;
                case MOSQ_ERR_NO_CONN:
                    spdlog::error("A broker is not connected");
                    break;
                case MOSQ_ERR_MALFORMED_UTF8:
                    spdlog::error("The topic {0} is not valid UTF-8", callback->topic.c_str());
                    break;
                case MOSQ_ERR_OVERSIZE_PACKET:
                    spdlog::error("The resulting packet would be larger than supported by the broker");
                    break;
            }
            return;
        }
    }
    else spdlog::debug("MQTT Broker not connected. Skipping subscribe");

    externalCallbacks.push_back(*callback);
}

void MqttTransfer::subscribeToCallbackTopics()
{
    if(externalCallbacks.size() == 0)
    {
        spdlog::debug("No MQTT Callbacks to subscribe for");
        return;
    }

    spdlog::debug("Subscribing to {0:d} MQTT {1}", externalCallbacks.size(), externalCallbacks.size() == 1 ? "topic" : "topics");
    std::for_each(externalCallbacks.begin(), externalCallbacks.end(), [this](const MqttTransfer::mqttReceiveCallback_t cb)
    {
        int rc;

        spdlog::debug("MQTT Subscribing to Topic: {0}", cb.topic.c_str());
        rc = mosquitto_subscribe(mqttClient, NULL, cb.topic.c_str(), cb.qos);
        if(rc != MOSQ_ERR_SUCCESS)
        {
            spdlog::error("Unable to subscribe to topic");
            switch(rc)
            {
                case MOSQ_ERR_INVAL:
                    spdlog::error("An argument was invalid");
                    break;
                case MOSQ_ERR_NOMEM:
                    spdlog::error("An out of memory condition has occurred");
                    break;
                case MOSQ_ERR_NO_CONN:
                    spdlog::error("A broker is not connected");
                    break;
                case MOSQ_ERR_MALFORMED_UTF8:
                    spdlog::error("The topic {0} is not valid UTF-8", cb.topic.c_str());
                    break;
                case MOSQ_ERR_OVERSIZE_PACKET:
                    spdlog::error("The resulting packet would be larger than supported by the broker");
                    break;
            }
            return;
        }
    });
}

void MqttTransfer::sendMessage(std::string topic, void * data, size_t length, qos_t qos, bool retain)
{
    if(!isConnected) return;

    int rc;
    std::string fullTopic = devName + "/" + topic;

    spdlog::debug("Sending MQTT message to topic: {0}", fullTopic.c_str());

    rc = mosquitto_publish(mqttClient, NULL, const_cast<char *>(fullTopic.c_str()), length, data, qos, retain);
    if(rc != MOSQ_ERR_SUCCESS)
    {
        spdlog::error("Unable to subscribe to topic");
        switch(rc)
        {
            case MOSQ_ERR_INVAL:
                spdlog::error("An argument was invalid");
                break;
            case MOSQ_ERR_NOMEM:
                spdlog::error("An out of memory condition has occurred");
                break;
            case MOSQ_ERR_NO_CONN:
                spdlog::error("A broker is not connected");
                break;
            case MOSQ_ERR_PROTOCOL:
                spdlog::error("There was a communication protocol error");
                break;
            case MOSQ_ERR_PAYLOAD_SIZE:
                spdlog::error("The payload length is too large");
                break;
            case MOSQ_ERR_MALFORMED_UTF8:
                spdlog::error("The topic {0} is not valid UTF-8", fullTopic.c_str());
                break;
            case MOSQ_ERR_QOS_NOT_SUPPORTED:
                spdlog::error("The QOS value is not supported");
                break;
            case MOSQ_ERR_OVERSIZE_PACKET:
                spdlog::error("The resulting packet would be larger than supported by the broker");
                break;
        }
        return;
    }
}

void MqttTransfer::messageReceived(struct mosquitto *mosq, void *obj, const struct mosquitto_message *message)
{
    MqttTransfer * classObj = (MqttTransfer *)(obj);

    spdlog::debug("Received MQTT message on {0}", message->topic);

    std::for_each(classObj->externalCallbacks.begin(), classObj->externalCallbacks.end(),
            [message](const MqttTransfer::mqttReceiveCallback_t cb)
    {
        if(cb.topic == message->topic) cb.callback(cb.handle, (mosquitto_message *) message);
    });
}

void MqttTransfer::setLogLevelByMQTT(void * handle, mosquitto_message * msg)
{
    std::string data((char *)(msg->payload));
    spdlog::level::level_enum newLevel;

    spdlog::debug("Attempting to set log level by MQTT");

    newLevel = spdlog::level::from_str(data);

    spdlog::set_level(spdlog::level::info);
    spdlog::info("Changing log level to {0} via MQTT", data);
    spdlog::set_level(newLevel);
}

void MqttTransfer::brokerConnected(struct mosquitto * mosq, void * obj, int rc)
{
    MqttTransfer * mqttObj = (MqttTransfer *) obj;

    if(rc)
    {
        spdlog::error("Broker connection failed");
        switch(rc)  //From: http://docs.oasis-open.org/mqtt/mqtt/v3.1.1/errata01/os/mqtt-v3.1.1-errata01-os-complete.html#_Toc442180848
        {
            case 1: //Connection Refused, unacceptable protocol version
                spdlog::error("The connection was refused due to an unacceptable protocol version");
                break;
            case 2: //Connection Refused, identifier rejected
                spdlog::error("The connection was refused due to the identifier being rejected");
                break;
            case 3: //Connection Refused, Connection Refused, Server unavailable
                spdlog::error("The connection was refused due to the server being unavailable");
                break;
            case 4: //Connection Refused, bad user name or password
                spdlog::error("The connection was refused due to a bad username or password");
                break;
            case 5: //Connection Refused, not authorized
                spdlog::error("The connection was refused due to the client not being authorized");
                break;
        }
        mqttObj->isConnected = false;
        return;
    }

    spdlog::info("MQTT Broker connected!");
    mqttObj->isConnected = true;

    int8_t stat = 1;
    mosquitto_publish(mqttObj->mqttClient, NULL, mqttObj->commStatusTopic.c_str(), sizeof(int8_t), &stat, QOS_2_EXACTLY_ONCE, true);

    mqttObj->subscribeToCallbackTopics();
}

void MqttTransfer::brokerDisconnected(struct mosquitto * mosq, void * obj, int rc)
{
    MqttTransfer * mqttObj = (MqttTransfer *) obj;

    if(rc == 0) spdlog::info("The MQTT broker has disconnected gracefully");
    else spdlog::error("The MQTT broker has disconnected with code {0:d}", rc);

    mqttObj->isConnected = false;
}