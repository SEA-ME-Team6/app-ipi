#include "racer.h"
#include "racersystem.hpp"
#include <unistd.h>
#include <iostream>

int main() {
    RacerSystem* racersystem = new RacerSystem;
    Racer* racer = new Racer;
    float steering = 0.0;
    float throttle = 0.0;
    
    while (true) {
        steering = racer->getSteering();
        throttle = racer->getThrottle();

        //racer->set_steering_percent(steering);
        //racer->set_throttle_percent(throttle);
        sleep(0.5);
    }
    
    return 0;
}
