#ifndef SOCKETCAN_H_
#define SOCKETCAN_H_

#include <list>
#include <poll.h>
#include <stdint.h>
#include <string>
#include <net/if.h>
#include <sys/ioctl.h>
#include <sys/socket.h>

class SocketCAN
{
    public:
        typedef void (*canReceiveCallback)(struct can_frame frame);

        struct receiveCallback_t
        {
            canReceiveCallback callback;
            int32_t id_mask;
            int32_t id_match;
        };

        int32_t configureSocketCAN(std::string iface);

        int32_t killSocket();

        int32_t sendFrame(struct can_frame frame);

        int32_t receiveData();

        void addCallback(receiveCallback_t * callback);

    private:
        int socketID;
        struct ifreq ifr;
        struct sockaddr_can addr;
        struct pollfd pollDesc;
        std::list<receiveCallback_t> callbacks;
};

#endif