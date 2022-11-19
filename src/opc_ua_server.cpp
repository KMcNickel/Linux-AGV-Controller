#include <open62541/plugin/log_stdout.h>
#include <open62541/server.h>
#include <open62541/server_config_default.h>

#include <spdlog/spdlog.h>
#include <stdlib.h>
#include "include/opc_ua_server.h"
#include "include/version_num.h"
#include "include/nodeset.h"
#include "include/global_defines.h"

void OPCUAServer::startServer()
{
    UA_StatusCode stat;

    spdlog::info("Starting OPC UA Server");

    if(server != NULL)
    {
        spdlog::error("Cannot start an OPC UA server when one is already running");
        return;
    }

    server = UA_Server_new();
    UA_ServerConfig_setDefault(UA_Server_getConfig(server));

    stat = nodeset(server);
    if(stat != UA_STATUSCODE_GOOD)
    {
        spdlog::error("Could not add OPC UA Nodeset: {0}", UA_StatusCode_name(stat));
        server = NULL;
        return;
    }

    setVersionNodeValues();

    stat = UA_Server_run_startup(server);
    if(stat != UA_STATUSCODE_GOOD)
    {
        spdlog::error("OPC UA Server could not start: {0}", UA_StatusCode_name(stat));
        server = NULL;
        return;
    }

    spdlog::debug("OPC UA Server Started");
}

void OPCUAServer::stopServer()
{
    UA_StatusCode stat;

    spdlog::info("Stopping OPC UA Server");

    if(server == NULL)
    {
        spdlog::warn("Attempting to stop an OPC UA server that is not running");
        return;
    }

    stat = UA_Server_run_shutdown(server);
    if(stat != UA_STATUSCODE_GOOD)
        spdlog::error("OPC UA Server could not stop: {0}", UA_StatusCode_name(stat));

    UA_Server_delete(server);

    spdlog::debug("OPC UA Server Stopped");
}

void OPCUAServer::checkServer()
{
    spdlog::trace("Iterating OPC UA Server");

    if(server == NULL)
    {
        spdlog::trace("Cannot iterate an OPC UA server that is not running");
        return;
    }

    UA_Server_run_iterate(server, false);
}

void OPCUAServer::setVersionNodeValues()
{
    UA_StatusCode stat;
    UA_VariableAttributes attr = UA_VariableAttributes_default;
    UA_UInt32 * version = (UA_UInt32 * ) UA_Array_new(4, &UA_TYPES[UA_TYPES_UINT32]);
    UA_Variant value;
    std::string node_id = "softwareversion";

    spdlog::debug("Setting OPC UA Server Version Node Data");

    if(server == NULL)
    {
        spdlog::warn("Cannot set version number value on an OPC UA server that is not running");
        return;
    }

    version[0] = VERSION_MAJOR;
    version[1] = VERSION_MINOR;
    version[2] = VERSION_PATCH;
    version[3] = VERSION_BUILD;

    UA_Variant_setArray(&value, version, 4, &UA_TYPES[UA_TYPES_UINT32]);
    UA_NodeId nodeID = UA_NODEID_STRING(OPCUA_NODE_NAMESPACE_ID, (char *) node_id.c_str());

    stat = UA_Server_writeValue(server, nodeID, value);


    if(stat != UA_STATUSCODE_GOOD)
        spdlog::error("OPC UA Server could not set values of version node: {0}", UA_StatusCode_name(stat));    
}

UA_StatusCode OPCUAServer::writeValueToServer(UA_NodeId id, UA_Variant value)
{
    spdlog::trace("Writing value to OPC UA Server");
    
    if(server == NULL)
    {
        spdlog::trace("Attempting to set value while server is not running");
        return UA_STATUSCODE_BADSERVERHALTED;
    }
    return UA_Server_writeValue(server, id, value);
}

UA_Server * OPCUAServer::getServer()
{
    return server;
}