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

void ControllerWrangler::gracefulEnd()
{
    for (int i = 0; i < 4; i++)
         odrive[i].eStopBoard();

    can.killSocket();       //MUST come after ALL devices on the bus are stopped
    mqtt.shutdownMQTT();
}

void ControllerWrangler::configureBatteryManager()
{
    spdlog::info("Configuring Battery Manager...");

    batteryManager.configureDevice(&can, CAN_ID_BATTERY_MANAGER);
    batteryManager.registerCallback();
    batteryManager.rebootDevice();
    batteryManager.setupMqtt(&mqtt);
    
    spdlog::info("Battery Manager Configured");
}

void ControllerWrangler::configureODrives()
{
    spdlog::info("Configuring ODrives...");

    odrive[0].configureDualAxis("Front", &can, CAN_ID_FRONT_LEFT_AXIS, CAN_ID_FRONT_RIGHT_AXIS);
    odrive[0].setupMqtt(&mqtt);
    odrive[1].configureDualAxis("Rear", &can, CAN_ID_REAR_LEFT_AXIS, CAN_ID_REAR_RIGHT_AXIS);
    odrive[1].setupMqtt(&mqtt);

    odrive[0].startBoard();
    odrive[1].startBoard();

    odrive[0].setVelocity(OdriveSafeVelocityManager::axis_t::AxisA, 1, 0);

    spdlog::info("ODrives Configured");
}

void ControllerWrangler::configureCANBus()
{
    spdlog::info("Configuring CAN Bus...");

    can.configureSocketCAN("can0");

    configureBatteryManager();
    configureODrives();

    spdlog::info("CAN Bus Configured");
}

void ControllerWrangler::configureMQTT()
{
    spdlog::info("Configuring MQTT...");
    mqtt.setupMQTT("AGV01", "192.168.2.163", 1883, DEVICE_NAME);
    mqtt.connectBroker();
    spdlog::info("MQTT configured");
}

void ControllerWrangler::configureKinematics()
{
    spdlog::info("Configuring Pendant...");
    kinematics.startup(MECANUM_WHEEL_RADIUS, MECANUM_WHEEL_BASE_WIDTH, MECANUM_WHEEL_BASE_LENGTH, MECANUM_WHEEL_RIGHT_INVERTED);
    kinematics.setupMqtt(&mqtt);
    spdlog::info("Pendant configured");
}

void ControllerWrangler::configurePendant()
{
    spdlog::info("Configuring Pendant...");
    pendant.startup();
    pendant.setupMqtt(&mqtt);
    spdlog::info("Pendant configured");
}

void ControllerWrangler::startup()
{
    spdlog::info("Controller Wrangler Starting Up...");

    configureMQTT();
    configureCANBus();
    configureKinematics();
    configurePendant();

    spdlog::info("Controller Wrangler Start Up Complete");
}

void ControllerWrangler::loop()
{
    PendantManager::gamepad_t pendantState;
    Kinematics::pose_t requestedMotion;

    spdlog::trace("Controller Wrangler loop iteration");
    can.receiveData();
    odrive[0].checkTimers();
    odrive[1].checkTimers();
    pendant.maintenanceLoop();

    pendantState = pendant.getCurrentState();
    requestedMotion.linear.x = (pendantState.leftJoystick.y / 3277) * -1;
    requestedMotion.linear.y = pendantState.leftJoystick.x / 3277;
    requestedMotion.angular.z = pendantState.rightJoystick.x / 3277;

    kinematics.calculateInverseKinematics(requestedMotion);

    odrive[0].setVelocity(OdriveSafeVelocityManager::AxisA, kinematics.getCommandedVelocity(Kinematics::frontLeft), 0);
    odrive[0].setVelocity(OdriveSafeVelocityManager::AxisB, kinematics.getCommandedVelocity(Kinematics::frontRight), 0);
    odrive[1].setVelocity(OdriveSafeVelocityManager::AxisA, kinematics.getCommandedVelocity(Kinematics::rearLeft), 0);
    odrive[1].setVelocity(OdriveSafeVelocityManager::AxisB, kinematics.getCommandedVelocity(Kinematics::rearRight), 0);
}
