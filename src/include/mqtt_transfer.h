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

        struct mqttReceiveCallback_t
        {
            mqttMessageReceiveCallback callback;
            void * handle;
        };

        void setupMQTT(std::string id, std::string addr, int port);
        bool connectBroker();
        bool shutdownMQTT();
        void addCallback(mqttReceiveCallback_t * callback);
        static void messageReceived(struct mosquitto *mosq, void *obj, const struct mosquitto_message *message);
        static void setLogLevelByMQTT(void * handle, mosquitto_message * msg);

    private:
        struct mosquitto * mqttClient;
        int keepalive = 15;
        std::string address;
        int portNum;
        std::string clientId;
        std::list<mqttReceiveCallback_t> externalCallbacks;
};

#endif