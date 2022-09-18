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
    char mqttMessageString[10];
    char mqttTopicString[32];
    spdlog::debug("Processing ODrive Data");

    int32_t commandID = CONVERT_CAN_ID_TO_COMMAND_ID(frame.can_id);
    OdriveInterface * odrive = (OdriveInterface *)handle;

    spdlog::debug("ODrive ID: 0x{0:X} Command ID: 0x{1:X}", CONVERT_CAN_ID_TO_DEVICE_ID(frame.can_id), commandID);

    switch(commandID)
    {
        case ODRIVE_CAN_CMD_ID_HEARTBEAT:
            uint32_t newAxisError;
            axisState_t newAxisState;
            uint8_t newControllerStatus;

            memcpy(&newAxisError, &(frame.data[0]), sizeof(newAxisError));
            if(newAxisError != odrive->currentErrors.axis)
            {
                if(newAxisError == 0) spdlog::info("Axis 0x{0:X} Error changed from {1:d} to: {2:d}",
                        odrive->canDevId, odrive->currentErrors.axis, newAxisError);
                else spdlog::warn("Axis 0x{0:X} Error changed from {1:d} to: {2:d}",
                        odrive->canDevId, odrive->currentErrors.axis, newAxisError);

                odrive->currentErrors.axis = newAxisError;

                sprintf(mqttMessageString, "%d", newAxisError);
                sprintf(mqttTopicString, "odrive%d/error/axis", odrive->canDevId);
                odrive->sendMqttMessage(mqttTopicString, &mqttMessageString, strlen(mqttMessageString), 1, true);
            }

            memcpy(&newAxisState, &(frame.data[4]), sizeof(newAxisState));
            if(newAxisState != odrive->currentState)
            {
                spdlog::info("Axis 0x{0:X} State changed from {1:d} to: {2:d}",
                        odrive->canDevId, odrive->currentErrors.axis, newAxisError);

                odrive->currentState = newAxisState;
                
                sprintf(mqttMessageString, "%d", newAxisState);
                sprintf(mqttTopicString, "odrive%d/state", odrive->canDevId);
                odrive->sendMqttMessage(mqttTopicString, &mqttMessageString, strlen(mqttMessageString), 1, true);
            }

            memcpy(&newControllerStatus, &(frame.data[7]), sizeof(newControllerStatus));
            spdlog::trace("New Controller Status is 0x{0:X}", newControllerStatus);

            break;
        case ODRIVE_CAN_CMD_ID_GET_MOTOR_ERROR:
            uint64_t newMotorError;

            memcpy(&newMotorError, &(frame.data[0]), sizeof(newMotorError));
            if(newMotorError != odrive->currentErrors.motor)
            {
                if(newMotorError == 0) spdlog::info("Motor on axis 0x{0:X} Error changed from {1:d} to: {2:d}",
                        odrive->canDevId, odrive->currentErrors.motor, newMotorError);
                else spdlog::warn("Motor on axis 0x{0:X} Error changed from {1:d} to: {2:d}",
                        odrive->canDevId, odrive->currentErrors.motor, newMotorError);

                odrive->currentErrors.motor = newMotorError;

                sprintf(mqttMessageString, "%d", newMotorError);
                sprintf(mqttTopicString, "odrive%d/error/motor", odrive->canDevId);
                odrive->sendMqttMessage(mqttTopicString, &mqttMessageString, strlen(mqttMessageString), 1, true);
            }
            break;
        case ODRIVE_CAN_CMD_ID_GET_ENCODER_ERROR:
            uint32_t newEncoderError;

            memcpy(&newEncoderError, &(frame.data[0]), sizeof(newEncoderError));
            if(newEncoderError != odrive->currentErrors.encoder)
            {
                if(newEncoderError == 0) spdlog::info("Encoder Error on axis 0x{0:X} changed from {1:d} to: {2:d}",
                        odrive->canDevId, odrive->currentErrors.encoder, newEncoderError);
                else spdlog::warn("Encoder Error on axis 0x{0:X} changed from {1:d} to: {2:d}",
                        odrive->canDevId, odrive->currentErrors.encoder, newEncoderError);

                odrive->currentErrors.encoder = newEncoderError;

                sprintf(mqttMessageString, "%d", newEncoderError);
                sprintf(mqttTopicString, "odrive%d/error/encoder", odrive->canDevId);
                odrive->sendMqttMessage(mqttTopicString, &mqttMessageString, strlen(mqttMessageString), 1, true);
            }
            break;
        case ODRIVE_CAN_CMD_ID_GET_SENSORLESS_ERROR:
            uint32_t newSensorlessError;

            memcpy(&newSensorlessError, &(frame.data[0]), sizeof(newSensorlessError));
            if(newSensorlessError != odrive->currentErrors.sensorless)
            {
                if(newSensorlessError == 0) spdlog::info("Sensorless Error on axis 0x{0:X} changed from {1:d} to: {2:d}",
                        odrive->canDevId, odrive->currentErrors.sensorless, newSensorlessError);
                else spdlog::warn("Sensorless Error on axis 0x{0:X} changed from {1:d} to: {2:d}",
                        odrive->canDevId, odrive->currentErrors.sensorless, newSensorlessError);

                odrive->currentErrors.sensorless = newSensorlessError;

                sprintf(mqttMessageString, "%d", newSensorlessError);
                sprintf(mqttTopicString, "odrive%d/error/sensorless", odrive->canDevId);
                odrive->sendMqttMessage(mqttTopicString, &mqttMessageString, strlen(mqttMessageString), 1, true);
            }
            break;
        case ODRIVE_CAN_CMD_ID_GET_IQ:
            //Not implemented here
            break;
        default:
            spdlog::warn("Message command id unknown");
            break;
    }
}

