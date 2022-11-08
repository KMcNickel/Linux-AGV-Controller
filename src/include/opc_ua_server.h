#ifndef OPC_UA_SERVER_H_
#define OPC_UA_SERVER_H_

#include <open62541/plugin/log_stdout.h>
#include <open62541/server.h>
#include <open62541/server_config_default.h>

#include <spdlog/spdlog.h>
#include <stdlib.h>

class OPCUAServer
{
    public:
        void startServer();
        void stopServer();
        void checkServer();

    private:
        void addVersionStringNode();
        UA_Server * server;
};

#endif