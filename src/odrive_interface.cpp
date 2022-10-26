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
#include "include/global_defines.h"
#include "include/mqtt_transfer.h"
#include "include/odrive_interface.h"

void OdriveInterface::receiveCAN(void * handle, struct can_frame frame)
{
    char mqttMessageString[64];
    spdlog::debug("Processing ODrive CAN Data");

    int32_t commandID = CONVERT_CAN_ID_TO_COMMAND_ID(frame.can_id);
    OdriveInterface * odrive = (OdriveInterface *)handle;

    spdlog::debug("ODrive ID: 0x{0:X} Command ID: 0x{1:X}", CONVERT_CAN_ID_TO_DEVICE_ID(frame.can_id), commandID);

    switch(commandID)
    {
        case ODRIVE_CAN_CMD_ID_HEARTBEAT:
            uint32_t newAxisError;
            axisState_t newAxisState;
            uint8_t newControllerStatus;

            memcpy(&newAxisError, frame.data, sizeof(newAxisError));
            spdlog::debug("New Axis Error is 0x{0:X}", newAxisError);
            if(newAxisError != odrive->currentErrors.axis)
            {
                if(newAxisError == 0) spdlog::info("Axis 0x{0:X} Error changed from {1:d} to {2:d}",
                        odrive->canDevId, odrive->currentErrors.axis, newAxisError);
                else spdlog::warn("Axis 0x{0:X} Error changed from {1:d} to {2:d}",
                        odrive->canDevId, odrive->currentErrors.axis, newAxisError);

                odrive->currentErrors.axis = newAxisError;
            }
            sprintf(mqttMessageString, "{\"Error\":{\"Axis\":%d}}", odrive->currentErrors.axis);
            odrive->sendMqttMessage(odrive->mqttTopicString, &mqttMessageString, strlen(mqttMessageString),
                    MqttTransfer::QOS_0_AT_MOST_ONCE, false);

            memcpy(&newAxisState, frame.data + 4, sizeof(newAxisState));
            spdlog::debug("New Axis State is 0x{0:X}", newAxisState);
            if(newAxisState != odrive->currentState)
            {
                spdlog::info("Axis 0x{0:X} State changed from {1:d} to {2:d}",
                        odrive->canDevId, odrive->currentState, newAxisState);

                odrive->currentState = newAxisState;
            }
            sprintf(mqttMessageString, "{\"State\":%d}", odrive->currentState);
            odrive->sendMqttMessage(odrive->mqttTopicString, &mqttMessageString, strlen(mqttMessageString),
                    MqttTransfer::QOS_0_AT_MOST_ONCE, false);

            memcpy(&newControllerStatus, frame.data + 7, sizeof(newControllerStatus));
            spdlog::debug("New Controller Status is 0x{0:X}", newControllerStatus);
            sprintf(mqttMessageString, "{\"Status\":%d}", newControllerStatus);
            odrive->sendMqttMessage(odrive->mqttTopicString, &mqttMessageString, strlen(mqttMessageString),
                    MqttTransfer::QOS_0_AT_MOST_ONCE, false);

            break;
        case ODRIVE_CAN_CMD_ID_GET_MOTOR_ERROR:
            uint64_t newMotorError;

            memcpy(&newMotorError, frame.data, sizeof(newMotorError));
            if(newMotorError != odrive->currentErrors.motor)
            {
                if(newMotorError == 0) spdlog::info("Motor on axis 0x{0:X} Error changed from {1:d} to {2:d}",
                        odrive->canDevId, odrive->currentErrors.motor, newMotorError);
                else spdlog::warn("Motor on axis 0x{0:X} Error changed from {1:d} to {2:d}",
                        odrive->canDevId, odrive->currentErrors.motor, newMotorError);

                odrive->currentErrors.motor = newMotorError;
            }
            sprintf(mqttMessageString, "{\"Error\":{\"Motor\":%ld}}", odrive->currentErrors.motor);
            odrive->sendMqttMessage(odrive->mqttTopicString, &mqttMessageString, strlen(mqttMessageString),
                    MqttTransfer::QOS_0_AT_MOST_ONCE, true);
            break;
        case ODRIVE_CAN_CMD_ID_GET_ENCODER_ERROR:
            uint32_t newEncoderError;

            memcpy(&newEncoderError, frame.data, sizeof(newEncoderError));
            if(newEncoderError != odrive->currentErrors.encoder)
            {
                if(newEncoderError == 0) spdlog::info("Encoder Error on axis 0x{0:X} changed from {1:d} to {2:d}",
                        odrive->canDevId, odrive->currentErrors.encoder, newEncoderError);
                else spdlog::warn("Encoder Error on axis 0x{0:X} changed from {1:d} to {2:d}",
                        odrive->canDevId, odrive->currentErrors.encoder, newEncoderError);

                odrive->currentErrors.encoder = newEncoderError;
            }
            sprintf(mqttMessageString, "{\"Error\":{\"Encoder\":%d}}", odrive->currentErrors.encoder);
            odrive->sendMqttMessage(odrive->mqttTopicString, &mqttMessageString, strlen(mqttMessageString),
                    MqttTransfer::QOS_0_AT_MOST_ONCE, true);
            break;
        case ODRIVE_CAN_CMD_ID_GET_SENSORLESS_ERROR:
            uint32_t newSensorlessError;

            memcpy(&newSensorlessError, frame.data, sizeof(newSensorlessError));
            if(newSensorlessError != odrive->currentErrors.sensorless)
            {
                if(newSensorlessError == 0) spdlog::info("Sensorless Error on axis 0x{0:X} changed from {1:d} to {2:d}",
                        odrive->canDevId, odrive->currentErrors.sensorless, newSensorlessError);
                else spdlog::warn("Sensorless Error on axis 0x{0:X} changed from {1:d} to {2:d}",
                        odrive->canDevId, odrive->currentErrors.sensorless, newSensorlessError);

                odrive->currentErrors.sensorless = newSensorlessError;
            }
            sprintf(mqttMessageString, "{\"Error\":{\"Sensorless\":%d}}", odrive->currentErrors.sensorless);
            odrive->sendMqttMessage(odrive->mqttTopicString, &mqttMessageString, strlen(mqttMessageString),
                    MqttTransfer::QOS_1_AT_LEAST_ONCE, true);
            break;
        case ODRIVE_CAN_CMD_ID_GET_ENCODER_ESTIMATES:
            memcpy(&odrive->currentPositionEstimate, frame.data, sizeof(odrive->currentPositionEstimate));
            memcpy(&odrive->currentVelocityEstimate, frame.data + 4, sizeof(odrive->currentVelocityEstimate));

            sprintf(mqttMessageString, "{\"PositionEst\":%10.4f,\"VelocityEst\":%10.4f}",
                    odrive->currentPositionEstimate, odrive->currentVelocityEstimate);
                odrive->sendMqttMessage(odrive->mqttTopicString, &mqttMessageString, strlen(mqttMessageString),
                        MqttTransfer::QOS_0_AT_MOST_ONCE, true);
            break;
        case ODRIVE_CAN_CMD_ID_GET_ENCODER_COUNT:
            break;
        case ODRIVE_CAN_CMD_ID_GET_IQ:
            //Not implemented here
            break;
        case ODRIVE_CAN_CMD_ID_GET_SENSORLESS_ESTIMATES:
            break;
        default:
            spdlog::warn("Message command id unknown");
            break;
    }
}

