#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include <linux/input.h>
#include <assert.h>
#include <errno.h>
#include <stdio.h>
#include "spdlog/spdlog.h"
#include "include/global_defines.h"
#include "include/pendant_manager.h"
#include "include/mqtt_transfer.h"
#include "nlohmann/json.hpp"

void PendantManager::startup()
{
    spdlog::info("Starting up Pendant Manager");
    gamepadDevice = open(PENDANT_INPUT, O_RDONLY | O_NONBLOCK);

    if(gamepadDevice == -1)
        spdlog::error("Unable to open pendant device file");
        
    if(gamepadDevice != -1)
        running = true;

    spdlog::info("Pendant Manager Start Up done");
}

void PendantManager::setupMqtt(MqttTransfer * mqtt)
{
    spdlog::info("Setting up MQTT for Pendant Manager");

    this->mqtt = mqtt;

    spdlog::info("MQTT Set up for Pendant Manager");
}

void PendantManager::readDevice() {
    struct input_event events[8];

    if(!running)
    {
        spdlog::trace("Pendant Device is not open");
        return;
    }

    ssize_t readLength = read(gamepadDevice, events, sizeof(events));

    if (readLength != -1) {
        int new_event_count = readLength / sizeof(struct input_event);
        for (int evi=0; evi<new_event_count; evi++) {
            auto& ev = events[evi];
            switch (ev.type) {
                case EV_ABS:
                    switch (ev.code) {
                        case ABS_X:
                            spdlog::trace("Left Joystick X Value: {0:d}", ev.value);
                            currentState.leftJoystick.x = ev.value;
                            break;
                        case ABS_Y:
                            spdlog::trace("Left Joystick Y Value: {0:d}", ev.value);
                            currentState.leftJoystick.y = ev.value;
                            break;
                        case ABS_Z:
                            spdlog::trace("Left Trigger Value: {0:d}", ev.value);
                            currentState.leftTrigger = ev.value;
                            break;
                        case ABS_RX:
                            spdlog::trace("Right Joystick X Value: {0:d}", ev.value);
                            currentState.rightJoystick.x = ev.value;
                            break;
                        case ABS_RY:
                            spdlog::trace("Right Joystick Y Value: {0:d}", ev.value);
                            currentState.rightJoystick.y = ev.value;
                            break;
                        case ABS_RZ:
                            spdlog::trace("Right Trigger Value: {0:d}", ev.value);
                            currentState.rightTrigger = ev.value;
                            break;
                        case ABS_HAT0X:
                            spdlog::trace("D-Pad X Value: {0:d}", ev.value);
                            currentState.dPad.x = ev.value;
                            break;
                        case ABS_HAT0Y:
                            spdlog::trace("D-Pad Y Value: {0:d}", ev.value);
                            currentState.dPad.y = ev.value;
                            break;
                        default:
                            break;
                    }
                    break;
                case EV_KEY:
                    switch (ev.code) {
                        case BTN_A:
                            if(ev.value) spdlog::trace("A Button Pressed");
                            else spdlog::trace("A Button Released");
                            currentState.a = ev.value;
                            break;
                        case BTN_B:
                            if(ev.value) spdlog::trace("B Button Pressed");
                            else spdlog::trace("B Button Released");
                            currentState.b = ev.value;
                            break;
                        case BTN_X:
                            if(ev.value) spdlog::trace("X Button Pressed");
                            else spdlog::trace("X Button Released");
                            currentState.x = ev.value;
                            break;
                        case BTN_Y:
                            if(ev.value) spdlog::trace("Y Button Pressed");
                            else spdlog::trace("Y Button Released");
                            currentState.y = ev.value;
                            break;
                        case BTN_TL:
                            if(ev.value) spdlog::trace("L Button Pressed");
                            else spdlog::trace("L Button Released");
                            currentState.l = ev.value;
                            break;
                        case BTN_TR:
                            if(ev.value) spdlog::trace("R Button Pressed");
                            else spdlog::trace("R Button Released");
                            currentState.r = ev.value;
                            break;
                        case BTN_THUMBL:
                            if(ev.value) spdlog::trace("Left Joystick Button Pressed");
                            else spdlog::trace("Left Joystick Button Released");
                            currentState.leftJoystickButton = ev.value;
                            break;
                        case BTN_THUMBR:
                            if(ev.value) spdlog::trace("Right Joystick Button Pressed");
                            else spdlog::trace("Right Joystick Button Released");
                            currentState.rightJoystickButton = ev.value;
                            break;
                        case BTN_SELECT:
                            if(ev.value) spdlog::trace("Select Button Pressed");
                            else spdlog::trace("Select Button Released");
                            currentState.select = ev.value;
                            break;
                        case BTN_START:
                            if(ev.value) spdlog::trace("Start Button Pressed");
                            else spdlog::trace("Start Button Released");
                            currentState.start = ev.value;
                            break;
                        case BTN_MODE:
                            if(ev.value) spdlog::trace("Home Button Pressed");
                            else spdlog::trace("Home Button Released");
                            currentState.home = ev.value;
                            break;
                        default:
                            break;
                    }
                    break;
            }
        }
    }
    else if(errno != EWOULDBLOCK && errno != EAGAIN)
    {
        spdlog::error("Unable to read from Pendant Device: {0}. Device will be closed", strerror(errno));
        running = false;
        close(gamepadDevice);
    }
}

void PendantManager::sendState()
{
    nlohmann::json data = currentState;
    std::string serializedData = data.dump();

    mqtt->sendMessage("pendant", (void *) serializedData.c_str(),
            serializedData.length(), MqttTransfer::QOS_0_AT_MOST_ONCE, false);
}

void PendantManager::maintenanceLoop()
{
    readDevice();

    std::chrono::time_point<DEFAULT_CLOCK> now = DEFAULT_CLOCK::now();
    std::chrono::milliseconds stateSendElapsedMs = std::chrono::duration_cast<std::chrono::milliseconds>(now - lastStateSend);

    if(stateSendElapsedMs > stateSendElapsedMs)
    {
        sendState();

        lastStateSend = now;
    }
}