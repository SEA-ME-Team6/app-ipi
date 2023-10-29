#include "CanReceive.hpp"
#include <cstdio>
#include <cstdlib>
# define M_PI           3.14159265358979323846  /* pi */
# define WheelRadius    0.0325

CanReceive::CanReceive(const char* interface_name) : ifname(interface_name) {
    if ((s = socket(PF_CAN, SOCK_RAW, CAN_RAW)) < 0) {
        perror("Error while opening socket");
        exit(-1);
    }

    std::strcpy(ifr.ifr_name, ifname);
    ioctl(s, SIOCGIFINDEX, &ifr);

    addr.can_family  = AF_CAN;
    addr.can_ifindex = ifr.ifr_ifindex;

    if (bind(s, (struct sockaddr *)&addr, sizeof(addr)) < 0) {
        perror("Error in socket bind");
        exit(-2);
    }
}

CanReceive::~CanReceive() {
    close(s);
}

float CanReceive::getSpeed() {
    float rpm;
    int nbytes = read(s, &frame, sizeof(struct can_frame));

    if (nbytes < 0) {
        perror("Error reading from CAN socket");
        return false;
    }

    std::memcpy(&rpm, frame.data, sizeof(float));
    
    float speed = rpm * (2 * M_PI * WheelRadius);
    return speed;
}