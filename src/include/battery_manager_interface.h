#ifndef BATTERY_MANAGER_INTERFACE_H_
#define BATTERY_MANAGER_INTERFACE_H_

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <linux/can.h>

#include "socketcan.h"
#include "mqtt_transfer.h"
#include "alarm_manager.h"

#define LOW_BAT_WARN_ID         1
#define LOW_BAT_WARN_THRESHOLD  25
#define LOW_BAT_ERROR_ID        2
#define LOW_BAT_ERROR_THRESHOLD 10

class BatteryManager
{
    private:
        SocketCAN::receiveCallback_t receiveCallback;
        SocketCAN * canDevice;
        int32_t canDevId;
        bool configured = false;
        MqttTransfer * mqttBackhaul = NULL;
        AlarmManager * alarmManager = NULL;
        void sendMqttMessage(std::string topic, void *data, size_t length, MqttTransfer::qos_t qos, bool retain)
        {
            if(mqttBackhaul == NULL) return;
            mqttBackhaul->sendMessage(topic, data, length, qos, retain);
        }

    public:
        static void receiveCAN(void * handle, struct can_frame frame);
        bool registerCallback();
        void configureDevice(SocketCAN * can, int32_t deviceId);
        void setupMqtt(MqttTransfer * mqtt);
        void setupAlarmManager(AlarmManager * alarmMan);
        void rebootDevice();
        float batteryVoltage;
        float batterySoC;
};

#endif