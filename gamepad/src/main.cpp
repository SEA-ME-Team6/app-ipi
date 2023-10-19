//#include "Gamepad.h"
//#include "piracer.h"
//#include "PythonManager.h"
#include <unistd.h>
#include "GearSelectionClient.hpp"
#include <iostream>

int main() {
    //PythonManager pythonManager;
    //Gamepad gamepad;
    //Piracer racer;

    GearSelectionClient *gearclient = new GearSelectionClient();

    while(true){
        gearclient->run();
        sleep(10000);
    }

    
    /*
    while(true){
        gamepad.read_data(); 
    
        float steering = gamepad.get_inputLX(); 
        float throttle = gamepad.get_inputRY();

        std::cout << "Steering: " << steering << std::endl;
        std::cout << "Throttle: " << throttle << std::endl;
    
        racer.set_steering_percent(steering);
        racer.set_throttle_percent(throttle);

    }
    */
    

    return 0;
}