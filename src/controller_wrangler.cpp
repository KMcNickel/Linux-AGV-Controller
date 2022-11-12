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
#include "include/battery_manager_interface.h"
#include "include/global_defines.h"
#include "include/mqtt_transfer.h"
#include "include/odrive_safe_velocity_manager.h"
#include "include/controller_wrangler.h"
#include "include/alarm_manager.h"
#include "include/node_ids.h"

void ControllerWrangler::gracefulEnd()
{
    odriveFront.eStopBoard();
    odriveRear.eStopBoard();

    can.killSocket();       //MUST come after ALL devices on the bus are stopped
    //mqtt.shutdownMQTT();
    opcUaServer.stopServer();
}

void ControllerWrangler::configureBatteryManager()
{
    spdlog::info("Configuring Battery Manager");

    batteryManager.configureDevice(&can, CAN_ID_BATTERY_MANAGER);
    batteryManager.registerCallback();
    batteryManager.rebootDevice();
    batteryManager.setupMqtt(&mqtt);
    batteryManager.setupAlarmManager(&alarmManager);
    
    spdlog::debug("Battery Manager Configured");
}

void ControllerWrangler::configureODrives()
{
    spdlog::info("Configuring ODrives");

    odriveFront.configureDualAxis("Front", &can, CAN_ID_FRONT_LEFT_AXIS, CAN_ID_FRONT_RIGHT_AXIS);
    odriveFront.setupMqtt(&mqtt);
    odriveRear.configureDualAxis("Rear", &can, CAN_ID_REAR_LEFT_AXIS, CAN_ID_REAR_RIGHT_AXIS);
    odriveRear.setupMqtt(&mqtt);

    odriveFront.startBoard();
    odriveRear.startBoard();

    spdlog::debug("ODrives Configured");
}

void ControllerWrangler::configureCANBus()
{
    spdlog::info("Configuring CAN Bus");

    can.configureSocketCAN("can0");

    configureBatteryManager();
    configureODrives();

    spdlog::debug("CAN Bus Configured");
}

void ControllerWrangler::configureMQTT()
{
    spdlog::info("Configuring MQTT");

    mqtt.setupMQTT(MQTT_DEVICE_ID, MQTT_BROKER_IP, MQTT_BROKER_PORT, DEVICE_NAME);
    mqtt.connectBroker();

    spdlog::debug("MQTT configured");
}

void ControllerWrangler::configureOPCUA()
{
    spdlog::info("Starting OPC UA Server");
    opcUaServer.startServer();
    spdlog::debug("OPC UA Server Started");
}

void ControllerWrangler::configureKinematics()
{
    Kinematics::nodeIds_t fwdNodeIds, invNodeIds;
    fwdNodeIds.motion.x = OPCUA_NODE_ID_KINEMATICS_FORWARD_MOTION_X;
    fwdNodeIds.motion.y = OPCUA_NODE_ID_KINEMATICS_FORWARD_MOTION_Y;
    fwdNodeIds.motion.z = OPCUA_NODE_ID_KINEMATICS_FORWARD_MOTION_Z;
    fwdNodeIds.velocities.frontLeft = OPCUA_NODE_ID_KINEMATICS_FORWARD_VELOCITY_FL;
    fwdNodeIds.velocities.frontRight = OPCUA_NODE_ID_KINEMATICS_FORWARD_VELOCITY_FR;
    fwdNodeIds.velocities.RearLeft = OPCUA_NODE_ID_KINEMATICS_FORWARD_VELOCITY_RL;
    fwdNodeIds.velocities.rearRight = OPCUA_NODE_ID_KINEMATICS_FORWARD_VELOCITY_RR;
    invNodeIds.motion.x = OPCUA_NODE_ID_KINEMATICS_INVERSE_MOTION_X;
    invNodeIds.motion.y = OPCUA_NODE_ID_KINEMATICS_INVERSE_MOTION_Y;
    invNodeIds.motion.z = OPCUA_NODE_ID_KINEMATICS_INVERSE_MOTION_Z;
    invNodeIds.velocities.frontLeft = OPCUA_NODE_ID_KINEMATICS_INVERSE_VELOCITY_FL;
    invNodeIds.velocities.frontRight = OPCUA_NODE_ID_KINEMATICS_INVERSE_VELOCITY_FR;
    invNodeIds.velocities.RearLeft = OPCUA_NODE_ID_KINEMATICS_INVERSE_VELOCITY_RL;
    invNodeIds.velocities.rearRight = OPCUA_NODE_ID_KINEMATICS_INVERSE_VELOCITY_RR;
    spdlog::info("Configuring Kinematics");

    kinematics.startup(MECANUM_WHEEL_RADIUS, MECANUM_WHEEL_BASE_WIDTH, MECANUM_WHEEL_BASE_LENGTH, MECANUM_WHEEL_RIGHT_INVERTED);
    kinematics.setupOPCUA(&opcUaServer, OPCUA_NODE_NAMESPACE_MAIN, fwdNodeIds, invNodeIds);

    spdlog::debug("Kinematics configured");
}

void ControllerWrangler::configurePendant()
{
    spdlog::info("Configuring Pendant");

    pendant.startup();
    pendant.setupMqtt(&mqtt);

    spdlog::debug("Pendant configured");
}