bool OdriveInterface::registerCallback()
{
    if(!configured)
    {
        spdlog::error("Unable to register ODrive CAN Callback: Device must be configured first");
        return false;
    }
    receiveCallback.callback = receiveCAN;
    receiveCallback.id_mask = CAN_DEVICE_ID_MASK;
    receiveCallback.id_match = CONVERT_CAN_DEVICE_ID_TO_CAN_ID(canDevId);
    receiveCallback.handle = this;

    canDevice->addCallback(&receiveCallback);
    spdlog::debug("ODrive 0x{0:X} CAN Callback Registered", canDevId);
    return true;
}

void OdriveInterface::configureDevice(SocketCAN * can, int32_t deviceId)
{
    canDevice = can;
    canDevId = deviceId;
    configured = true;

    spdlog::debug("ODrive Device registered with Device ID: 0x{0:X}", canDevId);
}

void OdriveInterface::setupMqtt(MqttTransfer * mqtt)
{
    spdlog::info("Setting up MQTT for ODrive 0x{0:X}", canDevId);

    mqttBackhaul = mqtt;

    sprintf(mqttTopicString, "odrive%d", canDevId);
}

bool OdriveInterface::hasErrors()
{
    return (currentErrors.board | currentErrors.axis | currentErrors.controller |
            currentErrors.encoder | currentErrors.motor | currentErrors.sensorless);
}

