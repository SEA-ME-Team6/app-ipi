#include "CanReceive.hpp"
#include "SpeedServer.hpp"
#include <iostream>

int main() {
    CanReceive receiver("can0");
    SpeedServer speed_server;

    while (true) {
        float speed = receiver.getSpeed();
        speed_server.setSpeedAttribute(speed);
        // std::cout << "Speed_Sender Speed: " << speed << std::endl;
    }
    return 0;
}
