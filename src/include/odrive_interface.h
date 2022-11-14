#ifndef ODRIVE_INTERFACE_H_
#define ODRIVE_INTERFACE_H_

#include <stdio.h>
#include <stdbool.h>
#include <stdint.h>
#include <string.h>
#include <csignal>
#include <iostream>
#include <mosquitto.h>

#include <linux/can.h>

#include "spdlog/spdlog.h"
#include "socketcan.h"
#include "global_defines.h"
#include "opc_ua_server.h"

#define ODRIVE_CAN_CMD_ID_HEARTBEAT                 0x1
#define ODRIVE_CAN_CMD_ID_ESTOP                     0x2
#define ODRIVE_CAN_CMD_ID_GET_MOTOR_ERROR           0x3
#define ODRIVE_CAN_CMD_ID_GET_ENCODER_ERROR         0x4
#define ODRIVE_CAN_CMD_ID_GET_SENSORLESS_ERROR      0x5
#define ODRIVE_CAN_CMD_ID_SET_AXIS_NODE_ID          0x6
#define ODRIVE_CAN_CMD_ID_SET_AXIS_REQUESTED_STATE  0x7
#define ODRIVE_CAN_CMD_ID_SET_AXIS_STARTUP_CONFIG   0x8
#define ODRIVE_CAN_CMD_ID_GET_ENCODER_ESTIMATES     0x9
#define ODRIVE_CAN_CMD_ID_GET_ENCODER_COUNT         0xA
#define ODRIVE_CAN_CMD_ID_SET_CONTROLLER_MODES      0xB
#define ODRIVE_CAN_CMD_ID_SET_INPUT_POS             0xC
#define ODRIVE_CAN_CMD_ID_SET_INPUT_VEL             0xD
#define ODRIVE_CAN_CMD_ID_SET_INPUT_TORQUE          0xE
#define ODRIVE_CAN_CMD_ID_SET_LIMITS                0xF
#define ODRIVE_CAN_CMD_ID_START_ANTICOGGING         0x10
#define ODRIVE_CAN_CMD_ID_SET_TRAJ_VEL_LIMIT        0x11
#define ODRIVE_CAN_CMD_ID_SET_TRAJ_ACCEL_LIMITS     0x12
#define ODRIVE_CAN_CMD_ID_SET_TRAJ_INERTIA          0x13
#define ODRIVE_CAN_CMD_ID_GET_IQ                    0x14
#define ODRIVE_CAN_CMD_ID_GET_SENSORLESS_ESTIMATES  0x15
#define ODRIVE_CAN_CMD_ID_REBOOT_ODRIVE             0x16
#define ODRIVE_CAN_CMD_ID_GET_VBUS_VOLTAGE          0x17
#define ODRIVE_CAN_CMD_ID_CLEAR_ERRORS              0x18
#define ODRIVE_CAN_CMD_ID_SET_LINEAR_COUNT          0x19
#define ODRIVE_CAN_CMD_ID_SET_POSITION_GAIN         0x1A
#define ODRIVE_CAN_CMD_ID_SET_VEL_GAINS             0x1B

#define ODRIVE_AXIS_ERROR_INVALID_STATE             0x1
#define ODRIVE_AXIS_ERROR_WATCHDOG_TIMER_EXPIRED    0x800
#define ODRIVE_AXIS_ERROR_MIN_ENDSTOP_PRESSED       0x1000
#define ODRIVE_AXIS_ERROR_MAX_ENDSTOP_PRESSED       0x2000
#define ODRIVE_AXIS_ERROR_ESTOP_REQUESTED           0x4000
#define ODRIVE_AXIS_ERROR_HOMING_WITHOUT_ENDSTOP    0x20000
#define ODRIVE_AXIS_ERROR_OVER_TEMP                 0x40000
#define ODRIVE_AXIS_ERROR_UNKNOWN_POSITION          0x80000

class OdriveInterface
{
    public:
        enum axisState_t : uint8_t
        {
            Undefined = 0x0,
            Idle = 0x01,
            StartupSequence = 0x02,
            FullCalibrationSequence = 0x03,
            MotorCalibration = 0x04,
            //There is no state 5. Because reasons...
            EncoderIndexSearch = 0x06,
            EncoderOffsetCalibration = 0x07,
            ClosedLoopControl = 0x08,
            LockinSpin = 0x09,
            EncoderDirFind = 0x0A,
            Homing = 0x0B,
            EncoderHallPolarityCalibration = 0x0C,
            EncoderHallPhaseCalibration = 0x0D
        };

        enum controlMode_t : uint32_t
        {
            voltage = 0,
            torque = 1,
            velocity = 2,
            position = 3
        };

        enum inputMode_t : uint32_t
        {
            inactive = 0,
            passthrough = 1,
            velocity_ramp = 2,
            position_filter = 3,
            mix_channels = 4,   //Not implemented by ODrive
            trapezoidal_trajectory = 5,
            torque_ramp = 6,
            mirror = 7,
            tuning = 8
        };

        struct errors_t
        {
            uint8_t board;
            uint32_t axis;
            uint64_t motor;
            uint8_t controller;
            uint16_t encoder;
            uint32_t sensorless;
        };

        axisState_t currentState;
        errors_t currentErrors;
        float currentPositionEstimate;
        float currentVelocityEstimate;

        static void receiveCAN(void * handle, struct can_frame frame);
        bool registerCallback();
        void configureDevice(SocketCAN * can, int32_t deviceId);
        void setupOPCUA(OPCUAServer * opcua, uint16_t ns, std::string nodeIdBase);
        bool hasErrors();
        bool isConfigured();

        void eStop();
        bool isEStopped();
        void getMotorError();
        void getEncoderError();
        void getSensorlessError();
        //void setAxisNodeID(uint32_t nodeID);
        void requestAxisStateChange(axisState_t requestedState);
        //void setAxisStartupConfig();  //Not implemented in ODrive
        void getEncoderEstimates();
        void getEncoderCount();
        void setControllerModes(controlMode_t controlMode, inputMode_t inputMode);
        void setInputPosition(float position, int16_t velocityFF, int16_t torqueFF);
        void setInputVelocity(float velocity, float torqueFF);
        void setInputTorque(float torque);
        void setLimits(float velocityLimit, float currentLimit);
        void startAnticogging();
        void setTrapTrajVelocityLimit(float velLimit);
        void setTrapTrajAccelLimits(float accelLimit, float decelLimit);
        void setTrapTrajInertia(float inertia);
        void getIQ();
        void getSensorlessEstimates();
        void rebootBoard();
        void clearErrors();
        void setLinearCount(int32_t linearCount);
        void setPositionGain(float positionGain);
        void setVelocityGains(float velocityGain, float integratorGain);


    private:
        SocketCAN::receiveCallback_t receiveCallback;
        SocketCAN * canDevice;
        int32_t canDevId;
        bool configured = false;
        bool checkIfConfigured(std::string caller);
        OPCUAServer * opcua = NULL;
        std::string nodeIdBase;
        uint16_t nodeNs;

        void writeOPCUAValueFloat(std::string id_ext, float value);
        void writeOPCUAValueByte(std::string id_ext, uint8_t value);
        void writeOPCUAValueUInt32(std::string id_ext, uint32_t value);
        void writeOPCUAValueUInt64(std::string id_ext, uint64_t value);
        void sendFloatToDevice(int cmdID, float value);
        void sendTwoFloatsToDevice(int cmdID, float valueA, float valueB);
        void sendEmptyRequestToDevice(int cmdID);
};

#endif