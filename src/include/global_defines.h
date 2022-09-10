#ifndef GLOBAL_DEFINES_H_
#define GLOBAL_DEFINES_H_

#define VERSION_MAJOR       0
#define VERSION_MINOR       1
#define VERSION_REVISION    0
#define VERSION_BUILD       3

//Can ID's are as follows:
//11 bits total
//Upper 6 bits -> Device ID
//Lower 5 bits -> Command ID
#define CAN_DEVICE_ID_MASK 0x7E0
#define CONVERT_CAN_DEVICE_ID_TO_CAN_ID(dev)(dev << 5)
#define CONVERT_CAN_ID_TO_COMMAND_ID(id)(id & 0x1F)
#define CONVERT_CAN_ID_TO_DEVICE_ID(id)(id >> 5 & 0x3F)

#endif