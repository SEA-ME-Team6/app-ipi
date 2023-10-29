#include "CanReceive.hpp"
#include "SpeedServer.hpp"
#include <iostream>

int main() {
    CanReceive receiver("can0");
    SpeedServer speed_server;
    float speed;

    while (true) {
        speed = receiver.getSpeed();
        if(speed){
            speed_server.run(speed);
            std::cout << "Speed_Sender Speed: " << speed << std::endl;
        }
        else {
            std::cout << "Error receiving data." << std::endl;
        }
    }
    return 0;
}
