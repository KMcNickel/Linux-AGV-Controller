#include <list>
#include <stdint.h>
#include <string>
#include <fstream>
#include "include/alarm_manager.h"
#include <stdlib.h>
#include "include/opc_ua_server.h"
#include "include/global_defines.h"
#include <open62541/server.h>

#include "spdlog/spdlog.h"

void AlarmManager::setupOPCUA(OPCUAServer * opcua, uint16_t ns, std::string nodeIdBase)
{
    this->opcua = opcua;
    this->nodeIdBase = nodeIdBase;
    this->nodeNs = ns;
}

void AlarmManager::setCallback(std::function<void()> cb)
{
    callback = cb;
}

bool AlarmManager::alarmsAreActive()
{
    return false;
}

void AlarmManager::createAlarmCondition(UA_NodeId * outNodeId, std::string sourceName, std::string name, uint16_t severity)
{
    UA_StatusCode stat;
    UA_NodeId placeholderNodeId;

    if(outNodeId == NULL) outNodeId = &placeholderNodeId;

    addConditionReference(UA_EXPANDEDNODEID_STRING(OPCUA_NODE_NAMESPACE_ID, (char *) sourceName.c_str()));

    createCondition(outNodeId, sourceName, name);

    setConditionSeverity(*outNodeId, severity);

    setConditionEnabledFlag(*outNodeId, true);

    setConditionRetainFlag(*outNodeId, true);
}

bool AlarmManager::addConditionReference(UA_ExpandedNodeId sourceNodeId)
{
    UA_StatusCode stat;

    stat = UA_Server_addReference(opcua->getServer(), UA_NODEID_NUMERIC(0, UA_NS0ID_SERVER),
            UA_NODEID_NUMERIC(0, UA_NS0ID_HASNOTIFIER),
            sourceNodeId, UA_TRUE);

    if(stat != UA_STATUSCODE_GOOD && stat != UA_STATUSCODE_BADDUPLICATEREFERENCENOTALLOWED)
    {
        spdlog::error("Unable to add alarm manager reference: {0}", UA_StatusCode_name(stat));
        return false;
    }

    return true;
}

bool AlarmManager::createCondition(UA_NodeId * outNodeId, std::string conditionSource, std::string name)
{
    UA_StatusCode stat;

    stat = UA_Server_createCondition(opcua->getServer(), UA_NODEID_NULL,
            UA_NODEID_NUMERIC(0, UA_NS0ID_OFFNORMALALARMTYPE),
            UA_QUALIFIEDNAME(0, (char *) name.c_str()),
            UA_NODEID_STRING(nodeNs, (char *) conditionSource.c_str()),
            UA_NODEID_NUMERIC(0, UA_NS0ID_HASCOMPONENT),
            outNodeId);

    if(stat != UA_STATUSCODE_GOOD)
    {
        spdlog::error("Unable to add alarm manager condition: {0}", UA_StatusCode_name(stat));
        return false;
    }

    return true;
}

void AlarmManager::activateCondition(UA_NodeId node)
{
    setConditionActiveFlag(node, true);
    
    setConditionTime(node, UA_DateTime_now());
}

void AlarmManager::activateConditionWithMessage(UA_NodeId node, std::string message)
{
    setConditionMessage(node, message);

    activateCondition(node);
}

void AlarmManager::deactivateAlarmCondition(UA_NodeId node)
{
    setConditionActiveFlag(node, false);
}

void AlarmManager::setConditionActiveFlag(UA_NodeId node, bool active)
{
    UA_Variant value;
    UA_StatusCode stat;

    UA_Variant_setScalar(&value, &active, &UA_TYPES[UA_TYPES_BOOLEAN]);

    stat = UA_Server_setConditionVariableFieldProperty(opcua->getServer(), node,
            &value, OPCUAFieldNames.activeState, OPCUAFieldNames.id);

    if(stat != UA_STATUSCODE_GOOD)
        spdlog::error("Unable to activate alarm condition: {0}", UA_StatusCode_name(stat));
}

void AlarmManager::setConditionEnabledFlag(UA_NodeId node, bool enabled)
{
    UA_Variant value;
    UA_StatusCode stat;

    UA_Variant_setScalar(&value, &enabled, &UA_TYPES[UA_TYPES_BOOLEAN]);

    stat = UA_Server_setConditionVariableFieldProperty(opcua->getServer(), node,
            &value, OPCUAFieldNames.enabledState, OPCUAFieldNames.id);

    if(stat != UA_STATUSCODE_GOOD)
        spdlog::error("Unable to enable alarm condition: {0}", UA_StatusCode_name(stat));
}

void AlarmManager::setConditionTime(UA_NodeId node, int64_t time)
{
    UA_StatusCode stat;

    stat = UA_Server_writeObjectProperty_scalar(opcua->getServer(), node,
            OPCUAFieldNames.time, &time, &UA_TYPES[UA_TYPES_DATETIME]);

    if(stat != UA_STATUSCODE_GOOD)
        spdlog::error("Unable to set alarm condition time: {0}", UA_StatusCode_name(stat));
}

void AlarmManager::setConditionRetainFlag(UA_NodeId node, bool retain)
{
    UA_StatusCode stat;

    stat = UA_Server_writeObjectProperty_scalar(opcua->getServer(), node,
            OPCUAFieldNames.retain, &retain, &UA_TYPES[UA_TYPES_BOOLEAN]);

    if(stat != UA_STATUSCODE_GOOD)
        spdlog::error("Unable to set alarm condition retain flag: {0}", UA_StatusCode_name(stat));
}

void AlarmManager::setConditionSeverity(UA_NodeId node, uint16_t severity)
{
    UA_StatusCode stat;

    stat = UA_Server_writeObjectProperty_scalar(opcua->getServer(), node,
            OPCUAFieldNames.severity, &severity, &UA_TYPES[UA_TYPES_UINT16]);

    if(stat != UA_STATUSCODE_GOOD)
        spdlog::error("Unable to set alarm condition severity: {0}", UA_StatusCode_name(stat));
}

void AlarmManager::setConditionMessage(UA_NodeId node, std::string message)
{
    UA_StatusCode stat;
    UA_Variant value;
    UA_LocalizedText messageValue = UA_LOCALIZEDTEXT("en", (char *) message.c_str());

    UA_Variant_setScalar(&value, &messageValue, &UA_TYPES[UA_TYPES_LOCALIZEDTEXT]);
    stat = UA_Server_setConditionField(opcua->getServer(), node, &value, OPCUAFieldNames.message);

    if(stat != UA_STATUSCODE_GOOD)
        spdlog::error("Unable to set alarm condition message: {0}", UA_StatusCode_name(stat));
}
