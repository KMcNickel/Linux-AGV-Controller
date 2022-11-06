#include <stdio.h>
#include <mosquitto.h>
#include <stdlib.h>
#include <string>
#include <unistd.h>
#include <signal.h>
#include <time.h>
#include <sys/time.h>

#include "spdlog/spdlog.h"
#include "include/odrive_safe_velocity_manager.h"
#include "include/odrive_interface.h"
#include "include/mqtt_transfer.h"
#include "include/socketcan.h"

void OdriveSafeVelocityManager::configureSingleAxis(std::string name, SocketCAN * can, int32_t axisDeviceId)
{
    spdlog::info("Configuring ODrive Manager {0} with single axis 0x{1:X}", name, axisDeviceId);

    this->name = name;
    axisA.configureDevice(can, axisDeviceId);
    axisA.registerCallback();
    feedWatchdog();
    configured = SingleAxis;
    spdlog::debug("ODrive Manager {0} Configured", name);
}

void OdriveSafeVelocityManager::configureDualAxis(std::string name, SocketCAN * can, int32_t axisADeviceId, int32_t axisBDeviceId)
{
    spdlog::info("Configuring ODrive Manager {0} with dual axes 0x{1:X} and 0x{2:X}", name, axisADeviceId, axisBDeviceId);

    this->name = name;
    axisA.configureDevice(can, axisADeviceId);
    axisA.registerCallback();
    axisB.configureDevice(can, axisBDeviceId);
    axisB.registerCallback();
    feedWatchdog();
    configured = DualAxis;

    spdlog::debug("ODrive Manager {0} Configured", name);
}

void OdriveSafeVelocityManager::setupMqtt(MqttTransfer * mqtt)
{

    if(!checkIfConfigured("Setup MQTT")) return;

    logStartOfAction("Setting Up MQTT for");
    
    axisA.setupMqtt(mqtt);
    if(configured == DualAxis) axisB.setupMqtt(mqtt);
}

bool OdriveSafeVelocityManager::isConfigured()
{
    return configured != Unconfigured;
}

bool OdriveSafeVelocityManager::hasErrors()
{
    if(!checkIfConfigured("Has Errors")) return false;
    if(incomingWatchdogExpired) return true;
    if(configured == SingleAxis) return axisA.hasErrors();
    if(configured == DualAxis) return (axisA.hasErrors() || axisB.hasErrors());

    return false;
}

void OdriveSafeVelocityManager::requestErrors(axis_t axis)
{
    if(!checkIfConfigured("Request Errors")) return;

    bool useAxisA = (axis == AxisA || axis == AxisAll);
    bool useAxisB = (configured == DualAxis && (axis == AxisB || axis == AxisAll));

    if(useAxisA)
    {
        spdlog::debug("Requesting Errors from ODrive Manager {0} axis A", name);
        axisA.getMotorError();
        axisA.getEncoderError();
        axisA.getSensorlessError();
    }
    else if(useAxisB)
    {
        spdlog::debug("Requesting Errors from ODrive Manager {0} axis B", name);
        axisB.getMotorError();
        axisB.getEncoderError();
        axisB.getSensorlessError();
    }

    lastErrorRequest = DEFAULT_CLOCK::now();
}

void OdriveSafeVelocityManager::setVelocity(axis_t axis, float velocity, float torqueFF)
{
    if(!checkIfConfigured("Set Velocity")) return;
    if(checkIfErrorsExist("Set Velocity")) return;

    if(axis == AxisB && !checkIfDualAxis("Set Velocity")) return;

    feedWatchdog();

    if(axis == AxisA)
    {
        spdlog::debug("Setting Axis A Velocity");
        axisA.setInputVelocity(velocity, torqueFF);
    }
    if(axis == AxisB)
    {
        spdlog::debug("Setting Axis B Velocity");
        axisB.setInputVelocity(velocity, torqueFF);
    }
}

float OdriveSafeVelocityManager::getVelocity(axis_t axis)
{
    if(!checkIfConfigured("Get Velocity")) return 0;

    if(axis == AxisB && !checkIfDualAxis("Get Velocity")) return 0;

    if(axis == AxisA)
        return axisA.currentVelocityEstimate;
    if(axis == AxisB)
        return axisB.currentVelocityEstimate;

    return 0;
}

void OdriveSafeVelocityManager::rebootBoard()
{
    if(!checkIfConfigured("Reboot Board")) return;

    logStartOfAction("Rebooting");
    
    axisA.rebootBoard();

    spdlog::info("Reboot Triggered");
}

void OdriveSafeVelocityManager::eStopBoard()
{
    if(configured != Unconfigured)
        if(axisA.isEStopped() && axisB.isEStopped())
            return;

    if(!checkIfConfigured("Emergency Stop Board")) return;

    logStartOfAction("Emergency Stopping");
    
    axisA.eStop();
    if(configured == DualAxis) axisB.eStop();

    spdlog::warn("ODrive Manager {0} was Emergency Stopped", name);
}

void OdriveSafeVelocityManager::stopBoard()
{
    if(!checkIfConfigured("Stop Board")) return;

    logStartOfAction("Stopping");

    axisA.setInputVelocity(0, 0);
    if(configured = DualAxis) axisB.setInputVelocity(0, 0);

    axisA.requestAxisStateChange(OdriveInterface::axisState_t::Idle);
    if(configured = DualAxis) axisB.requestAxisStateChange(OdriveInterface::axisState_t::Idle);

    spdlog::info("Stopped Board");
}

