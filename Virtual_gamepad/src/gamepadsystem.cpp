#include "gamepadsystem.hpp"
#include <iostream>
#include <thread>

GamepadSystem::GamepadSystem(){
    runtime = CommonAPI::Runtime::get();
    lightService = std::make_shared<LightStubImpl>();

    std::string domain = "local";

    // light stub
    std::string light_from_game_instance = "LightStatus_from_gamepad";
    std::string light_from_game_connection = "service-light";
    while (!runtime->registerService(domain, light_from_game_instance, lightService, light_from_game_connection)) {
        std::cout << "Register light Service failed, trying again in 100 milliseconds..." << std::endl;
        std::this_thread::sleep_for(std::chrono::milliseconds(100));
    }
    std::cout << "Successfully Registered Light Service!" << std::endl;

}

void GamepadSystem::setLightAttribute(bool light){
    lightService->setLightAttribute(light);
    std::cout<<"Sending Light: " << light << std::endl;
}
