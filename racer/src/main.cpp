#include "racer.h"
#include "racersystem.hpp"
#include <unistd.h>
#include <iostream>

int main() {
    RacerSystem* racersystem = new RacerSystem;
    uint32_t battery = 0;
    
    while (true) {
        battery = racersystem->getBattery();
        racersystem->setBattery(battery);
    }
    
    return 0;
}
