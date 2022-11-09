#ifndef SOCKETCAN_H_
#define SOCKETCAN_H_

#include <list>
#include <poll.h>
#include <stdint.h>
#include <string>
#include <net/if.h>
#include <sys/ioctl.h>
#include <sys/socket.h>

/* SocketCAN Setup
 * For Ubuntu
 * Reference: https://www.pragmaticlinux.com/2021/10/can-communication-on-the-raspberry-pi-with-socketcan/
 * Reference: https://www.pragmaticlinux.com/2021/07/automatically-bring-up-a-socketcan-interface-on-boot/
 * 
 * Add the following to /boot/firmware/usercfg.txt
 * dtoverlay=mcp2515-can0,oscillator=CLOCKFREQ,interrupt=25,spimaxfrequency=2000000
 * Change CLOCKFREQ to the frequency of the MCP2515 clock
 * Ensure dtparam=spi=on is in /boot/firmware/config.txt or add it to the usercfg file
 * 
 * Create a file: /etc/modules-load.d/can.conf and put in the following:
 * can
 * can_raw
 * 
 * run the following commands:
 * sudo systemctl start systemd-networkd
 * sudo systemctl enable systemd-networkd
 * 
 * Create a file: /etc/systemd/network/80-can.network and put in the following:
 * [Match]
 * Name=can0
 * [CAN]
 * BitRate=500000
 * RestartSec=100ms
 * 
 * The following requires systemd 249 (Later than Ubuntu 20.04)
 * Create a file: /etc/systemd/network/80-can.link and put in the following:
 * [Match]
 * Name=can0
 * [Link]
 * TransmitQueueLength=10000
 * 
 * Alternately, run the command: sudo ifconfig can0 txqueuelen 10000
*/

class SocketCAN
{
    public:
        typedef void (*canReceiveCallback)(void * handle, struct can_frame frame);

        struct receiveCallback_t
        {
            canReceiveCallback callback;
            int32_t id_mask;
            int32_t id_match;
            void * handle;
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
        bool lastActionSucceeded = true;
};

#endif