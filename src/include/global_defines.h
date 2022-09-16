#ifndef GLOBAL_DEFINES_H_
#define GLOBAL_DEFINES_H_

#define VERSION_MAJOR       0
#define VERSION_MINOR       1
#define VERSION_PATCH       0
#define VERSION_BUILD       4

#define GLOBAL_LOG_LEVEL spdlog::level::debug

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

#endif