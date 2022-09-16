#ifndef MQTT_TRANSFER_H_
#define MQTT_TRANSFER_H_

#include <stdio.h>
#include <mosquitto.h>
#include <stdlib.h>
#include <string>
#include <unistd.h>
#include <mosquitto.h>

class MqttTransfer
{
    private:
        struct mosquitto * mqttClient;
        int keepalive = 15;
        std::string address;
        int portNum;
        std::string clientId;

    public:
        void setupMQTT(std::string id, std::string addr, int port);
        bool connectBroker();
};

#endif