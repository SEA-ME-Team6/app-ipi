#include "gamepadsystem.hpp"
#include <unistd.h>
#include <iostream>

int main() {
    GamepadSystem* gamepadsystem = new GamepadSystem;
    bool light = false;
    
    while(true){
        light = !light;
        std::cout << "Light: " << light << std::endl;

        gamepadsystem->setLightAttribute(light);

        sleep(2);
    }
    
    return 0;
}
