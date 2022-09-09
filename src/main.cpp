#include <stdio.h>
#include <stdbool.h>
#include <stdint.h>
#include <string.h>
#include <csignal>
#include <iostream>

#define VERSION_MAJOR       0
#define VERSION_MINOR       1
#define VERSION_REVISION    0
#define VERSION_BUILD       0

using namespace std;

void signalHandler(int signal)
{
    switch(signal)  // https://en.cppreference.com/w/cpp/utility/program/SIG_types
    {
        case SIGTERM:   //termination request, sent to the program
            printf("Received SIGTERM. Stopping System...\r\n");
            printf("Goodbye\r\n");
            exit(EXIT_SUCCESS);
            break;
        case SIGSEGV:   //invalid memory access (segmentation fault)
            printf("Received SIGSEGV. Stopping System...\r\n");
            printf("Goodbye\r\n");
            exit(EXIT_SUCCESS);
            break;
        case SIGINT:    //external interrupt, usually initiated by the user
            printf("Received SIGINT. Stopping System...\r\n");
            printf("Goodbye\r\n");
            exit(EXIT_SUCCESS);
            break;
        case SIGILL:    //invalid program image, such as invalid instruction
            printf("Received SIGILL. Stopping System...\r\n");
            printf("Goodbye\r\n");
            exit(EXIT_SUCCESS);
            break;
        case SIGABRT:   //abnormal termination condition, as is e.g. initiated by std::abort()
            printf("Received SIGABRT. Stopping System...\r\n");
            printf("Goodbye\r\n");
            exit(EXIT_SUCCESS);
            break;
        case SIGFPE:    //erroneous arithmetic operation such as divide by zero
            printf("Received SIGFPE. Stopping System...\r\n");
            printf("Goodbye\r\n");
            exit(EXIT_SUCCESS);
            break;
    }
}

void registerSignals()
{
    printf("Registering Signals\r\n");

    signal(SIGTERM, signalHandler);
    signal(SIGSEGV, signalHandler);
    signal(SIGINT, signalHandler);
    signal(SIGILL, signalHandler);
    signal(SIGABRT, signalHandler);
    signal(SIGFPE, signalHandler);
    
    printf("Signal Registration Complete\r\n");
}

void systemStartup()
{
    printf("Linux AGV Battery Manager\r\n");
    printf("Version: %d.%d.%d Build: %d\r\n", VERSION_MAJOR, VERSION_MINOR, VERSION_REVISION, VERSION_BUILD);
    printf("System Starting Up...\r\n");

    registerSignals();

    printf("System Start Up Complete\r\n");
}

int main(int argc, char ** argv)
{
    systemStartup();

    while(1);
}
