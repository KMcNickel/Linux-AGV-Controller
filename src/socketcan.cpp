#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <iostream>
#include <memory>
#include <cstring>
#include <cerrno>
#include <thread>
#include <poll.h>

#include "spdlog/spdlog.h"

#include <net/if.h>
#include <sys/ioctl.h>
#include <sys/socket.h>

#include <linux/can.h>
#include <linux/can/raw.h>

#include "include/socketcan.h"

#define MAX_DLC_LENGTH 8
#define SOCKET_CLOSED_PROGRAMATICALLY -10
#define CAN_ID_LARGER_THAN_29_BIT_MASK 0xE0000000
#define CAN_ID_LARGER_THAN_11_BIT_MASK 0xFFFFF800
#define SOCKET_POLL_TIMEOUT 0       //in milliseconds. 0 returns immediately


int32_t SocketCAN::configureSocketCAN(std::string iface)
{
    spdlog::info("Configuring CAN Socket");

    if ((socketID = socket(PF_CAN, SOCK_RAW, CAN_RAW)) < 0)
    {
        spdlog::error("Socket Error: Unable to create socket: {0:d}", socketID);
        return -1;
    }

    strcpy(ifr.ifr_name, iface.c_str());
    
    if(ioctl(socketID, SIOCGIFINDEX, &ifr) < 0)
    {
        spdlog::error("Socket Error: Unable to find interface: {0} - Errno: {1}", iface.c_str(), std::strerror(errno));
        return -1;
    }

    if(!(ifr.ifr_flags & IFF_UP))
        spdlog::warn("Selected interface '{0}' is not UP", iface.c_str());

    memset(&addr, 0, sizeof(addr));
    addr.can_family = AF_CAN;
    addr.can_ifindex = ifr.ifr_ifindex;

    if(bind(socketID, (struct sockaddr *)&addr, sizeof(addr)) < 0)
    {
        spdlog::error("Socket Error: Unable to bind to socket: {0}", std::strerror(errno));
        return -1;
    }

    pollDesc.fd = socketID;
    pollDesc.events = POLLIN;

    spdlog::info("Configuration complete");
    
    return 0;
}

int32_t SocketCAN::killSocket()
{
    spdlog::info("Killing CAN Socket");
    
    if(socketID != SOCKET_CLOSED_PROGRAMATICALLY && close(socketID) < 0)
    {
        spdlog::error("Socket Error: Unable to close socket: {0}", std::strerror(errno));
        return -1;
    }
    socketID = SOCKET_CLOSED_PROGRAMATICALLY;

    spdlog::info("CAN socket killed");
    
    return 0;
}

int32_t SocketCAN::sendFrame(struct can_frame frame)
{
    int err = 0;

    spdlog::trace("Preparing to send CAN data");

    if(frame.can_dlc > MAX_DLC_LENGTH)
    {
        spdlog::error("Message was sent with an invalid DLC: {0:d} - ID: {1:X}", 
                    frame.can_dlc, frame.can_id);
        err = -1;
    }

    /*if((incomingData.is_extended_id && (incomingData.can_id & CAN_ID_LARGER_THAN_29_BIT_MASK))
            || (!incomingData.is_extended_id && (incomingData.can_id & CAN_ID_LARGER_THAN_11_BIT_MASK)))
    {
        spdlog::warn("Message was sent with an invalid ID: {0:d}", incomingData.can_id);
        err += -2;
    }*/
    
    if(err != 0)
    {
        spdlog::error("Message will not be sent");
        return err;
    }

    spdlog::trace("Sending:\n\tID: 0x{0:X}\n\tLength: {1:d}\n\tData: 0x{2:X} 0x{3:X} 0x{4:X} 0x{5:X} 0x{6:X} 0x{7:X} 0x{8:X} 0x{9:X}",
            frame.can_id, frame.can_dlc, frame.data[0], frame.data[1], frame.data[2],
            frame.data[3], frame.data[4], frame.data[5], frame.data[6], frame.data[7]);
        
    if((err = write(socketID, &frame, sizeof(struct can_frame))) != sizeof(struct can_frame))
    {
        if(err < 0)
            spdlog::error("Socket Error: Unable to write data: {0}", std::strerror(errno));
        else
            spdlog::error("Socket Error: Could only write: {0:d} bytes", err);

        return err;
    }

    spdlog::trace("Frame sent successfully");
    return 0;
}

int32_t SocketCAN::receiveData()
{
    struct can_frame frame;
    int event;

    spdlog::trace("Checking for CAN data");

    event = poll(&pollDesc, 1, SOCKET_POLL_TIMEOUT);

    if(event < 0 && errno != EINTR) //EINTR = Function interrupted (like if we Ctrl + C)
    {
        spdlog::error("Socket Error: Unable to poll socket: {0}", std::strerror(errno));
        return event;
    }
    if(event > 0)
    {
        if(read(socketID, &frame, sizeof(struct can_frame)) < 0)
        {
            spdlog::error("Socket Error: Unable to read data: {0}", std::strerror(errno));
            return -1;
        }

        spdlog::trace("Received:\n\tID: 0x{0:X}\n\tLength: {1:d}\n\tData: 0x{2:X} 0x{3:X} 0x{4:X} 0x{5:X} 0x{6:X} 0x{7:X} 0x{8:X} 0x{9:X}",
                frame.can_id, frame.can_dlc, frame.data[0], frame.data[1], frame.data[2],
                frame.data[3], frame.data[4], frame.data[5], frame.data[6], frame.data[7]);

        std::for_each(callbacks.begin(), callbacks.end(), [frame](const receiveCallback_t cb)
        {
            if((cb.id_mask & frame.can_id) == cb.id_match)
                cb.callback(cb.handle, frame);
        });
        
        return 1;
    }

    spdlog::trace("No CAN data received");
    return 0;
}

void SocketCAN::addCallback(receiveCallback_t * callback)
{
    spdlog::debug("Adding SocketCAN Receive Callback with Mask: 0x{0:X} and Match: 0x{1:X}", callback->id_mask, callback->id_match);
    callbacks.push_back(*callback);
}