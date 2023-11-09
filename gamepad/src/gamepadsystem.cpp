#include "gamepadsystem.hpp"
#include <iostream>
#include <thread>

GamepadSystem::GamepadSystem(){
    runtime = CommonAPI::Runtime::get();
    movingService = std::make_shared<MovingStubImpl>();

    std::string domain = "local";

    //moving stub
    std::string moving_instance = "MovingStatus";
    std::string moving_connection = "service-moving";
    while (!runtime->registerService(domain, moving_instance, movingService, moving_connection)) {
        std::cout << "Register Service failed, trying again in 100 milliseconds..." << std::endl;
        std::this_thread::sleep_for(std::chrono::milliseconds(100));
    }
    std::cout << "Successfully Registered Moving Service!" << std::endl;

    // //light from gamepad client
    // std::string light_from_gamepad_instance = "lightStatus_from_gamepad";
    // std::string light_from_gamepad_connection = "client-light";
    // lightProxy1 = runtime->buildProxy<lightStatusProxy>(domain, light_from_gamepad_instance, light_from_gamepad_connection);
    // std::cout << "Successfully Accessed Light from gamepad Service!" << std::endl;
}

void GamepadSystem::setSteeringAttribute(float steering){
    movingService->setSteeringAttribute(steering);
}

void GamepadSystem::setThrottleAttribute(float throttle){
    movingService->setThrottleAttribute(throttle);
}