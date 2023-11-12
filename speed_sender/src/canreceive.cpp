#include "canreceive.hpp"
#include <cstdio>
#include <cstdlib>
#include <iostream>
# define M_PI           3.1415 /* pi */
# define WheelRadius    0.0325

CanReceive::CanReceive(const char* interface_name) : ifname(interface_name), filtered_speed(0), prev_filtered_speed(0), alpha(0.7) {
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
    float rpm =0;
    int nbytes = read(s, &frame, sizeof(struct can_frame));

    //Receiveing CAN data
    if (nbytes < 0) {
        perror("Error reading from CAN socket");
        return false;
    }
    std::memcpy(&rpm, frame.data, sizeof(float));
    float current_speed = rpm * (2 * M_PI * WheelRadius);
    
    //Filtering
    if (current_speed < 0.01) {
        filtered_speed = 0;
        prev_filtered_speed = 0;
    }
    else {
    	filtered_speed = alpha * current_speed + (1 - alpha) * prev_filtered_speed;
    	prev_filtered_speed = filtered_speed;
    }

    std::cout << "Origin Speed: " << current_speed << std::endl;
    std::cout << "Filltering Speed: " << filtered_speed << std::endl;

    return filtered_speed;
}