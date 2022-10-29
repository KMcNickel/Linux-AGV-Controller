#include <stdio.h>
#include <stdbool.h>
#include <stdint.h>
#include <string.h>
#include <csignal>
#include <iostream>
#include <mosquitto.h>

#include "spdlog/spdlog.h"
#include "include/global_defines.h"
#include "include/version_num.h"
#include "include/mqtt_transfer.h"
#include "include/controller_wrangler.h"
#include "include/cxxopts.hpp"

using namespace std;

ControllerWrangler controllerWrangler;
cxxopts::Options commandLineOptions("agv_controller", "Controls a self-driving robot");
cxxopts::ParseResult commandLineResult;

void shutdownProgram(int32_t exitCode)
{
    controllerWrangler.gracefulEnd();
    
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
    
    spdlog::debug("Signal Registration Complete");
}

void configureCommandLineOptions(int argc, char ** argv)
{
    commandLineOptions.add_options()
    ("h,help", "Print help")
    ("l,log_level", "log level on startup", cxxopts::value<std::string>()->default_value(GLOBAL_LOG_LEVEL))
    ;

    commandLineResult = commandLineOptions.parse(argc, argv);

    if (commandLineResult.count("help"))
    {
      std::cout << commandLineOptions.help() << std::endl;
      exit(EXIT_SUCCESS);
    }
}

void setLogLevel()
{
    spdlog::level::level_enum newLevel;

    newLevel = spdlog::level::from_str(commandLineResult["log_level"].as<std::string>());

    spdlog::set_level(spdlog::level::info);

    if(newLevel == spdlog::level::off)
        spdlog::warn("Log level set to {0}", spdlog::level::to_string_view(newLevel));
    else
        spdlog::info("Log level set to {0}", spdlog::level::to_string_view(newLevel));

    spdlog::set_level(newLevel);
}

void systemStartup(int argc, char ** argv)
{
    configureCommandLineOptions(argc, argv);

    setLogLevel();

    spdlog::info("Linux AGV Manager");
    spdlog::info("Version: {0:d}.{1:d}.{2:d} Build: {3:d}", VERSION_MAJOR, VERSION_MINOR, VERSION_PATCH, VERSION_BUILD);
    spdlog::info("System Starting Up...");

    registerSignals();

    controllerWrangler.startup();

    spdlog::info("System Start Up Complete");
}

int main(int argc, char ** argv)
{
    systemStartup(argc, argv);

    spdlog::info("System spinning");

    while(1)
    {
        spdlog::trace("Begin main loop iteration");
        controllerWrangler.loop();
    }
}
