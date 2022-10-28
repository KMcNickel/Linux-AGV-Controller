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
    bool alarmsPreviuslyActive = alarmsActive;

    std::for_each(valueAlarms.begin(), valueAlarms.end(), [this](valueAlarm_t alarm)
    {
        if(alarm.info.isActive)
        {
            if(alarm.info.autoClear)
            {
                switch(alarm.type)
                {
                    case ValueAlarmTypeLow:
                        if(*alarm.currentValue > (alarm.triggerValue + alarm.hysteresisValue))
                            clearValueAlarm(&alarm);
                        break;
                    case ValueAlarmTypeHigh:
                        if(*alarm.currentValue < (alarm.triggerValue - alarm.hysteresisValue))
                            clearValueAlarm(&alarm);
                        break;
                }
            }
            alarmsActive = true;
            return;
        } else {
            switch(alarm.type)
                {
                    case ValueAlarmTypeLow:
                        if(*alarm.currentValue < alarm.triggerValue)
                        {
                            if(alarm.info.isWarning) throwValueWarning(&alarm);
                            else
                            {
                                throwValueAlarm(&alarm);
                                alarmsActive = true;
                            }
                        }
                        break;
                    case ValueAlarmTypeHigh:
                        if(*alarm.currentValue > alarm.triggerValue)
                        {
                            if(alarm.info.isWarning) throwValueWarning(&alarm);
                            else 
                            {
                                throwValueAlarm(&alarm);
                                alarmsActive = true;
                            }
                        }
                        break;
                }
        }
    });

    return alarmsActive & !alarmsPreviuslyActive;
}

bool AlarmManager::alarmsAreActive()
{
    return alarmsActive;
}

void AlarmManager::clearAlarms()
{
    std::for_each(valueAlarms.begin(), valueAlarms.end(), [this](valueAlarm_t alarm)
    {
        if(!alarm.info.isActive) return;
        else
        {
            switch(alarm.type)
                {
                    case ValueAlarmTypeLow:
                        if(*alarm.currentValue > (alarm.triggerValue + alarm.hysteresisValue))
                            clearValueAlarm(&alarm);
                        break;
                    case ValueAlarmTypeHigh:
                        if(*alarm.currentValue < (alarm.triggerValue - alarm.hysteresisValue))
                            clearValueAlarm(&alarm);
                        break;
                }
        }
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

    if(mqtt)
    {
        std::string mqttTopicString = "alarms";
        char mqttMessageString[64];

        sprintf(mqttMessageString, "{Warnings: {%d: 1}}", alarm->info.id);

        mqtt->sendMessage(mqttTopicString, mqttMessageString, strlen(mqttMessageString), MqttTransfer::QOS_2_EXACTLY_ONCE, true);
    }
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

    if(mqtt)
    {
        std::string mqttTopicString = "alarms";
        char mqttMessageString[64];

        sprintf(mqttMessageString, "{Alarms: {%d: 1}}", alarm->info.id);

        mqtt->sendMessage(mqttTopicString, mqttMessageString, strlen(mqttMessageString), MqttTransfer::QOS_2_EXACTLY_ONCE, true);
    }
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

    if(mqtt)
    {
        std::string mqttTopicString = "alarms";
        char mqttMessageString[64];

        if(alarm->info.isWarning)
            sprintf(mqttMessageString, "{Warnings: {%d: 0}}", alarm->info.id);
        else
            sprintf(mqttMessageString, "{Alarms: {%d: 0}}", alarm->info.id);

        mqtt->sendMessage(mqttTopicString, mqttMessageString, strlen(mqttMessageString), MqttTransfer::QOS_2_EXACTLY_ONCE, true);
    }
}
