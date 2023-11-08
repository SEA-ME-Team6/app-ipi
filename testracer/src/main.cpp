#include "gamepad.h"
#include "racer.h"
#include "pythonmanager.h"
#include <unistd.h>
#include <iostream>

int main() {
    PythonManager pythonManager;
    Gamepad gamepad;
    Racer racer;

    
    while(true){
        gamepad.read_data(); 
    
        float steering = gamepad.get_inputLX(); 
        float throttle = gamepad.get_inputRY();
        std::cout << "Steering: " << steering << std::endl;
        std::cout << "Throttle: " << throttle << std::endl;
    
        racer.set_steering_percent(steering);
        racer.set_throttle_percent(throttle);
    }
    


    return 0;
}