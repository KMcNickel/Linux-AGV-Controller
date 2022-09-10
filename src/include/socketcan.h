#ifndef SOCKETCAN_H_
#define SOCKETCAN_H_

#include <stdint.h>
#include <string>

int32_t configureSocketCAN(std::string iface);

int32_t killSocketCAN();

int32_t sendFrame(struct can_frame * frame);

int32_t receiveData();

#endif