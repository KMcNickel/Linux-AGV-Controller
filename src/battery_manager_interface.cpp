#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <linux/can.h>

#include "include/socketcan.h"
#include "include/battery_manager_interface.h"
#include "spdlog/spdlog.h"
#include "include/global_defines.h"
#include "include/opc_ua_server.h"

#define CAN_COMMAND_ID_RESET_DEVICE     0x0
#define CAN_COMMAND_ID_VERSION_NUMBER   0x1
#define CAN_COMMAND_ID_STATE_OF_CHARGE  0x2
#define CAN_COMMAND_ID_BATTERY_VOLTAGE  0x3

void BatteryManager::receiveCAN(void * handle, struct can_frame frame)
{
    spdlog::debug("Processing Battery Data");

    int32_t commandID = CONVERT_CAN_ID_TO_COMMAND_ID(frame.can_id);
    BatteryManager * batMan = (BatteryManager *)handle;
    uint8_t version[4];

    spdlog::debug("Battery Device ID: 0x{0:X} Command ID: 0x{1:X}", CONVERT_CAN_ID_TO_DEVICE_ID(frame.can_id), commandID);

    switch(commandID)
    {
        case CAN_COMMAND_ID_VERSION_NUMBER:
            version[0] = frame.data[3];
            version[1] = frame.data[2];
            version[2] = frame.data[1];
            version[3] = frame.data[0];
            batMan->writeOPCUAValueByteArray("softwareversion", version, 4);
            spdlog::info("Battery manager is version: {0:d}.{1:d}.{2:d} build: {3:d}",
                    version[0], version[1], version[2], version[3]);
            break;
        case CAN_COMMAND_ID_STATE_OF_CHARGE:
            memcpy(&(batMan->batterySoC), &(frame.data[1]), sizeof(float));
            batMan->writeOPCUAValueFloat("soc", batMan->batterySoC);
            spdlog::trace("Battery State of Charge: {0:3.0f}%", batMan->batterySoC);

            if(batMan->alarmManager && batMan->batterySoC < LOW_BAT_WARN_THRESHOLD)
                batMan->alarmManager->throwAlarm(LOW_BAT_WARN_ID);
            if(batMan->alarmManager && batMan->batterySoC < LOW_BAT_ERROR_THRESHOLD)
                batMan->alarmManager->throwAlarm(LOW_BAT_ERROR_ID);
            break;
        case CAN_COMMAND_ID_BATTERY_VOLTAGE:
            memcpy(&(batMan->batteryVoltage), &(frame.data[1]), sizeof(float));
            batMan->writeOPCUAValueFloat("voltage", batMan->batteryVoltage);
            spdlog::trace("Battery Voltage: {0:3.1f}V", batMan->batteryVoltage);
            break;
    }
}

void BatteryManager::rebootDevice()
{
    can_frame frame;

    frame.can_id = CONVERT_DEVICE_AND_COMMAND_ID_TO_CAN_ID(canDevId, CAN_COMMAND_ID_RESET_DEVICE);
    frame.can_dlc = 0;

    spdlog::debug("Sending reboot command to Battery Manager with ID: 0x{0:X}", canDevId);
    canDevice->sendFrame(frame);
}

void BatteryManager::setupAlarmManager(AlarmManager * alarmMan)
{
    alarmManager = alarmMan;
}

void BatteryManager::configureDevice(SocketCAN * can, int32_t deviceId)
{
    canDevice = can;
    canDevId = deviceId;
    configured = true;

    spdlog::debug("Battery Manager Device registered with Device ID: 0x{0:X}", canDevId);
}

void BatteryManager::setupOPCUA(OPCUAServer * opcua, uint16_t ns, std::string nodeIdBase)
{
    spdlog::debug("Setting up OPC UA for Battery Manager with node base: {0} and namespace {1:d}", nodeIdBase, ns);
    this->opcua = opcua;
    nodeNs = ns;
    this->nodeIdBase = nodeIdBase;
}

bool BatteryManager::registerCallback()
{
    if(!configured)
    {
        spdlog::error("Unable to register Battery Manager CAN Callback: Device must be configured first");
        return false;
    }
    receiveCallback.callback = receiveCAN;
    receiveCallback.id_mask = CAN_DEVICE_ID_MASK;
    receiveCallback.id_match = CONVERT_CAN_DEVICE_ID_TO_CAN_ID(canDevId);
    receiveCallback.handle = this;

    canDevice->addCallback(&receiveCallback);
    spdlog::debug("Battery Manager CAN Callback Registered");
    return true;
}

void BatteryManager::writeOPCUAValueFloat(std::string id_ext, float value)
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

void BatteryManager::writeOPCUAValueByteArray(std::string id_ext, uint8_t * value, size_t len)
{
    if(opcua == NULL) return;
    
    UA_StatusCode stat;
    UA_Variant variant;
    std::string node_id = nodeIdBase + "." + id_ext;
    UA_Variant_setArray(&variant, value, len, &UA_TYPES[UA_TYPES_BYTE]);

    UA_NodeId nodeId = UA_NODEID_STRING(nodeNs, (char *) node_id.c_str());
    stat = opcua->writeValueToServer(nodeId, variant);

    if(stat != UA_STATUSCODE_GOOD)
        spdlog::trace("Unable to send kinematic value update: {0}", UA_StatusCode_name(stat));
}
