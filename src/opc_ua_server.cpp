#include <open62541/plugin/log_stdout.h>
#include <open62541/server.h>
#include <open62541/server_config_default.h>

#include <spdlog/spdlog.h>
#include <stdlib.h>
#include "include/opc_ua_server.h"
#include "include/version_num.h"

void OPCUAServer::startServer()
{
    UA_StatusCode stat;

    server = UA_Server_new();
    UA_ServerConfig_setDefault(UA_Server_getConfig(server));

    addVersionStringNode();

    stat = UA_Server_run_startup(server);
    if(stat != UA_STATUSCODE_GOOD)
        spdlog::error("OPC UA Server could not start: {0}", UA_StatusCode_name(stat));
}

void OPCUAServer::stopServer()
{
    UA_StatusCode stat;

    stat = UA_Server_run_shutdown(server);
    if(stat != UA_STATUSCODE_GOOD)
        spdlog::error("OPC UA Server could not stop: {0}", UA_StatusCode_name(stat));
    UA_Server_delete(server);
}

void OPCUAServer::checkServer()
{
    UA_Server_run_iterate(server, false);
}

void OPCUAServer::addVersionStringNode()
{
    UA_StatusCode stat;
    UA_VariableAttributes attr = UA_VariableAttributes_default;
    UA_Int32 * version = (UA_Int32 * ) UA_Array_new(4, &UA_TYPES[UA_TYPES_INT32]);
    UA_UInt32 arrayDims[1] = {4};

    version[0] = VERSION_MAJOR;
    version[1] = VERSION_MINOR;
    version[2] = VERSION_PATCH;
    version[3] = VERSION_BUILD;

    UA_Variant_setArray(&attr.value, version, 4, &UA_TYPES[UA_TYPES_INT32]);
    attr.valueRank = UA_VALUERANK_ANY;
    attr.displayName = UA_LOCALIZEDTEXT("en-US", "software version");

    attr.value.arrayDimensions = arrayDims;
    attr.value.arrayDimensionsSize = 1;

    UA_NodeId versionNumNodeId = UA_NODEID_STRING(1, "software.version");
    UA_QualifiedName versionNumName = UA_QUALIFIEDNAME(1, "software version");
    UA_NodeId parentNodeId = UA_NODEID_NUMERIC(0, UA_NS0ID_OBJECTSFOLDER);
    UA_NodeId parentReferenceNodeId = UA_NODEID_NUMERIC(0, UA_NS0ID_ORGANIZES);
    stat = UA_Server_addVariableNode(server, versionNumNodeId,
            parentNodeId, parentReferenceNodeId, versionNumName,
            UA_NODEID_NUMERIC(0, UA_NS0ID_BASEDATAVARIABLETYPE), attr, NULL, NULL);

    if(stat != UA_STATUSCODE_GOOD)
        spdlog::error("OPC UA Server could not add version node: {0}", UA_StatusCode_name(stat));    
}