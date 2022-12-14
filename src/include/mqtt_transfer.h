#ifndef MQTT_TRANSFER_H_
#define MQTT_TRANSFER_H_

#include <stdio.h>
#include <mosquitto.h>
#include <stdlib.h>
#include <string>
#include <list>
#include <unistd.h>
#include <mosquitto.h>

class MqttTransfer
{
    public:
        typedef void (*mqttMessageReceiveCallback)(void * handle, mosquitto_message * msg);

        enum qos_t : int
        {
            QOS_0_AT_MOST_ONCE = 0,
            QOS_1_AT_LEAST_ONCE = 1,
            QOS_2_EXACTLY_ONCE = 2
        };

        struct mqttReceiveCallback_t
        {
            mqttMessageReceiveCallback callback;
            void * handle;
            std::string topic;
            qos_t qos;
        };

        bool isConnected;
        void setupMQTT(std::string id, std::string addr, int port, std::string deviceName);
        bool connectBroker();
        bool shutdownMQTT();
        void addCallback(mqttReceiveCallback_t * callback);
        void subscribeToCallbackTopics();
        void sendMessage(std::string topic, void * data, size_t length, qos_t qos, bool retain);
        static void brokerConnected(struct mosquitto * mosq, void * obj, int rc);
        static void brokerDisconnected(struct mosquitto * mosq, void * obj, int rc);
        static void messageReceived(struct mosquitto *mosq, void *obj, const struct mosquitto_message *message);
        static void setLogLevelByMQTT(void * handle, mosquitto_message * msg);

    private:
        int keepalive = 5;
        std::string address;
        std::string devName;
        int portNum;
        std::string clientId;
        struct mosquitto * mqttClient;
        std::list<mqttReceiveCallback_t> externalCallbacks;
        mqttReceiveCallback_t loggerLevelSetCallback;
        std::string commStatusTopic;
};

#endif