//#include "game.h"
#include "gamepadServer.hpp"
#include <unistd.h>

int main() {
    //Gamepad* gamepad;
    GamepadServer* gamepadserver = new GamepadServer;

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

        gamepadserver->setSteeringAttribute(steering);
        gamepadserver->setThrottleAttribute(throttle);

        sleep(1);
    }
    
    return 0;
}