bool OdriveInterface::isConfigured()
{
    return configured;
}

void OdriveInterface::eStop()
{
    if(!checkIfConfigured("E-Stop Board")) return;

    spdlog::warn("E-Stopping ODrive 0x{0:X}", canDevId);
    sendEmptyRequestToDevice(ODRIVE_CAN_CMD_ID_ESTOP);
}

void OdriveInterface::getMotorError()
{
    if(!checkIfConfigured("Get Motor Error")) return;

    spdlog::debug("Requesting Motor Error from ODrive 0x{0:X}", canDevId);
    sendEmptyRequestToDevice(ODRIVE_CAN_CMD_ID_GET_MOTOR_ERROR);
}

void OdriveInterface::getEncoderError()
{
    if(!checkIfConfigured("Get Encoder Error")) return;

    spdlog::debug("Requesting Encoder Error from ODrive 0x{0:X}", canDevId);
    sendEmptyRequestToDevice(ODRIVE_CAN_CMD_ID_GET_ENCODER_ERROR);
}

void OdriveInterface::getSensorlessError()
{
    if(!checkIfConfigured("Get Sensorless Error")) return;

    spdlog::debug("Requesting Sensorless Error from ODrive 0x{0:X}", canDevId);
    sendEmptyRequestToDevice(ODRIVE_CAN_CMD_ID_GET_SENSORLESS_ERROR);
}

void OdriveInterface::requestAxisStateChange(axisState_t requestedState)
{
    if(!checkIfConfigured("Request Axis State Change")) return;

    struct can_frame frame;

    spdlog::debug("Requesting new state {0:d} from ODrive 0x{1:X}", requestedState, canDevId);
    frame.can_id = CONVERT_DEVICE_AND_COMMAND_ID_TO_CAN_ID(canDevId, ODRIVE_CAN_CMD_ID_SET_AXIS_REQUESTED_STATE);
    frame.can_dlc = sizeof(requestedState);
    memcpy(frame.data, &requestedState, sizeof(requestedState));
    
    canDevice->sendFrame(frame);
}

void OdriveInterface::getEncoderEstimates()
{
    if(!checkIfConfigured("Get Encoder Estimates")) return;

    spdlog::debug("Requesting Encoder Estimates from ODrive 0x{0:X}", canDevId);
    sendEmptyRequestToDevice(ODRIVE_CAN_CMD_ID_GET_ENCODER_ESTIMATES);
}

void OdriveInterface::getEncoderCount()
{
    if(!checkIfConfigured("Get Encoder Count")) return;

    spdlog::debug("Requesting Encoder Count from ODrive 0x{0:X}", canDevId);
    sendEmptyRequestToDevice(ODRIVE_CAN_CMD_ID_GET_ENCODER_COUNT);
}

void OdriveInterface::setControllerModes(controlMode_t controlMode, inputMode_t inputMode)
{
    if(!checkIfConfigured("Set Controller Modes")) return;

    struct can_frame frame;

    spdlog::debug("Requesting new controller mode {0:d} and input mode {1:d} from ODrive 0x{2:X}", controlMode, inputMode, canDevId);
    frame.can_id = CONVERT_DEVICE_AND_COMMAND_ID_TO_CAN_ID(canDevId, ODRIVE_CAN_CMD_ID_SET_CONTROLLER_MODES);
    frame.can_dlc = 8;
    memcpy(frame.data, &controlMode, sizeof(controlMode));
    memcpy(frame.data + 4, &inputMode, sizeof(inputMode));
    
    canDevice->sendFrame(frame);
}