void OdriveSafeVelocityManager::startBoard()
{
    if(!checkIfConfigured("Start Board")) return;

    logStartOfAction("Starting");

    axisA.clearErrors();
    if(configured = DualAxis) axisB.clearErrors();

    axisA.setInputVelocity(0, 0);
    if(configured = DualAxis) axisB.setInputVelocity(0, 0);

    axisA.requestAxisStateChange(OdriveInterface::axisState_t::ClosedLoopControl);
    if(configured = DualAxis) axisB.requestAxisStateChange(OdriveInterface::axisState_t::ClosedLoopControl);

    spdlog::info("Started Board");
}

void OdriveSafeVelocityManager::stopAxis(axis_t axis)
{
    if(!checkIfConfigured("Stop Axis")) return;
    if(axis == AxisB && !checkIfDualAxis("Stop Axis")) return;
    
    if(axis == AxisA)
    {
        spdlog::info("Stopping ODrive Manager {0} axis A...", name);
        axisA.setInputVelocity(0, 0);
        axisA.requestAxisStateChange(OdriveInterface::axisState_t::Idle);
        spdlog::info("Stopped Axis");
    }
    else if(axis == AxisB)
    {
        spdlog::info("Stopping ODrive Manager {0} axis A...", name);
        axisB.setInputVelocity(0, 0);
        axisB.requestAxisStateChange(OdriveInterface::axisState_t::Idle);
        spdlog::info("Stopped Axis");
    }
}

void OdriveSafeVelocityManager::startAxis(axis_t axis)
{
    if(!checkIfConfigured("Start Axis")) return;
    if(checkIfErrorsExist("Start Axis")) return;

    if(axis == AxisB && !checkIfDualAxis("Start Axis")) return;
    
    if(axis == AxisA)
    {
        spdlog::info("Starting ODrive Manager {0} axis A...", name);
        axisA.clearErrors();
        axisA.setInputVelocity(0, 0);
        axisA.requestAxisStateChange(OdriveInterface::axisState_t::ClosedLoopControl);
        spdlog::info("Started Axis");
    }
    else if(axis == AxisB)
    {
        spdlog::info("Starting ODrive Manager {0} axis B...", name);
        axisB.clearErrors();
        axisB.setInputVelocity(0, 0);
        axisB.requestAxisStateChange(OdriveInterface::axisState_t::ClosedLoopControl);
        spdlog::info("Started Axis");
    }
}

void OdriveSafeVelocityManager::feedWatchdog()
{
    spdlog::trace("Watchdog feed on Odrive Manager {0}", name);
    lastWatchdogFeed = DEFAULT_CLOCK::now();
    incomingWatchdogExpired = false;
}

bool OdriveSafeVelocityManager::checkIfConfigured(std::string caller)
{
    if(configured != Unconfigured) return true;

    spdlog::warn("Cannot process \"{0}\" request because ODrive Manager {0} is not configured", caller.c_str(), name);
    return false;
}

bool OdriveSafeVelocityManager::checkIfDualAxis(std::string caller)
{
    if(configured == DualAxis) return true;

    spdlog::warn("Cannot process \"{0}\" request because ODrive Manager {1} is not configured in dual axis mode", caller.c_str(), name);
    return false;
}

void OdriveSafeVelocityManager::logStartOfAction(std::string actionName)
{
    if(configured == Unconfigured) return;
    
    spdlog::info("{0} ODrive Manager {1}", actionName, name);

}

void OdriveSafeVelocityManager::checkTimers()
{
    if(configured == Unconfigured) return;

    spdlog::trace("Checking timers for Odrive Manager {0}", name);
    std::chrono::time_point<DEFAULT_CLOCK> now = DEFAULT_CLOCK::now();
    std::chrono::milliseconds watchdogElapsedMs = std::chrono::duration_cast<std::chrono::milliseconds>(now - lastWatchdogFeed);
    std::chrono::milliseconds errorRequestElapsedMs = std::chrono::duration_cast<std::chrono::milliseconds>(now - lastErrorRequest);

    if(watchdogElapsedMs > incomingWatchdogTimeout && incomingWatchdogExpired == false)
    {
        //Only log message and trigger E-Stop if we haven't done so somewhere else for another reason
        if(!(axisA.isEStopped() && (configured == SingleAxis || axisB.isEStopped())))
        {
            spdlog::warn("Incoming Watchdog was not fed after {0:d} ms. ODrive Manager {1} will be Emergency Stopped.",
                    watchdogElapsedMs.count(), name);
            eStopBoard();
        }
        incomingWatchdogExpired = true;
    }

    if(errorRequestElapsedMs > errorRequestInterval)
    {
        spdlog::trace("Error request interval for ODrive Manager {0} has elapsed after {1:d} ms",
                name, errorRequestElapsedMs.count());
        requestErrors(AxisAll);
        lastErrorRequest = now;
    }
}

bool OdriveSafeVelocityManager::checkIfErrorsExist(std::string caller)
{
    if(!checkIfConfigured("Check if errors exist")) return true;

    if(incomingWatchdogExpired)
    {
        spdlog::warn("Unable to {0} while the incoming watchdog for ODrive Manager {1} is expired", caller, name);
        return true;
    }

    if(hasErrors())
    {
        spdlog::warn("Unable to {0} while ODrive errors for ODrive Manager {1} exist", caller, name);
        return true;
    }

    return false;
}