void OdriveInterface::associateAxes(OdriveInterface * axis1, OdriveInterface * axis2)
{
    axis1->partnerAxis = axis2;
    axis2->partnerAxis = axis1;
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
    spdlog::info("Setting up MQTT for ODrive");

    mqttBackhaul = mqtt;
}


void OdriveInterface::eStopBoard()
{
    if(!checkIfConfigured("E-Stop Board")) return;

    struct can_frame frame;

    spdlog::warn("E-Stopping ODrive 0x{0:X}", canDevId);
    frame.can_id = CONVERT_DEVICE_AND_COMMAND_ID_TO_CAN_ID(canDevId, ODRIVE_CAN_CMD_ID_ESTOP);
    frame.can_dlc = 0;
    
    canDevice->sendFrame(frame);
}

void OdriveInterface::getMotorError()
{
    if(!checkIfConfigured("Get Motor Error")) return;

    struct can_frame frame;

    spdlog::debug("Requesting Motor Error from ODrive 0x{0:X}", canDevId);
    frame.can_id = CONVERT_DEVICE_AND_COMMAND_ID_TO_CAN_ID(canDevId, ODRIVE_CAN_CMD_ID_GET_MOTOR_ERROR);
    SET_CAN_RTR_BIT(frame.can_id);
    frame.can_dlc = 0;
    
    canDevice->sendFrame(frame);
}

void OdriveInterface::getEncoderError()
{
    if(!checkIfConfigured("Get Encoder Error")) return;

    struct can_frame frame;

    spdlog::debug("Requesting Encoder Error from ODrive 0x{0:X}", canDevId);
    frame.can_id = CONVERT_DEVICE_AND_COMMAND_ID_TO_CAN_ID(canDevId, ODRIVE_CAN_CMD_ID_GET_ENCODER_ERROR);
    SET_CAN_RTR_BIT(frame.can_id);
    frame.can_dlc = 0;
    
    canDevice->sendFrame(frame);
}

void OdriveInterface::getSensorlessError()
{
    if(!checkIfConfigured("Get Sensorless Error")) return;

    struct can_frame frame;

    spdlog::debug("Requesting Sensorless Error from ODrive 0x{0:X}", canDevId);
    frame.can_id = CONVERT_DEVICE_AND_COMMAND_ID_TO_CAN_ID(canDevId, ODRIVE_CAN_CMD_ID_GET_SENSORLESS_ERROR);
    SET_CAN_RTR_BIT(frame.can_id);
    frame.can_dlc = 0;
    
    canDevice->sendFrame(frame);
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

    struct can_frame frame;

    spdlog::debug("Requesting Encoder Estimates from ODrive 0x{0:X}", canDevId);
    frame.can_id = CONVERT_DEVICE_AND_COMMAND_ID_TO_CAN_ID(canDevId, ODRIVE_CAN_CMD_ID_GET_ENCODER_ESTIMATES);
    SET_CAN_RTR_BIT(frame.can_id);
    frame.can_dlc = 0;
    
    canDevice->sendFrame(frame);
}