void OdriveInterface::setInputPosition(float position, int16_t velocityFF, int16_t torqueFF)
{
    char mqttMessageString[96];

    if(!checkIfConfigured("Set Input Position")) return;

    struct can_frame frame;

    spdlog::debug("Setting new input position {0:f}, velocity FF {1:d}, and torque FF {2:d} for ODrive 0x{3:X}",
            position, velocityFF, torqueFF, canDevId);
    frame.can_id = CONVERT_DEVICE_AND_COMMAND_ID_TO_CAN_ID(canDevId, ODRIVE_CAN_CMD_ID_SET_INPUT_POS);
    frame.can_dlc = 8;
    memcpy(frame.data, &position, sizeof(position));
    memcpy(frame.data + 4, &velocityFF, sizeof(velocityFF));
    memcpy(frame.data + 6, &torqueFF, sizeof(torqueFF));
    
    canDevice->sendFrame(frame);

    sprintf(mqttMessageString, "{\"PositionCmd\":%10.4f,\"VelocityFFCmd\":%10.4f,\"TorqueFFCmd\":%10.4f}",
            position, velocityFF, torqueFF);

    sendMqttMessage(mqttTopicString, &mqttMessageString, strlen(mqttMessageString),
                        MqttTransfer::QOS_0_AT_MOST_ONCE, true);
}

void OdriveInterface::setInputVelocity(float velocity, float torqueFF)
{
    char mqttMessageString[64];

    if(!checkIfConfigured("Set Input Velocity")) return;

    spdlog::debug("Setting new input velocity {0:f}, and torque FF {1:f} for ODrive 0x{2:X}",
            velocity, torqueFF, canDevId);
    sendTwoFloatsToDevice(ODRIVE_CAN_CMD_ID_SET_INPUT_VEL, velocity, torqueFF);

    sprintf(mqttMessageString, "{\"VelocityCmd\":%10.4f,\"TorqueFFCmd\":%10.4f}", velocity, torqueFF);

    sendMqttMessage(mqttTopicString, &mqttMessageString, strlen(mqttMessageString),
                        MqttTransfer::QOS_0_AT_MOST_ONCE, true);
}

void OdriveInterface::setInputTorque(float torque)
{
    char mqttMessageString[64];

    if(!checkIfConfigured("Set Input Torque")) return;

    spdlog::debug("Setting new input torque {0:f} for ODrive 0x{1:X}",
            torque, canDevId);
    sendFloatToDevice(ODRIVE_CAN_CMD_ID_SET_INPUT_TORQUE, torque);

    sprintf(mqttMessageString, "{\"TorqueCmd\":%10.4f}", torque);

    sendMqttMessage(mqttTopicString, &mqttMessageString, strlen(mqttMessageString),
                        MqttTransfer::QOS_0_AT_MOST_ONCE, true);
}

void OdriveInterface::setLimits(float velocityLimit, float currentLimit)
{
    if(!checkIfConfigured("Set Limits")) return;

    spdlog::debug("Setting new velocity limit {0:d}, and current limit {1:d} for ODrive 0x{2:X}",
            velocityLimit, currentLimit, canDevId);
    sendTwoFloatsToDevice(ODRIVE_CAN_CMD_ID_SET_LIMITS, velocityLimit, currentLimit);
}

void OdriveInterface::startAnticogging()
{
    if(!checkIfConfigured("Start Anticogging")) return;

    spdlog::debug("Starting anticogging for ODrive 0x{0:X}", canDevId);
    sendEmptyRequestToDevice(ODRIVE_CAN_CMD_ID_START_ANTICOGGING);
}

void OdriveInterface::setTrapTrajVelocityLimit(float velLimit)
{
    if(!checkIfConfigured("Set Trapezoidal Trajectory Velocity Limit")) return;

    spdlog::debug("Setting new trapezoidal trajectory velocity limit {0:d} for ODrive 0x{2:X}",
            velLimit, canDevId);
    sendFloatToDevice(ODRIVE_CAN_CMD_ID_SET_TRAJ_VEL_LIMIT, velLimit);
}

void OdriveInterface::setTrapTrajAccelLimits(float accelLimit, float decelLimit)
{
    if(!checkIfConfigured("Set Trapezoidal Trajectory Acceleration Limits")) return;

    spdlog::debug("Setting new trapezoidal trajectory acceleration limit {0:d}, and deceleration limit {1:d} for ODrive 0x{2:X}",
            accelLimit, decelLimit, canDevId);
    sendTwoFloatsToDevice(ODRIVE_CAN_CMD_ID_SET_TRAJ_ACCEL_LIMITS, accelLimit, decelLimit);
}

void OdriveInterface::setTrapTrajInertia(float inertia)
{
    if(!checkIfConfigured("Set Trapezoidal Trajectory Inertia")) return;

    spdlog::debug("Setting new trapezoidal trajectory inertia {0:d} for ODrive 0x{1:X}",
            inertia, canDevId);
    sendFloatToDevice(ODRIVE_CAN_CMD_ID_SET_TRAJ_INERTIA, inertia);
}

