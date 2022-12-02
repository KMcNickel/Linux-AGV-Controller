#ifndef BATTERY_MANAGER_INTERFACE_H_
#define BATTERY_MANAGER_INTERFACE_H_

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <linux/can.h>

#include "socketcan.h"
#include "alarm_manager.h"
#include "opc_ua_server.h"

#define LOW_BAT_WARN_THRESHOLD  25
#define LOW_BAT_ERROR_THRESHOLD 10

class BatteryManager
{
    private:
        SocketCAN::receiveCallback_t receiveCallback;
        SocketCAN * canDevice;
        int32_t canDevId;
        bool configured = false;
        AlarmManager * alarmManager = NULL;
        OPCUAServer * opcua = NULL;
        std::string nodeIdBase;
        uint16_t nodeNs;
        UA_NodeId lowBatAlarmId;
        UA_NodeId lowlowBatAlarmId;

        void writeOPCUAValueFloat(std::string id_ext, float value);
        void writeOPCUAValueByteArray(std::string id_ext, uint8_t * value, size_t len);
        void setup_OPCUA_Nodeset();

    public:
        static void receiveCAN(void * handle, struct can_frame frame);
        bool registerCallback();
        void configureDevice(SocketCAN * can, int32_t deviceId);
        void setupOPCUA(OPCUAServer * opcua, uint16_t ns, std::string nodeIdBase);
        void setupAlarmManager(AlarmManager * alarmMan);
        void rebootDevice();
        float batteryVoltage;
        float batterySoC;
};

#endif