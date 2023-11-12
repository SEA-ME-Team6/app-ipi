#ifndef CANRECEIVE_HPP
#define CANRECEIVE_HPP

#include <linux/can.h>
#include <linux/can/raw.h>
#include <sys/socket.h>
#include <sys/ioctl.h>
#include <net/if.h>
#include <cstring>
#include <unistd.h>
#include <queue> 

class CanReceive {
    private:
        int s;
        struct sockaddr_can addr;
        struct can_frame frame;
        struct ifreq ifr;
        const char *ifname;

        float filtered_speed, prev_filtered_speed;
        float alpha; //filtering

    public:
        explicit CanReceive(const char* interface_name);
        ~CanReceive();
        float getSpeed();
};

#endif