void OdriveInterface::getIQ()
{
    if(!checkIfConfigured("Get IQ")) return;

    spdlog::debug("Requesting IQ from ODrive 0x{0:X}", canDevId);
    sendEmptyRequestToDevice(ODRIVE_CAN_CMD_ID_GET_IQ);
}

void OdriveInterface::getSensorlessEstimates()
{
    if(!checkIfConfigured("Get Sensorless Estimates")) return;

    spdlog::debug("Requesting Sensorless Estimates from ODrive 0x{0:X}", canDevId);
    sendEmptyRequestToDevice(ODRIVE_CAN_CMD_ID_GET_SENSORLESS_ESTIMATES);
}

void OdriveInterface::rebootBoard()
{
    if(!checkIfConfigured("Reboot Board")) return;

    spdlog::debug("Rebooting ODrive 0x{0:X}", canDevId);
    sendEmptyRequestToDevice(ODRIVE_CAN_CMD_ID_REBOOT_ODRIVE);
}

void OdriveInterface::clearErrors()
{
    if(!checkIfConfigured("Clear Errors")) return;

    spdlog::debug("Clearing Errors on ODrive 0x{0:X}", canDevId);
    sendEmptyRequestToDevice(ODRIVE_CAN_CMD_ID_CLEAR_ERRORS);
}

void OdriveInterface::setLinearCount(int32_t linearCount)
{
    if(!checkIfConfigured("Set Linear Count")) return;

    struct can_frame frame;

    spdlog::debug("Setting linear count {0:d} for ODrive 0x{1:X}",
            linearCount, canDevId);
    frame.can_id = CONVERT_DEVICE_AND_COMMAND_ID_TO_CAN_ID(canDevId, ODRIVE_CAN_CMD_ID_SET_LINEAR_COUNT);
    frame.can_dlc = 4;
    memcpy(frame.data, &linearCount, sizeof(linearCount));
    
    canDevice->sendFrame(frame);
}

void OdriveInterface::setPositionGain(float positionGain)
{
    if(!checkIfConfigured("Set Position Gain")) return;

    spdlog::debug("Setting position gain {0:d} for ODrive 0x{1:X}",
            positionGain, canDevId);
    sendFloatToDevice(ODRIVE_CAN_CMD_ID_SET_POSITION_GAIN, positionGain);
}

void OdriveInterface::setVelocityGains(float velocityGain, float integratorGain)
{
    if(!checkIfConfigured("Set Velocity Gains")) return;

    spdlog::debug("Setting new velocity proportional gain {0:d} and integrator gain {1:d} for ODrive 0x{2:X}",
            velocityGain, integratorGain, canDevId);
    sendTwoFloatsToDevice(ODRIVE_CAN_CMD_ID_SET_VEL_GAINS, velocityGain, integratorGain);
}

bool OdriveInterface::checkIfConfigured(std::string caller)
{
    if(configured) return true;

    spdlog::warn("Cannot process \"{0}\" request because ODrive is not configured", caller.c_str());
    return false;
}

void OdriveInterface::sendFloatToDevice(int cmdID, float value)
{
    struct can_frame frame;

    frame.can_id = CONVERT_DEVICE_AND_COMMAND_ID_TO_CAN_ID(canDevId, cmdID);
    frame.can_dlc = 4;
    memcpy(frame.data, &value, sizeof(float));
    
    canDevice->sendFrame(frame);
}

void OdriveInterface::sendTwoFloatsToDevice(int cmdID, float valueA, float valueB)
{
    struct can_frame frame;

    frame.can_id = CONVERT_DEVICE_AND_COMMAND_ID_TO_CAN_ID(canDevId, cmdID);
    frame.can_dlc = 8;
    memcpy(frame.data, &valueA, sizeof(float));
    memcpy(frame.data + 4, &valueB, sizeof(float));
    
    canDevice->sendFrame(frame);
}

void OdriveInterface::sendEmptyRequestToDevice(int cmdID)
{
    struct can_frame frame;

    frame.can_id = CONVERT_DEVICE_AND_COMMAND_ID_TO_CAN_ID(canDevId, cmdID);
    SET_CAN_RTR_BIT(frame.can_id);
    frame.can_dlc = 0;
    
    canDevice->sendFrame(frame);
}