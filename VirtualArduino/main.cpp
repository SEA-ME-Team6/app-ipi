#include "CanSender.hpp"
#include <unistd.h>
#include <iostream>

int main() {
    CanSender sender("can0");
    float rpm = 0.0f;

    while (true) {
        sender.sendRPM(rpm);
        std::cout << "Sent rpm: " << rpm << std::endl;
        rpm += 1.0f;
        sleep(1); 
    }

    return 0;
}