void ControllerWrangler::configureAlarms()
{
    spdlog::info("Registering Alarms");

    alarmManager.initializeAlarmList();
    alarmManager.setupMqtt(&mqtt);
    alarmManager.setCallback(std::bind(&ControllerWrangler::newAlarmsThrown, this));

    spdlog::debug("Alarms registered");
}

int ControllerWrangler::scalePendantJoystickValues(int raw, int dividend, int deadZone, bool invert)
{
    if(raw < deadZone && raw > (deadZone * -1)) return 0;

    if(invert) raw *= -1;

    return (raw - deadZone) / dividend;
}

void ControllerWrangler::updateMotorVelocities()
{
    PendantManager::gamepad_t pendantState;
    Kinematics::pose_t requestedMotion;
    if(odriveFront.hasErrors() || odriveRear.hasErrors()) return;


    switch(motorControlMode)
    {
        case Idle:
            odriveFront.setVelocity(OdriveSafeVelocityManager::AxisA, 0, 0);
            odriveFront.setVelocity(OdriveSafeVelocityManager::AxisB, 0, 0);
            odriveRear.setVelocity(OdriveSafeVelocityManager::AxisA, 0, 0);
            odriveRear.setVelocity(OdriveSafeVelocityManager::AxisB, 0, 0);
            break;
        case Manual:
            pendantState = pendant.getCurrentState();
            requestedMotion.linear.x = scalePendantJoystickValues(pendantState.leftJoystick.y,
                    pendantJoystickLinearDividend, pendantJoystickDeadZone, true);
            requestedMotion.linear.y = scalePendantJoystickValues(pendantState.rightJoystick.x,
                    pendantJoystickLinearDividend, pendantJoystickDeadZone, false);
            requestedMotion.angular.z = scalePendantJoystickValues(pendantState.leftJoystick.x,
                    pendantJoystickAngularDividend, pendantJoystickDeadZone, false);
            
            if(requestedMotion.linear.x < 0) requestedMotion.angular.z *= -1;    //Fix to match ackerman-style steering


            requestedMotion.linear.x = (pendantJoystickFilterAlpha * requestedMotion.linear.x) +
                    ((1 - pendantJoystickFilterAlpha) * lastPendantCommand.linear.x);
            requestedMotion.linear.y = (pendantJoystickFilterAlpha * requestedMotion.linear.y) +
                    ((1 - pendantJoystickFilterAlpha) * lastPendantCommand.linear.y);
            requestedMotion.angular.z = (pendantJoystickFilterAlpha * requestedMotion.angular.z) +
                    ((1 - pendantJoystickFilterAlpha) * lastPendantCommand.angular.z);

            kinematics.calculateInverseKinematics(requestedMotion);

            odriveFront.setVelocity(OdriveSafeVelocityManager::AxisA, kinematics.getCommandedVelocity(Kinematics::frontLeft), 0);
            odriveFront.setVelocity(OdriveSafeVelocityManager::AxisB, kinematics.getCommandedVelocity(Kinematics::frontRight), 0);
            odriveRear.setVelocity(OdriveSafeVelocityManager::AxisA, kinematics.getCommandedVelocity(Kinematics::rearLeft), 0);
            odriveRear.setVelocity(OdriveSafeVelocityManager::AxisB, kinematics.getCommandedVelocity(Kinematics::rearRight), 0);

            kinematics.updateCurrentVelocity(Kinematics::frontLeft, odriveFront.getVelocity(OdriveSafeVelocityManager::AxisA));
            kinematics.updateCurrentVelocity(Kinematics::frontRight, odriveFront.getVelocity(OdriveSafeVelocityManager::AxisB));
            kinematics.updateCurrentVelocity(Kinematics::rearLeft, odriveFront.getVelocity(OdriveSafeVelocityManager::AxisA));
            kinematics.updateCurrentVelocity(Kinematics::rearRight, odriveFront.getVelocity(OdriveSafeVelocityManager::AxisB));
            kinematics.calculateForwardKinematics(NULL);

            lastPendantCommand = requestedMotion;
            break;
        case Automatic:
            //Not implemented
            motorControlMode = Manual;
            break;
        }
    
}

void ControllerWrangler::newAlarmsThrown()
{
    odriveFront.eStopBoard();
    odriveRear.eStopBoard();
}

void ControllerWrangler::startup()
{
    spdlog::info("Controller Wrangler Starting Up");

    motorControlMode = Idle;

    configureMQTT();
    configureOPCUA();
    configureAlarms();
    configureCANBus();
    configureKinematics();
    configurePendant();

    motorControlMode = Manual;

    spdlog::info("Controller Wrangler Is Now Running");

    spdlog::debug("Controller Wrangler Start Up Complete");
}

void ControllerWrangler::loop()
{
    spdlog::trace("Controller Wrangler loop iteration");
    can.receiveData();
    odriveFront.checkTimers();
    odriveRear.checkTimers();
    pendant.maintenanceLoop();
    opcUaServer.checkServer();

    if(alarmManager.alarmsAreActive())
    {
        odriveFront.eStopBoard();
        odriveRear.eStopBoard();
    }

    std::chrono::time_point<DEFAULT_CLOCK> now = DEFAULT_CLOCK::now();
    std::chrono::milliseconds motorUpdateElapsedMs = std::chrono::duration_cast<std::chrono::milliseconds>(now - lastMotorUpdate);

    if(motorUpdateElapsedMs > motorUpdateInterval)
    {
        updateMotorVelocities();

        lastMotorUpdate = now;
    }
}
