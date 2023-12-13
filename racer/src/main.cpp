#include <unistd.h>
#include <iostream>
// #include "racer.h"
#include "racersystem.hpp"
#include "gearstubImpl.hpp"

int main() {
    // Racer* racer = new Racer;
    RacerSystem* racersystem = new RacerSystem();
    GearStubImpl* gearstubimpl = new GearStubImpl();

    float steering = 0.0;
    float throttle = 0.0;
    uint8_t gear = 0;
    
    while (true) {
        steering = racersystem->getSteering();
        throttle = racersystem->getThrottle();

        gear = gearstubimpl->getGear();
        if(gear == 1)
            throttle *= (-1);
        else if(gear == 0 or gear == 2)
            throttle = 0;
        else
            ;

        // racer->set_steering_percent(steering);
        // racer->set_throttle_percent(throttle);
    }
    
    delete racersystem;
    // delete racer;

    return 0;
}
