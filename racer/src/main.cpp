#include "racer.h"
#include "racersystem.hpp"
#include <unistd.h>
#include <iostream>

int main() {
    Racer* racer = new Racer;
    RacerSystem* racersystem = new RacerSystem(racer);

    float steering = 0.0;
    float throttle = 0.0;
    
    while (true) {
        steering = racer->getSteering();
        throttle = racer->getThrottle();

        racer->set_steering_percent(steering);
        racer->set_throttle_percent(throttle);
    }
    
    delete racersystem;
    delete racer;

    return 0;
}
