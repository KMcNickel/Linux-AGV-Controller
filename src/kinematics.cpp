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
#include "include/kinematics.h"
#include "include/opc_ua_server.h"

#define RADIANS_PER_CIRCLE 6.28319

void Kinematics::startup(float length, float width, float radius, float invertRightWheels)
{
    wheelBaseLength = length;
    wheelBaseWidth = width;
    wheelRadius = radius;
    invertRight = invertRightWheels;
}

void Kinematics::setupOPCUA(OPCUAServer * opcua, uint16_t ns, std::string nodeIdBase)
{
    spdlog::debug("Setting up OPC UA for Kinematics with node base: {0} and namespace {1:d}", nodeIdBase, ns);
    this->opcua = opcua;
    nodeNs = ns;
    this->nodeIdBase = nodeIdBase;
}

void Kinematics::updateCurrentVelocity(wheel_t wheel, float velocity)
{
    switch(wheel)
    {
        case frontLeft:
            spdlog::trace("Front Left Wheel Velocity is currently: {0:f}", velocity);
            currentVelocity[0] = velocity;
            break;
        case frontRight:
            spdlog::trace("Front Right Wheel Velocity is currently: {0:f}", velocity);
            currentVelocity[1] = velocity;
            if(invertRight) currentVelocity[1] *= -1;
            break;
        case rearLeft:
            spdlog::trace("Rear Left Wheel Velocity is currently: {0:f}", velocity);
            currentVelocity[2] = velocity;
            break;
        case rearRight:
            spdlog::trace("Rear Right Wheel Velocity is currently: {0:f}", velocity);
            currentVelocity[3] = velocity;
            if(invertRight) currentVelocity[3] *= -1;
            break;
    }
}

void Kinematics::calculateForwardKinematics(pose_t * currentMotion)
{
    spdlog::trace("Calculating Forward Kinematics");

    //If we just want to log data, we can use a null argument
    pose_t motionTemp;
    if(!currentMotion) currentMotion = &motionTemp;

    std::chrono::time_point<DEFAULT_CLOCK> now = DEFAULT_CLOCK::now();
    std::chrono::duration<float> kinematicCalculatorElapsedSec = now - lastForwardCalculation;

    currentMotion->linear.x = (currentVelocity[0] + currentVelocity[1] + currentVelocity[2] + currentVelocity[3]) * 
            (wheelRadius / 4.0) * RADIANS_PER_CIRCLE * kinematicCalculatorElapsedSec.count();
    currentMotion->linear.y = (currentVelocity[0] - currentVelocity[1] - currentVelocity[2] + currentVelocity[3]) * 
            (wheelRadius / 4.0) * RADIANS_PER_CIRCLE * kinematicCalculatorElapsedSec.count();
    currentMotion->linear.z = 0;

    currentMotion->angular.x = 0;
    currentMotion->angular.y = 0;
    currentMotion->angular.z = (currentVelocity[0] - currentVelocity[1] + currentVelocity[2] - currentVelocity[3]) *
            (wheelRadius / (4.0 * ((wheelBaseWidth / 2.0) + (wheelBaseLength / 2.0)))) *
            RADIANS_PER_CIRCLE * kinematicCalculatorElapsedSec.count();

    spdlog::trace("Forward Kinematic Results: Linear X: {0:f} Linear Y: {0:f} Angular Z: {0:f}",
            currentMotion->linear.x, currentMotion->linear.y, currentMotion->angular.z);

    writeOPCUAValue("forward.motion.x", currentMotion->linear.x);
    writeOPCUAValue("forward.motion.y", currentMotion->linear.y);
    writeOPCUAValue("forward.motion.z", currentMotion->angular.z);
    writeOPCUAValue("forward.velocities.frontleft", currentVelocity[0]);
    writeOPCUAValue("forward.velocities.frontright", currentVelocity[1]);
    writeOPCUAValue("forward.velocities.rearleft", currentVelocity[2]);
    writeOPCUAValue("forward.velocities.rearright", currentVelocity[3]);

    lastForwardCalculation = now;
}

void Kinematics::calculateInverseKinematics(pose_t requestedMotion)
{
    float reciprocalRadius = 1 / wheelRadius;
    double wheelSeperation = (wheelBaseWidth / 2) + (wheelBaseLength / 2);

    spdlog::trace("Calculating Inverse Kinematics");

    // Front Left
    commandedVelocity[0] = (reciprocalRadius * (requestedMotion.linear.x + requestedMotion.linear.y +
            wheelSeperation * requestedMotion.angular.z)) / RADIANS_PER_CIRCLE;
    // Front Right
    commandedVelocity[1] = (reciprocalRadius * (requestedMotion.linear.x - requestedMotion.linear.y -
            wheelSeperation * requestedMotion.angular.z)) / RADIANS_PER_CIRCLE;
    // Rear Left
    commandedVelocity[2] = (reciprocalRadius * (requestedMotion.linear.x - requestedMotion.linear.y +
            wheelSeperation * requestedMotion.angular.z)) / RADIANS_PER_CIRCLE;
    // Rear Right
    commandedVelocity[3] = (reciprocalRadius * (requestedMotion.linear.x + requestedMotion.linear.y -
            wheelSeperation * requestedMotion.angular.z)) / RADIANS_PER_CIRCLE;

    spdlog::trace("Inverse Kinematic Result: FL: {0:f} FR: {0:f} RL: {0:f} RR: {0:f}",
            commandedVelocity[0], commandedVelocity[1], commandedVelocity[2], commandedVelocity[3]);

    writeOPCUAValue("inverse.motion.x", requestedMotion.linear.x);
    writeOPCUAValue("inverse.motion.y", requestedMotion.linear.y);
    writeOPCUAValue("inverse.motion.z", requestedMotion.angular.z);
    writeOPCUAValue("inverse.velocities.frontleft", commandedVelocity[0]);
    writeOPCUAValue("inverse.velocities.frontright", commandedVelocity[1]);
    writeOPCUAValue("inverse.velocities.rearleft", commandedVelocity[2]);
    writeOPCUAValue("inverse.velocities.rearright", commandedVelocity[3]);

}

float Kinematics::getCommandedVelocity(wheel_t wheel)
{
    switch(wheel)
    {
        case frontLeft:
            return commandedVelocity[0];
        case frontRight:
            if(invertRight) return commandedVelocity[1] * -1;
            else return commandedVelocity[1];
        case rearLeft:
            return commandedVelocity[2];
        case rearRight:
            if(invertRight) return commandedVelocity[3] * -1;
            else return commandedVelocity[3];
    }
    return 0;
}

void Kinematics::writeOPCUAValue(std::string id_ext, float value)
{
    if(opcua == NULL) return;

    UA_StatusCode stat;
    UA_Variant variant;
    std::string node_id = nodeIdBase + "." + id_ext;
    UA_Variant_setScalar(&variant, &value, &UA_TYPES[UA_TYPES_FLOAT]);

    UA_NodeId nodeId = UA_NODEID_STRING(nodeNs, (char *) node_id.c_str());
    stat = opcua->writeValueToServer(nodeId, variant);

    if(stat != UA_STATUSCODE_GOOD)
        spdlog::trace("Unable to send kinematic value update: {0}", UA_StatusCode_name(stat));
}