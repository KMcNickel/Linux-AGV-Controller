#ifndef ODRIVE_MANAGER_H_
#define ODRIVE_MANAGER_H_

#include <stdio.h>
#include <mosquitto.h>
#include <stdlib.h>
#include <string>
#include <unistd.h>
#include <signal.h>

#include "spdlog/spdlog.h"
#include "odrive_interface.h"
#include "mqtt_transfer.h"
#include "socketcan.h"

class OdriveSafeVelocityManager
{
    public:
        enum odriveBoardConfig_t
        {
            Unconfigured = 0,
            SingleAxis = 1,
            DualAxis = 2
        };

        enum axis_t
        {
            AxisNone = 0,
            AxisA = 1,
            AxisB = 2,
            AxisAll = 3
        };

        void configureSingleAxis(std::string name, SocketCAN * can, int32_t axisDeviceId);
        void configureDualAxis(std::string name, SocketCAN * can, int32_t axisADeviceId, int32_t axisBDeviceId);
        void setupMqtt(MqttTransfer * mqtt);
        bool isConfigured();
        bool hasErrors();
        void requestErrors(axis_t axis);
        void setVelocity(axis_t axis, float velocity, float torqueFF);
        float getVelocity(axis_t axis);
        void rebootBoard();
        void eStopBoard();
        void stopBoard();
        void startBoard();
        void stopAxis(axis_t axis);
        void startAxis(axis_t axis);
        void feedWatchdog();
        void checkTimers();

    private:
        odriveBoardConfig_t configured;
        OdriveInterface axisA;
        OdriveInterface axisB;
        std::string name;
        bool incomingWatchdogExpired;
        std::chrono::time_point<std::chrono::steady_clock> lastErrorRequest;
        std::chrono::time_point<std::chrono::steady_clock> lastWatchdogFeed;
        std::chrono::milliseconds errorRequestInterval = std::chrono::milliseconds(250);
        std::chrono::milliseconds incomingWatchdogTimeout = std::chrono::milliseconds(500);
        bool checkIfConfigured(std::string caller);
        bool checkIfDualAxis(std::string caller);
        void logStartOfAction(std::string actionName);
        bool checkIfErrorsExist(std::string caller);
};

#endif