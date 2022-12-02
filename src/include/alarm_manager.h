#ifndef ALARM_MANAGER_H_
#define ALARM_MANAGER_H_

#include <list>
#include <stdint.h>
#include <string>
#include <stdlib.h>
#include "opc_ua_server.h"

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

        void setupOPCUA(OPCUAServer * opcua, uint16_t ns, std::string nodeIdBase);
        void setCallback(std::function<void()> cb);

        bool alarmsAreActive();

        void createAlarmCondition(UA_NodeId * outNodeId, std::string sourceName, std::string name, uint16_t severity);
        void activateConditionWithMessage(UA_NodeId node, std::string message);
        void deactivateAlarmCondition(UA_NodeId node);

    private:
        std::list<alarmListInfo_t> alarms;
        OPCUAServer * opcua = NULL;
        std::function<void()> callback;
        std::string nodeIdBase;
        uint16_t nodeNs;
        UA_NodeId conditionNodeId;

        bool addConditionReference(UA_ExpandedNodeId sourceNodeId);
        bool createCondition(UA_NodeId * outNodeId, std::string conditionSource, std::string name);
        void activateCondition(UA_NodeId node);
        void setConditionActiveFlag(UA_NodeId node, bool active);
        void setConditionEnabledFlag(UA_NodeId node, bool enabled);
        void setConditionTime(UA_NodeId node, int64_t time);
        void setConditionRetainFlag(UA_NodeId node, bool retain);
        void setConditionSeverity(UA_NodeId node, uint16_t severity);
        void setConditionMessage(UA_NodeId node, std::string message);

        struct
        {
            UA_QualifiedName enabledState = UA_QUALIFIEDNAME(0,"EnabledState");
            UA_QualifiedName ackedState = UA_QUALIFIEDNAME(0,"AckedState");
            UA_QualifiedName confirmedState = UA_QUALIFIEDNAME(0,"ConfirmedState");
            UA_QualifiedName activeState = UA_QUALIFIEDNAME(0,"ActiveState");
            UA_QualifiedName severity = UA_QUALIFIEDNAME(0,"Severity");
            UA_QualifiedName message = UA_QUALIFIEDNAME(0,"Message");
            UA_QualifiedName comment = UA_QUALIFIEDNAME(0,"Comment");
            UA_QualifiedName retain = UA_QUALIFIEDNAME(0,"Retain");
            UA_QualifiedName time = UA_QUALIFIEDNAME(0,"Time");
            UA_QualifiedName id = UA_QUALIFIEDNAME(0,"Id");
        } OPCUAFieldNames;
};

#endif