#ifndef ALARM_MANAGER_H_
#define ALARM_MANAGER_H_

#include <list>
#include <stdint.h>
#include <string>
#include <stdlib.h>
#include "mqtt_transfer.h"
#include "nlohmann/json.hpp"

class AlarmManager
{

    public:
        enum alarmLevel
        {
            Info = 1,
            Warn = 2,
            Error = 3
        };
        
        struct alarmListInfo_t
        {
            int32_t id;
            std::string message;
            alarmLevel level;
            bool masked;
            bool thrown;
            bool acknowledged;
        };
        
        NLOHMANN_DEFINE_TYPE_INTRUSIVE(alarmListInfo_t, id, message, level)

        void initializeAlarmList();
        void setupMqtt(MqttTransfer * mqtt);
        void setCallback(std::function<void()> cb);

        bool alarmsAreActive();

        void unmaskAlarm(int id);
        void maskAlarm(int id);
        void throwAlarm(int id);
        void clearAlarm(int id);
        void unmaskAllAlarms();
        void clearAllAlarms();
        void acknowledgeAllAlarms();

    private:
        std::list<alarmListInfo_t> alarms;
        MqttTransfer * mqtt;
        std::function<void()> callback;
};

#endif