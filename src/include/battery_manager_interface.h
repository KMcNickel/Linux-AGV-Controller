#ifndef BATTERY_MANAGER_INTERFACE_H_
#define BATTERY_MANAGER_INTERFACE_H_

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <linux/can.h>

#include "socketcan.h"
#include "mqtt_transfer.h"

class BatteryManager
{
    private:
        SocketCAN::receiveCallback_t receiveCallback;
        SocketCAN * canDevice;
        int32_t canDevId;
        bool configured = false;
        MqttTransfer * mqttBackhaul = NULL;

    public:
        static void receiveCAN(void * handle, struct can_frame frame);
        bool registerCallback();
        void configureDevice(SocketCAN * can, int32_t deviceId);
        void setupMqtt(MqttTransfer * mqtt);
        void rebootDevice();
        float batteryVoltage;
        float batterySoC;
};

#endif