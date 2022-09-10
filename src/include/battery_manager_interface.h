#ifndef BATTERY_MANAGER_INTERFACE_H_
#define BATTERY_MANAGER_INTERFACE_H_

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <linux/can.h>

#include "socketcan.h"

class BatteryManager
{
    private:
        SocketCAN::receiveCallback_t receiveCallback;

    public:
        void registerCallback(SocketCAN * can, int32_t deviceId);
        float batteryVoltage;
        float batterySoC;
};

#endif