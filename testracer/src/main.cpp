#include "gamepad.h"
#include "racer.h"
#include "pythonmanager.h"
#include <unistd.h>
#include <iostream>

int main() {
    PythonManager pythonManager;
    Gamepad* gamepad = new Gamepad;
    Racer* racer = new Racer;

    
    while(true){
        gamepad->read_data(); 
    
        float steering = gamepad->get_inputLX(); 
        float throttle = gamepad->get_inputRY();
	bool light = gamepad->get_inputBY();
        // std::cout << "Steering: " << steering << std::endl;
        // std::cout << "Throttle: " << throttle << std::endl;
        // std::cout << "Light: " << light << std::endl;
    
        racer->set_steering_percent(steering);
        racer->set_throttle_percent(throttle);

	uint32_t battery = racer->getBatttery();
	std::cout << "Battery: " << battery << std::endl;
	//usleep(10000); 
    }
    


    return 0;
}