void OdriveInterface::getEncoderCount()
{
    if(!checkIfConfigured("Get Encoder Count")) return;

    struct can_frame frame;

    spdlog::debug("Requesting Encoder Count from ODrive 0x{0:X}", canDevId);
    frame.can_id = CONVERT_DEVICE_AND_COMMAND_ID_TO_CAN_ID(canDevId, ODRIVE_CAN_CMD_ID_GET_ENCODER_COUNT);
    SET_CAN_RTR_BIT(frame.can_id);
    frame.can_dlc = 0;
    
    canDevice->sendFrame(frame);
}

void OdriveInterface::setControllerModes(controlMode_t controlMode, inputMode_t inputMode)
{
    if(!checkIfConfigured("Set Controller Modes")) return;

    struct can_frame frame;

    spdlog::debug("Requesting new controller mode {0:d} and input mode {1:d} from ODrive 0x{2:X}", controlMode, inputMode, canDevId);
    frame.can_id = CONVERT_DEVICE_AND_COMMAND_ID_TO_CAN_ID(canDevId, ODRIVE_CAN_CMD_ID_SET_CONTROLLER_MODES);
    frame.can_dlc = sizeof(controlMode) + sizeof(inputMode);
    memcpy(frame.data, &controlMode, sizeof(controlMode));
    memcpy(frame.data + 4, &inputMode, sizeof(inputMode));
    
    canDevice->sendFrame(frame);
}

void OdriveInterface::setInputPosition(float position, int16_t velocityFF, int16_t torqueFF)
{
    if(!checkIfConfigured("Set Input Position")) return;

    struct can_frame frame;

    spdlog::debug("Setting new input position {0:f}, velocity FF {1:d}, and torque FF {2:d} for ODrive 0x{3:X}",
            position, velocityFF, torqueFF, canDevId);
    frame.can_id = CONVERT_DEVICE_AND_COMMAND_ID_TO_CAN_ID(canDevId, ODRIVE_CAN_CMD_ID_SET_INPUT_POS);
    frame.can_dlc = sizeof(position) + sizeof(velocityFF) + sizeof(torqueFF);
    memcpy(frame.data, &position, sizeof(position));
    memcpy(frame.data + 4, &velocityFF, sizeof(velocityFF));
    memcpy(frame.data + 6, &torqueFF, sizeof(torqueFF));
    
    canDevice->sendFrame(frame);
}

void OdriveInterface::setInputVelocity(float velocity, float torqueFF)
{

}

void OdriveInterface::setInputTorque(float torque)
{

}

void OdriveInterface::setLimits(float velocityLimit, float currentLimit)
{

}

void OdriveInterface::startAnticogging()
{

}

void OdriveInterface::setTrapTrajVelocityLimit(float velLimit)
{

}

void OdriveInterface::setTrapTrajAccelLimits(float accelLimit, float decelLimit)
{

}

void OdriveInterface::setTrapTrajInertia(float inertia)
{

}

void OdriveInterface::getIQ()
{

}

void OdriveInterface::getSensorlessEstimates()
{

}

void OdriveInterface::rebootBoard()
{

}

void OdriveInterface::clearErrors()
{

}

void OdriveInterface::setLinearCount(int32_t linearCount)
{

}

void OdriveInterface::setPositionGain(float positionGain)
{

}

void OdriveInterface::setVelocityGains(float velocityGain, float integratorGain)
{

}

bool OdriveInterface::checkIfConfigured(std::string caller)
{
    if(configured) return true;

    spdlog::warn("Cannot process \"{0}\" request because ODrive 0x{1:X} is not configured", caller.c_str(), canDevId);
    return false;
}