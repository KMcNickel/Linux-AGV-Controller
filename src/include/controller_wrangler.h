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
#include "pendant_manager.h"
#include "kinematics.h"

class ControllerWrangler
{
    public:
        enum controlMode_t
        {
            Idle,
            Manual,
            Automatic
        };

    private:
        SocketCAN can;
        BatteryManager batteryManager;
        MqttTransfer mqtt;
        OdriveSafeVelocityManager odrive[2];
        PendantManager pendant;
        Kinematics kinematics;
        controlMode_t motorControlMode;
        std::chrono::time_point<std::chrono::steady_clock> lastMotorUpdate;
        std::chrono::milliseconds motorUpdateInterval = std::chrono::milliseconds(100);
        
        void configureBatteryManager();
        void configureODrives();
        void configureCANBus();
        void configureKinematics();
        void configureMQTT();
        void configurePendant();
        void updateMotorVelocities();

    public:
        void gracefulEnd();
        void startup();
        void loop();

};

#endif