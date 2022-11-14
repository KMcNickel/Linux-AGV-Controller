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
#include "opc_ua_server.h"

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

        NLOHMANN_DEFINE_TYPE_INTRUSIVE(axes_t, x, y, z)
        NLOHMANN_DEFINE_TYPE_INTRUSIVE(pose_t, linear, angular)

    private:
        float wheelRadius;
        float wheelBaseLength;
        float wheelBaseWidth;
        bool invertRight;
        float currentVelocity[4];
        float commandedVelocity[4];
        OPCUAServer * opcua;
        std::chrono::time_point<DEFAULT_CLOCK> lastForwardCalculation;
        std::string nodeIdBase;
        uint16_t nodeNs;

        void writeOPCUAValue(std::string id_ext, float value);

    public:
        void startup(float length, float width, float radius, float invertRightWheels);
        void setupOPCUA(OPCUAServer * opcua, uint16_t ns, std::string nodeIdBase);
        void updateCurrentVelocity(wheel_t wheel, float velocity);
        void calculateForwardKinematics(pose_t * currentMotion);
        void calculateInverseKinematics(pose_t requestedMotion);
        float getCommandedVelocity(wheel_t wheel);

};

#endif