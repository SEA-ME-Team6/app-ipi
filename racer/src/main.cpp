#include "racer.h"
#include "racersystem.hpp"
#include <unistd.h>
#include <iostream>

int main() {
    //Racer racer;
    RacerSystem racersystem;
    int battery = 0;
    
    while (true) {
        //battery = racer.getVoltage();
        battery += 1; 
        racersystem.setBattery(battery);
        std::cout << "Battery Voltage: " << battery << " V" << std::endl;
        sleep(1);
    }

    return 0;
}
