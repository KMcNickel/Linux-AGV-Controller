#include <stdio.h>
#include <stdbool.h>
#include <stdint.h>
#include <string.h>
#include <csignal>
#include <iostream>
#include <mosquitto.h>

#include <linux/can.h>

#include "spdlog/spdlog.h"
#include "include/socketcan.h"
#include "include/battery_manager_interface.h"
#include "include/global_defines.h"
#include "include/version_num.h"
#include "include/mqtt_transfer.h"

using namespace std;

SocketCAN can;
BatteryManager batteryManager;
MqttTransfer mqtt;

void shutdownProgram(int32_t exitCode)
{
    can.killSocket();
    if(mqtt.isConnected) mqtt.shutdownMQTT();
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

void configureCANBus()
{
    spdlog::info("Configuring CAN Bus...");

    can.configureSocketCAN("can0");

    batteryManager.configureDevice(&can, 0x4);
    batteryManager.registerCallback();
    batteryManager.rebootDevice();
    batteryManager.setupMqtt(&mqtt);

    spdlog::info("CAN Bus Configured");
}

void configureMQTT()
{
    spdlog::info("Configuring MQTT...");
    mqtt.setupMQTT("AGV01", "192.168.2.163", 1883, DEVICE_NAME);
    mqtt.connectBroker();
    spdlog::info("MQTT configured");
}

void systemStartup()
{
    spdlog::set_level(GLOBAL_LOG_LEVEL);

    spdlog::info("Linux AGV Battery Manager");
    spdlog::info("Version: {0:d}.{1:d}.{2:d} Build: {3:d}", VERSION_MAJOR, VERSION_MINOR, VERSION_PATCH, VERSION_BUILD);
    spdlog::info("System Starting Up...");

    registerSignals();
    configureMQTT();
    configureCANBus();

    spdlog::info("System Start Up Complete");
}

int main(int argc, char ** argv)
{
    systemStartup();

    spdlog::info("System spinning");

    while(1)
    {
        spdlog::trace("Begin main loop iteration");
        can.receiveData();
    }
}
