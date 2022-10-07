#ifndef PENDANT_MANAGER_H_
#define PENDANT_MANAGER_H_

#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include <linux/input.h>
#include <assert.h>
#include <errno.h>
#include <stdio.h>
#include "spdlog/spdlog.h"
#include "mqtt_transfer.h"
#include "nlohmann/json.hpp"

class PendantManager
{
    public:
        struct joystick_t
        {
            int x;
            int y;
        };

        struct gamepad_t
        {
            joystick_t leftJoystick;
            joystick_t rightJoystick;
            unsigned char leftTrigger;
            unsigned char rightTrigger;
            joystick_t dPad;
            bool a;
            bool b;
            bool x;
            bool y;
            bool select;
            bool start;
            bool home;
            bool l;
            bool r;
            bool leftJoystickButton;
            bool rightJoystickButton;
        };

        NLOHMANN_DEFINE_TYPE_INTRUSIVE(joystick_t, x, y)
        NLOHMANN_DEFINE_TYPE_INTRUSIVE(gamepad_t, leftJoystick, rightJoystick,
                leftTrigger, rightTrigger, dPad, a, b, x, y, select, start, home,
                l, r, leftJoystickButton, rightJoystickButton)

    private:
        int gamepadDevice;
        bool running;
        gamepad_t currentState;
        MqttTransfer * mqtt;
        std::chrono::time_point<std::chrono::steady_clock> lastStateSend;
        std::chrono::milliseconds StateSendInterval = std::chrono::milliseconds(100);

        void sendState();
        void readDevice();

    public:
        void startup();
        void setupMqtt(MqttTransfer * mqtt);
        void maintenanceLoop();
};

#endif

/* 8BitDo Pro 2 Gamepad Settings
 * 
 * Down - Y Pos, Up - Y Neg, Right - X Pos, Left - X Neg
 * -32,768 to 32,767
 * Left Joystick: ABS_X and ABS_Y
 * Right Joystick: ABS_RX and ABS_RY
 * -1 to 1
 * D-Pad: ABS_HAT0X and ABS_HAT0Y
 * 
 * Press - 255, Release - 0
 * Left Trigger: ABS_Z
 * Right Trigger: ABS_RZ
 * 
 * Press - 1, Release - 0
 * A, B, X, Y, SELECT, START: BTN_n
 * Home: BTN_MODE
 * L, R: BTN_Tn
 * L Joy Press: BTN_THUMBL
 * R Joy Press: BTN_THUMBR
 */