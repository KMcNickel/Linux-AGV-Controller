#ifndef CONTROLLER_WRANGLER_H_
#define CONTROLLER_WRANGLER_H_

#include <stdio.h>
#include <stdbool.h>
#include <stdint.h>
#include <string.h>
#include <csignal>
#include <iostream>
#include <mosquitto.h>

#include <linux/can.h>

#include "spdlog/spdlog.h"
#include "socketcan.h"
#include "battery_manager_interface.h"
#include "global_defines.h"
#include "version_num.h"
#include "mqtt_transfer.h"
#include "odrive_safe_velocity_manager.h"

class ControllerWrangler
{
    private:
        SocketCAN can;
        BatteryManager batteryManager;
        MqttTransfer mqtt;
        OdriveSafeVelocityManager odrive[2];
        void configureBatteryManager();
        void configureODrives();
        void configureCANBus();
        void configureMQTT();

    public:
        void gracefulEnd();
        void startup();
        void loop();

};

#endif