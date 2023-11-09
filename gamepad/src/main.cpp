//#include "game.h"
#include "gamepadsystem.hpp"
#include <unistd.h>

int main() {
    //Gamepad* gamepad;
    GamepadSystem* gamepadsystem = new GamepadSystem;

    float steering = 0;
    float throttle = 0;
    
    while(true){
        //gamepad->read_data(); 
    
        //steering = gamepad.get_inputLX(); 
        //throttle = gamepad.get_inputRY();
        steering +=1;
        throttle +=1;

        std::cout << "Steering: " << steering << std::endl;
        std::cout << "Throttle: " << throttle << std::endl;

        gamepadsystem->setSteeringAttribute(steering);
        gamepadsystem->setThrottleAttribute(throttle);

        sleep(1);
    }
    
    return 0;
}