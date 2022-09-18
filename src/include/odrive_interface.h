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
#include "mqtt_transfer.h"

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

class OdriveInterface
{
    public:
        enum axisState_t
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

        enum controlMode_t
        {
            voltage = 0,
            torque = 1,
            velocity = 2,
            position = 3
        };

        enum inputMode_t
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

        OdriveInterface * partnerAxis = NULL;
        axisState_t currentState;
        errors_t currentErrors;
        float currentPosition;
        float currentVelocity;
        float lastCommandedVelocity;

        static void receiveCAN(void * handle, struct can_frame frame);
        static void associateAxes(OdriveInterface * axis1, OdriveInterface * axis2);
        bool registerCallback();
        void configureDevice(SocketCAN * can, int32_t deviceId);
        void setupMqtt(MqttTransfer * mqtt);

        void eStopBoard();
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
        MqttTransfer * mqttBackhaul = NULL;
        void sendMqttMessage(std::string topic, void *data, size_t length, int qos, bool retain)
        {
            if(mqttBackhaul == NULL) return;
            mqttBackhaul->sendMessage(topic, data, length, qos, retain);
        }
};

#endif