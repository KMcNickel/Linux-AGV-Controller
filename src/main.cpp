#include <stdio.h>
#include <stdbool.h>
#include <stdint.h>
#include <string.h>
#include <csignal>
#include <iostream>

#include <linux/can.h>

#include "spdlog/spdlog.h"
#include "include/socketcan.h"

#define VERSION_MAJOR       0
#define VERSION_MINOR       1
#define VERSION_REVISION    0
#define VERSION_BUILD       3

#define CAN_DEVICE_ID_MASK 0x7E0
#define CONVERT_CAN_DEVICE_ID_TO_CAN_ID(dev)(dev << 5)

using namespace std;

SocketCAN can;
SocketCAN::receiveCallback_t rxCallback;

void shutdownProgram(int32_t exitCode)
{
    can.killSocket();
    spdlog::info("Goodbye");
    exit(exitCode);
}

void signalHandler(int signal)
{
    switch(signal)  // https://en.cppreference.com/w/cpp/utility/program/SIG_types
    {
        case SIGTERM:   //termination request, sent to the program
            spdlog::critical("Received SIGTERM. Stopping System...");
            shutdownProgram(EXIT_SUCCESS);
            break;
        case SIGSEGV:   //invalid memory access (segmentation fault)
            spdlog::critical("Received SIGSEGV. Stopping System...");
            shutdownProgram(EXIT_SUCCESS);
            break;
        case SIGINT:    //external interrupt, usually initiated by the user
            spdlog::critical("Received SIGINT. Stopping System...");
            shutdownProgram(EXIT_SUCCESS);
            break;
        case SIGILL:    //invalid program image, such as invalid instruction
            spdlog::critical("Received SIGILL. Stopping System...");
            shutdownProgram(EXIT_SUCCESS);
            break;
        case SIGABRT:   //abnormal termination condition, as is e.g. initiated by std::abort()
            spdlog::critical("Received SIGABRT. Stopping System...");
            shutdownProgram(EXIT_SUCCESS);
            break;
        case SIGFPE:    //erroneous arithmetic operation such as divide by zero
            spdlog::critical("Received SIGFPE. Stopping System...");
            shutdownProgram(EXIT_SUCCESS);
            break;
    }
}

void registerSignals()
{
    spdlog::info("Registering Signals");

    signal(SIGTERM, signalHandler);
    signal(SIGSEGV, signalHandler);
    signal(SIGINT, signalHandler);
    signal(SIGILL, signalHandler);
    signal(SIGABRT, signalHandler);
    signal(SIGFPE, signalHandler);
    
    spdlog::info("Signal Registration Complete");
}

void systemStartup()
{
    spdlog::info("Linux AGV Battery Manager");
    spdlog::info("Version: {0:d}.{1:d}.{2:d} Build: {3:d}", VERSION_MAJOR, VERSION_MINOR, VERSION_REVISION, VERSION_BUILD);
    spdlog::info("System Starting Up...");

    registerSignals();

    spdlog::info("System Start Up Complete");
}

void receiveCAN(struct can_frame frame)
{
    spdlog::info("Received: {0:d}", frame.can_id);
}

int main(int argc, char ** argv)
{
    struct can_frame frame;

    systemStartup();

    spdlog::set_level(spdlog::level::info);



    while(1)
    {
        can.receiveData();
    }
}
