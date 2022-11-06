#include <list>
#include <stdint.h>
#include <string>
#include <fstream>
#include "include/alarm_manager.h"
#include <stdlib.h>
#include "include/mqtt_transfer.h"
#include "nlohmann/json.hpp"

#include "spdlog/spdlog.h"

void AlarmManager::initializeAlarmList()
{
    std::ifstream jsonFile("alarmList.json");
    std::stringstream jsonFileBuffer;

    jsonFileBuffer << jsonFile.rdbuf();

    nlohmann::json alarmList = nlohmann::json::parse(jsonFileBuffer.str());

    alarms = alarmList;
}

void AlarmManager::setupMqtt(MqttTransfer * mqtt)
{
    this->mqtt = mqtt;
}

void AlarmManager::setCallback(std::function<void()> cb)
{
    callback = cb;
}

bool AlarmManager::alarmsAreActive()
{
    bool active;

    std::for_each(alarms.begin(), alarms.end(), [&](alarmListInfo_t & alarm)
    {
        if(alarm.thrown && alarm.level == Error) active = true;
    });

    return active;
}

void AlarmManager::unmaskAlarm(int id)
{
    std::for_each(alarms.begin(), alarms.end(), [&](alarmListInfo_t & alarm)
    {
        if(alarm.id == id) alarm.masked = false;
    });
}

void AlarmManager::maskAlarm(int id)
{
    std::for_each(alarms.begin(), alarms.end(), [&](alarmListInfo_t & alarm)
    {
        if(alarm.id == id) alarm.masked = true;
    });
}

void AlarmManager::throwAlarm(int id)
{
    bool threwNewAlarm;

    std::for_each(alarms.begin(), alarms.end(), [&](alarmListInfo_t & alarm)
    {
        if(alarm.id != id) return;
        if(alarm.thrown) return;
        if(alarm.masked) return;

        alarm.thrown = true;
        alarm.acknowledged = false;
        if(alarm.level == Error) threwNewAlarm = true;

        switch(alarm.level)
        {
            case Info:
                spdlog::info("Message: {0:d} - {1}", alarm.id, alarm.message);
                break;
            case Warn:
                spdlog::warn("Warning: {0:d} - {1}", alarm.id, alarm.message);
                break;
            case Error:
                spdlog::error("Error: {0:d} - {1}", alarm.id, alarm.message);
                break;
        }
    });

    if(threwNewAlarm) callback();

    if(mqtt)
    {
        std::list<alarmListInfo_t> activeAlarms;
        std::string mqttTopicString = "alarms";

        std::for_each(alarms.begin(), alarms.end(), [&](alarmListInfo_t & alarm)
        {
            if(alarm.thrown)
                activeAlarms.push_back(alarm);
        });
        nlohmann::json data = activeAlarms;
        std::string serializedData = data.dump();

        mqtt->sendMessage(mqttTopicString, (void *) serializedData.c_str(),
                serializedData.length(), MqttTransfer::QOS_1_AT_LEAST_ONCE, true);
    }
}

void AlarmManager::clearAlarm(int id)
{
    std::for_each(alarms.begin(), alarms.end(), [&](alarmListInfo_t & alarm)
    {
        if(alarm.id != id) return;
        if(!alarm.thrown) return;

        alarm.thrown = false;
        alarm.acknowledged = false;

        switch(alarm.level)
        {
            case Info:
                spdlog::info("Cleared message: {0:d}", alarm.id);
                break;
            case Warn:
                spdlog::warn("Cleared warning: {0:d}", alarm.id);
                break;
            case Error:
                spdlog::error("Cleared error: {0:d}", alarm.id);
                break;
        }
    });

    if(mqtt)
    {
        std::list<alarmListInfo_t> activeAlarms;
        std::string mqttTopicString = "alarms";

        std::for_each(alarms.begin(), alarms.end(), [&](alarmListInfo_t & alarm)
        {
            if(alarm.thrown)
                activeAlarms.push_back(alarm);
        });
        nlohmann::json data = activeAlarms;
        std::string serializedData = data.dump();

        mqtt->sendMessage(mqttTopicString, (void *) serializedData.c_str(),
                serializedData.length(), MqttTransfer::QOS_1_AT_LEAST_ONCE, true);
    }
}

void AlarmManager::unmaskAllAlarms()
{
    std::for_each(alarms.begin(), alarms.end(), [&](alarmListInfo_t & alarm)
    {
        alarm.masked = false;
    });
}

void AlarmManager::clearAllAlarms()
{
    std::for_each(alarms.begin(), alarms.end(), [&](alarmListInfo_t & alarm)
    {
        alarm.thrown = false;
        alarm.acknowledged = false;
    });
}

void AlarmManager::acknowledgeAllAlarms()
{
    std::for_each(alarms.begin(), alarms.end(), [&](alarmListInfo_t & alarm)
    {
        alarm.acknowledged = true;
    });
}
