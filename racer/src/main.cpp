#include "racer.h"
#include "racersystem.hpp"
#include <unistd.h>
#include <iostream>

int main() {
    RacerSystem* racersystem = new RacerSystem;
    Racer* racer = new Racer;
    
    while (true) {
        racer->set_steering_percent();
        racer->set_throttle_percent();
        sleep(0.1);
    }
    
    return 0;
}
