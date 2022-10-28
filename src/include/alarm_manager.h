#ifndef ALARM_MANAGER_H_
#define ALARM_MANAGER_H_

#include <list>
#include <stdint.h>
#include <string>
#include "mqtt_transfer.h"

class AlarmManager
{
    public:
        struct alarmInfo_t
        {
            bool isEnabled;
            bool isActive;
            bool isWarning;
            bool autoClear;
            std::string message;
            int32_t id;
        };

        enum valueAlarmType
        {
            ValueAlarmTypeLow,
            ValueAlarmTypeHigh
        };

        struct valueAlarm_t
        {
            float * currentValue;
            float triggerValue;
            float hysteresisValue;
            valueAlarmType type;
            alarmInfo_t info;
        };

        void setupMqtt(MqttTransfer * mqtt);
        
        valueAlarm_t * addLowValueAlarm
                (float * value, float trigger, float hysteresis, bool isWarning, bool autoClear, std::string message, int32_t id);
        valueAlarm_t * addHighValueAlarm
                (float * value, float trigger, float hysteresis, bool isWarning, bool autoClear, std::string message, int32_t id);

        void removeValueAlarm(valueAlarm_t * alarm);
        void disableValueAlarm(valueAlarm_t * alarm);
        void enableValueAlarm(valueAlarm_t * alarm);

        bool checkAlarms();
        bool alarmsAreActive();
        void clearAlarms();

    private:
        std::list<valueAlarm_t> valueAlarms;
        bool alarmsActive;
        MqttTransfer * mqtt;

        void throwValueWarning(valueAlarm_t * alarm);
        void throwValueAlarm(valueAlarm_t * alarm);
        void clearValueAlarm(valueAlarm_t * alarm);
};

#endif