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

#define RADIANS_PER_CIRCLE 6.28319

void Kinematics::startup(float length, float width, float radius, float invertRightWheels)
{
    wheelBaseLength = length;
    wheelBaseWidth = width;
    wheelRadius = radius;
    invertRight = invertRightWheels;
}

void Kinematics::setupMqtt(MqttTransfer * mqtt)
{
    this->mqtt = mqtt;
}

void Kinematics::updateCurrentVelocity(wheel_t wheel, float velocity)
{
    switch(wheel)
    {
        case frontLeft:
            currentVelocity[0] = velocity;
            break;
        case frontRight:
            currentVelocity[1] = velocity;
            if(invertRight) currentVelocity[1] *= -1;
            break;
        case rearLeft:
            currentVelocity[2] = velocity;
            break;
        case rearRight:
            currentVelocity[3] = velocity;
            if(invertRight) currentVelocity[3] *= -1;
            break;
    }
}

void Kinematics::calculateForwardKinematics(pose_t * currentMotion)
{
    std::chrono::time_point<DEFAULT_CLOCK> now = DEFAULT_CLOCK::now();
    std::chrono::duration<float> kinematicCalculatorElapsedSec =
            std::chrono::duration_cast<std::chrono::duration<float>>(now - lastForwardCalculation);

    currentMotion->linear.x = (currentVelocity[0] + currentVelocity[1] + currentVelocity[2] + currentVelocity[3]) * 
            (wheelRadius / 4.0) * RADIANS_PER_CIRCLE * kinematicCalculatorElapsedSec.count();
    currentMotion->linear.y = (-currentVelocity[0] + currentVelocity[1] + currentVelocity[2] - currentVelocity[3]) * 
            (wheelRadius / 4.0) * RADIANS_PER_CIRCLE * kinematicCalculatorElapsedSec.count();
    currentMotion->linear.z = 0;

    currentMotion->angular.x = 0;
    currentMotion->angular.y = 0;
    currentMotion->angular.z = (-currentVelocity[0] + currentVelocity[1] - currentVelocity[2] + currentVelocity[3]) *
            (wheelRadius / (4.0 * ((wheelBaseWidth / 2.0) + (wheelBaseLength / 2.0)))) *
            RADIANS_PER_CIRCLE * kinematicCalculatorElapsedSec.count();
}

void Kinematics::calculateInverseKinematics(pose_t requestedMotion)
{
    float reciprocalRadius = 1 / wheelRadius;
    double wheelSeperation = (wheelBaseWidth / 2) + (wheelBaseLength / 2);

    // Front Left
    commandedVelocity[0] = (reciprocalRadius * (requestedMotion.linear.x - requestedMotion.linear.y -
            wheelSeperation * requestedMotion.angular.z)) / RADIANS_PER_CIRCLE;
    // Front Right
    commandedVelocity[1] = (reciprocalRadius * (requestedMotion.linear.x + requestedMotion.linear.y +
            wheelSeperation * requestedMotion.angular.z)) / RADIANS_PER_CIRCLE;
    if(invertRight) commandedVelocity[1] *= -1;
    // Rear Left
    commandedVelocity[2] = (reciprocalRadius * (requestedMotion.linear.x + requestedMotion.linear.y -
            wheelSeperation * requestedMotion.angular.z)) / RADIANS_PER_CIRCLE;
    // Rear Right
    commandedVelocity[3] = (reciprocalRadius * (requestedMotion.linear.x - requestedMotion.linear.y +
            wheelSeperation * requestedMotion.angular.z)) / RADIANS_PER_CIRCLE;
    if(invertRight) commandedVelocity[3] *= -1;
}

float Kinematics::getCommandedVelocity(wheel_t wheel)
{
    switch(wheel)
    {
        case frontLeft:
            return commandedVelocity[0];
        case frontRight:
            return commandedVelocity[1];
        case rearLeft:
            return commandedVelocity[2];
        case rearRight:
            return commandedVelocity[3];
    }
    return 0;
}