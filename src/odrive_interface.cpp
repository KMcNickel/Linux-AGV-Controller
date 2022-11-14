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
#include "include/odrive_interface.h"
#include "include/opc_ua_server.h"

void OdriveInterface::receiveCAN(void * handle, struct can_frame frame)
{
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
            spdlog::trace("New Axis Error is 0x{0:X}", newAxisError);
            if(newAxisError != odrive->currentErrors.axis)
            {
                if(newAxisError == 0) spdlog::debug("Axis 0x{0:X} Error changed from {1:d} to {2:d}",
                        odrive->canDevId, odrive->currentErrors.axis, newAxisError);
                else spdlog::debug("Axis 0x{0:X} Error changed from {1:d} to {2:d}",
                        odrive->canDevId, odrive->currentErrors.axis, newAxisError);

                odrive->currentErrors.axis = newAxisError;
            }

            odrive->writeOPCUAValueUInt32("error.axis", newAxisError);

            memcpy(&newAxisState, frame.data + 4, sizeof(newAxisState));
            spdlog::trace("New Axis State is 0x{0:X}", newAxisState);
            if(newAxisState != odrive->currentState)
            {
                spdlog::debug("Axis 0x{0:X} State changed from {1:d} to {2:d}",
                        odrive->canDevId, odrive->currentState, newAxisState);

                odrive->currentState = newAxisState;
            }
            
            odrive->writeOPCUAValueByte("axisstate", newAxisState);

            memcpy(&newControllerStatus, frame.data + 7, sizeof(newControllerStatus));
            spdlog::trace("New Controller Status is 0x{0:X}", newControllerStatus);
            
            odrive->writeOPCUAValueByte("controllerstatus", newControllerStatus);

            break;
        case ODRIVE_CAN_CMD_ID_GET_MOTOR_ERROR:
            uint64_t newMotorError;

            memcpy(&newMotorError, frame.data, sizeof(newMotorError));
            if(newMotorError != odrive->currentErrors.motor)
            {
                if(newMotorError == 0) spdlog::debug("Motor on axis 0x{0:X} Error changed from {1:d} to {2:d}",
                        odrive->canDevId, odrive->currentErrors.motor, newMotorError);
                else spdlog::debug("Motor on axis 0x{0:X} Error changed from {1:d} to {2:d}",
                        odrive->canDevId, odrive->currentErrors.motor, newMotorError);

                odrive->currentErrors.motor = newMotorError;
            }
            
            odrive->writeOPCUAValueUInt64("error.motor", newMotorError);
            break;
        case ODRIVE_CAN_CMD_ID_GET_ENCODER_ERROR:
            uint32_t newEncoderError;

            memcpy(&newEncoderError, frame.data, sizeof(newEncoderError));
            if(newEncoderError != odrive->currentErrors.encoder)
            {
                if(newEncoderError == 0) spdlog::debug("Encoder Error on axis 0x{0:X} changed from {1:d} to {2:d}",
                        odrive->canDevId, odrive->currentErrors.encoder, newEncoderError);
                else spdlog::debug("Encoder Error on axis 0x{0:X} changed from {1:d} to {2:d}",
                        odrive->canDevId, odrive->currentErrors.encoder, newEncoderError);

                odrive->currentErrors.encoder = newEncoderError;
            }
            
            odrive->writeOPCUAValueUInt32("error.encoder", newEncoderError);
            break;
        case ODRIVE_CAN_CMD_ID_GET_SENSORLESS_ERROR:
            uint32_t newSensorlessError;

            memcpy(&newSensorlessError, frame.data, sizeof(newSensorlessError));
            if(newSensorlessError != odrive->currentErrors.sensorless)
            {
                if(newSensorlessError == 0) spdlog::debug("Sensorless Error on axis 0x{0:X} changed from {1:d} to {2:d}",
                        odrive->canDevId, odrive->currentErrors.sensorless, newSensorlessError);
                else spdlog::debug("Sensorless Error on axis 0x{0:X} changed from {1:d} to {2:d}",
                        odrive->canDevId, odrive->currentErrors.sensorless, newSensorlessError);

                odrive->currentErrors.sensorless = newSensorlessError;
            }
            
            odrive->writeOPCUAValueUInt32("error.sensorless", newSensorlessError);
            break;
        case ODRIVE_CAN_CMD_ID_GET_ENCODER_ESTIMATES:
            memcpy(&odrive->currentPositionEstimate, frame.data, sizeof(odrive->currentPositionEstimate));
            memcpy(&odrive->currentVelocityEstimate, frame.data + 4, sizeof(odrive->currentVelocityEstimate));
            
            odrive->writeOPCUAValueFloat("encoderestimates.position", odrive->currentPositionEstimate);
            odrive->writeOPCUAValueFloat("encoderestimates.velocity", odrive->currentVelocityEstimate);
            break;
        case ODRIVE_CAN_CMD_ID_GET_ENCODER_COUNT:
            break;
        case ODRIVE_CAN_CMD_ID_GET_IQ:
            //Not implemented here
            break;
        case ODRIVE_CAN_CMD_ID_GET_SENSORLESS_ESTIMATES:
            break;
        default:
            spdlog::info("Message command id unknown");
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

void OdriveInterface::setupOPCUA(OPCUAServer * opcua, uint16_t ns, std::string nodeIdBase)
{
    spdlog::debug("Setting up OPC UA for ODrive with node base: {0} and namespace {1:d}", nodeIdBase, ns);
    this->opcua = opcua;
    nodeNs = ns;
    this->nodeIdBase = nodeIdBase;
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

    spdlog::debug("E-Stopping ODrive 0x{0:X}", canDevId);
    sendEmptyRequestToDevice(ODRIVE_CAN_CMD_ID_ESTOP);
}

bool OdriveInterface::isEStopped()
{
    return currentErrors.axis == ODRIVE_AXIS_ERROR_ESTOP_REQUESTED;
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
    std::string mqttMessageString;
    std::string mqttTopicString;

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
}

void OdriveInterface::setInputVelocity(float velocity, float torqueFF)
{
    std::string mqttMessageString;
    std::string mqttTopicString;

    if(!checkIfConfigured("Set Input Velocity")) return;

    spdlog::debug("Setting new input velocity {0:f}, and torque FF {1:f} for ODrive 0x{2:X}",
            velocity, torqueFF, canDevId);
    sendTwoFloatsToDevice(ODRIVE_CAN_CMD_ID_SET_INPUT_VEL, velocity, torqueFF);
}

void OdriveInterface::setInputTorque(float torque)
{
    std::string mqttMessageString;
    std::string mqttTopicString;

    if(!checkIfConfigured("Set Input Torque")) return;

    spdlog::debug("Setting new input torque {0:f} for ODrive 0x{1:X}",
            torque, canDevId);
    sendFloatToDevice(ODRIVE_CAN_CMD_ID_SET_INPUT_TORQUE, torque);
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
        
void OdriveInterface::writeOPCUAValueFloat(std::string id_ext, float value)
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

void OdriveInterface::writeOPCUAValueByte(std::string id_ext, uint8_t value)
{
    if(opcua == NULL) return;
    
    UA_StatusCode stat;
    UA_Variant variant;
    std::string node_id = nodeIdBase + "." + id_ext;
    UA_Variant_setScalar(&variant, &value, &UA_TYPES[UA_TYPES_BYTE]);

    UA_NodeId nodeId = UA_NODEID_STRING(nodeNs, (char *) node_id.c_str());
    stat = opcua->writeValueToServer(nodeId, variant);

    if(stat != UA_STATUSCODE_GOOD)
        spdlog::trace("Unable to send kinematic value update: {0}", UA_StatusCode_name(stat));
}

void OdriveInterface::writeOPCUAValueUInt32(std::string id_ext, uint32_t value)
{
    if(opcua == NULL) return;
    
    UA_StatusCode stat;
    UA_Variant variant;
    std::string node_id = nodeIdBase + "." + id_ext;
    UA_Variant_setScalar(&variant, &value, &UA_TYPES[UA_TYPES_UINT32]);

    UA_NodeId nodeId = UA_NODEID_STRING(nodeNs, (char *) node_id.c_str());
    stat = opcua->writeValueToServer(nodeId, variant);

    if(stat != UA_STATUSCODE_GOOD)
        spdlog::trace("Unable to send kinematic value update: {0}", UA_StatusCode_name(stat));
}

void OdriveInterface::writeOPCUAValueUInt64(std::string id_ext, uint64_t value)
{
    if(opcua == NULL) return;
    
    UA_StatusCode stat;
    UA_Variant variant;
    std::string node_id = nodeIdBase + "." + id_ext;
    UA_Variant_setScalar(&variant, &value, &UA_TYPES[UA_TYPES_UINT64]);

    UA_NodeId nodeId = UA_NODEID_STRING(nodeNs, (char *) node_id.c_str());
    stat = opcua->writeValueToServer(nodeId, variant);

    if(stat != UA_STATUSCODE_GOOD)
        spdlog::trace("Unable to send kinematic value update: {0}", UA_StatusCode_name(stat));
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
    frame.can_id = SET_CAN_RTR_BIT(frame.can_id);
    frame.can_dlc = 0;
    
    canDevice->sendFrame(frame);
}