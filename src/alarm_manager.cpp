#include <list>
#include <stdint.h>
#include <string>
#include "include/alarm_manager.h"
#include <stdlib.h>
#include "include/mqtt_transfer.h"
#include "nlohmann/json.hpp"

#include "spdlog/spdlog.h"

void AlarmManager::setupMqtt(MqttTransfer * mqtt)
{
    this->mqtt = mqtt;
}

AlarmManager::valueAlarm_t * AlarmManager::addLowValueAlarm
        (float * value, float trigger, float hysteresis, bool isWarning, bool autoClear, std::string message, int32_t id)
{
    valueAlarm_t alarm;

    alarm.currentValue = value;
    alarm.hysteresisValue = hysteresis;
    alarm.info.autoClear = autoClear;
    alarm.info.isActive = false;
    alarm.info.isEnabled = true;
    alarm.info.isWarning = isWarning;
    alarm.info.message = message;
    alarm.info.id = id;
    alarm.triggerValue = trigger;
    alarm.type = ValueAlarmTypeLow;
    
    valueAlarms.push_back(alarm);

    return &valueAlarms.back();
}

AlarmManager::valueAlarm_t * AlarmManager::addHighValueAlarm
        (float * value, float trigger, float hysteresis, bool isWarning, bool autoClear, std::string message, int32_t id)
{
    valueAlarm_t alarm;

    alarm.currentValue = value;
    alarm.hysteresisValue = hysteresis;
    alarm.info.autoClear = autoClear;
    alarm.info.isActive = false;
    alarm.info.isEnabled = true;
    alarm.info.isWarning = isWarning;
    alarm.info.message = message;
    alarm.info.id = id;
    alarm.triggerValue = trigger;
    alarm.type = ValueAlarmTypeHigh;
    
    valueAlarms.push_back(alarm);

    return &valueAlarms.back();
}

void AlarmManager::removeValueAlarm(AlarmManager::valueAlarm_t * alarm)
{
    valueAlarms.remove_if([alarm](valueAlarm_t & alarmTest){return &alarmTest == alarm;});
}

void AlarmManager::disableValueAlarm(valueAlarm_t * alarm)
{
    if(alarm == NULL) return;
    alarm->info.isEnabled = false;
    alarm->info.isActive = false;
}

void AlarmManager::enableValueAlarm(valueAlarm_t * alarm)
{
    if(alarm == NULL) return;
    alarm->info.isEnabled = true;
}

bool AlarmManager::checkAlarms()
{
    bool alarmsPreviouslyActive = alarmsActive;
    std::list<uint32_t> activeAlarms;
    bool changedStates;

    std::for_each(valueAlarms.begin(), valueAlarms.end(), [&](valueAlarm_t & alarm)
    {
        if(alarm.info.isActive)
        {
            if(alarm.info.autoClear)
            {
                switch(alarm.type)
                {
                    case ValueAlarmTypeLow:
                        if(*alarm.currentValue > (alarm.triggerValue + alarm.hysteresisValue))
                        {
                            clearValueAlarm(&alarm);
                            changedStates = true;
                        }
                        break;
                    case ValueAlarmTypeHigh:
                        if(*alarm.currentValue < (alarm.triggerValue - alarm.hysteresisValue))
                        {
                            clearValueAlarm(&alarm);
                            changedStates = true;
                        }
                        break;
                }
            }
        } else {
            switch(alarm.type)
            {
                case ValueAlarmTypeLow:
                    if(*alarm.currentValue < alarm.triggerValue)
                    {
                        if(alarm.info.isWarning) throwValueWarning(&alarm);
                        else throwValueAlarm(&alarm);
                        changedStates = true;
                    }
                    break;
                case ValueAlarmTypeHigh:
                    if(*alarm.currentValue > alarm.triggerValue)
                    {
                        if(alarm.info.isWarning) throwValueWarning(&alarm);
                        else throwValueAlarm(&alarm);
                        changedStates = true;
                    }
                    break;
            }
        }
        if(alarm.info.isActive)
        {
            alarmsActive = true;
            activeAlarms.push_back(alarm.info.id);
        }
    });

    if(mqtt && changedStates)
    {
        nlohmann::json data;
        data["alarmsActive"] = activeAlarms.size() != 0;
        std::string mqttTopicString = "alarms";
        if(data["alarmsActive"])
        {
            nlohmann::json alarmList = activeAlarms;
            data["alarmList"] = alarmList;
        }
        std::string serializedData = data.dump();

        mqtt->sendMessage(mqttTopicString, (void *) serializedData.c_str(),
                serializedData.length(), MqttTransfer::QOS_1_AT_LEAST_ONCE, true);
    }

    return alarmsActive && !alarmsPreviouslyActive;
}

bool AlarmManager::alarmsAreActive()
{
    return alarmsActive;
}

void AlarmManager::clearAlarms()
{
    std::for_each(valueAlarms.begin(), valueAlarms.end(), [this](valueAlarm_t & alarm)
    {
        if(!alarm.info.isActive) return;
        else clearValueAlarm(&alarm);
    });
}

void AlarmManager::throwValueWarning(valueAlarm_t * alarm)
{
    if(alarm->info.isActive)        //Just in case...
    {
        spdlog::trace("Warning {0:d} triggerd while already active", alarm->info.id);
        return;
    }

    alarm->info.isActive = true;

    spdlog::warn("Warning: {0:d} - {1}", alarm->info.id, alarm->info.message);
}

void AlarmManager::throwValueAlarm(valueAlarm_t * alarm)
{
    if(alarm->info.isActive)        //Just in case...
    {
        spdlog::trace("Alarm {0:d} triggerd while already active", alarm->info.id);
        return;
    }

    alarm->info.isActive = true;

    spdlog::error("Alarm: {0:d} - {1}", alarm->info.id, alarm->info.message);
}

void AlarmManager::clearValueAlarm(valueAlarm_t * alarm)
{
    if(!alarm->info.isActive)        //Just in case...
    {
        spdlog::trace("Clear alarm {0:d} triggerd while already inactive", alarm->info.id);
        return;
    }

    alarm->info.isActive = false;

    spdlog::info("Cleared alarm: {0:d}", alarm->info.id);
}
