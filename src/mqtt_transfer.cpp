#include <stdio.h>
#include <mosquitto.h>
#include <stdlib.h>
#include <string>
#include <unistd.h>

#include "spdlog/spdlog.h"
#include "mosquitto.h"
#include "include/mqtt_transfer.h"

void MqttTransfer::setupMQTT(std::string id, std::string addr, int port)
{
    spdlog::info("Configuring MQTT with broker address: {0} and port: {1:d}", addr, port);
    address = addr;
    portNum = port;

    mosquitto_lib_init();

    mqttClient = mosquitto_new(id.c_str(), true, NULL);
    mosquitto_message_callback_set(mqttClient, messageReceived);
}

bool MqttTransfer::connectBroker()
{
    int rc;

    spdlog::info("Connecting to MQTT Broker");

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

    spdlog::info("MQTT Broker connected successfully");
    return true;
}

bool MqttTransfer::shutdownMQTT()
{
    int rc;

    spdlog::info("Shutting down MQTT Client");
    mosquitto_disconnect(mqttClient);
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

    mosquitto_loop_stop(mqttClient, false);
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
    spdlog::info("Adding MQTT Transfer Receive Callback");
    MqttTransfer::externalCallbacks.insert(MqttTransfer::externalCallbacks.end(), *callback);
}

void MqttTransfer::messageReceived(struct mosquitto *mosq, void *obj, const struct mosquitto_message *message)
{
    mqttReceiveCallback_t * callbackItem = (mqttReceiveCallback_t *)(obj);

    callbackItem->callback(callbackItem->handle, (mosquitto_message *) message);
}