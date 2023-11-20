#include "batterysystem.hpp"
#include <unistd.h>
#include <iostream>

int main() {
    BatterySystem* batterysystem = new BatterySystem;
    uint32_t battery = 0;

    while(true){
        battery = batterysystem->getBattery();
        std::cout << "battery: " << battery << std::endl;
        batterysystem->setBattery(battery);
        sleep(0.5);
    }
    
    return 0;
}
