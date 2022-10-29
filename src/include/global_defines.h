#ifndef GLOBAL_DEFINES_H_
#define GLOBAL_DEFINES_H_

#include <linux/can.h>

#define GLOBAL_LOG_LEVEL "info"
#define DEFAULT_CLOCK std::chrono::steady_clock

#define MQTT_DEVICE_ID "AGV0"
#define MQTT_BROKER_IP "192.168.2.59"
#define MQTT_BROKER_PORT 1883

#define DEVICE_NAME "agv0"
#define PENDANT_INPUT "/dev/input/by-id/usb-8BitDo_8BitDo_Pro_2_000000000003-event-joystick"

//All measurements are in meters
#define MECANUM_WHEEL_RADIUS            0.04064
#define MECANUM_WHEEL_BASE_LENGTH       0.181356
#define MECANUM_WHEEL_BASE_WIDTH        0.27178
#define MECANUM_WHEEL_RIGHT_INVERTED    true

//CAN Bus ID's
#define CAN_ID_FRONT_LEFT_AXIS  0x0
#define CAN_ID_FRONT_RIGHT_AXIS 0x1
#define CAN_ID_REAR_LEFT_AXIS   0x2
#define CAN_ID_REAR_RIGHT_AXIS  0x3
#define CAN_ID_BATTERY_MANAGER  0x4
#define CAN_ID_DWM1001          0x5

//Can ID's are as follows:
//11 bits total
//Upper 6 bits -> Device ID
//Lower 5 bits -> Command ID
#define CAN_DEVICE_ID_MASK 0x7E0
#define CONVERT_DEVICE_AND_COMMAND_ID_TO_CAN_ID(dev, cmd)((dev << 5) | cmd)
#define CONVERT_CAN_DEVICE_ID_TO_CAN_ID(dev)(dev << 5)
#define CONVERT_CAN_ID_TO_COMMAND_ID(id)(id & 0x1F)
#define CONVERT_CAN_ID_TO_DEVICE_ID(id)(id >> 5 & 0x3F)
#define SET_CAN_RTR_BIT(id)(id | CAN_RTR_FLAG)

#define ALARM_ID_TYPE_BATTERY 0x00010000

#endif