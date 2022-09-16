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

    spdlog::info("MQTT Broker connected successfully");
    return true;
}