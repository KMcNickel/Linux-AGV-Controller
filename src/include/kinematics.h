#ifndef KINEMATICS_H_
#define KINEMATICS_H_

#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include <linux/input.h>
#include <assert.h>
#include <errno.h>
#include <stdio.h>
#include "spdlog/spdlog.h"
#include "global_defines.h"
#include "mqtt_transfer.h"

class Kinematics
{
    public:
        enum wheel_t
        {
            frontLeft,
            frontRight,
            rearLeft,
            rearRight
        };

        struct axes_t
        {
            float x;
            float y;
            float z;
        };

        struct pose_t
        {
            axes_t linear;
            axes_t angular;
        };

    private:
        float wheelRadius;
        float wheelBaseLength;
        float wheelBaseWidth;
        bool invertRight;
        float currentVelocity[4];
        float commandedVelocity[4];
        MqttTransfer * mqtt;
        std::chrono::time_point<std::chrono::steady_clock> lastForwardCalculation;

    public:
        void startup(float length, float width, float radius, float invertRightWheels);
        void setupMqtt(MqttTransfer * mqtt);
        void updateCurrentVelocity(wheel_t wheel, float velocity);
        void calculateForwardKinematics(pose_t * currentMotion);
        void calculateInverseKinematics(pose_t requestedMotion);
        float getCommandedVelocity(wheel_t wheel);

};

#endif