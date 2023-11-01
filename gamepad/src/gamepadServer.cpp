#include "gamepadServer.hpp"
#include <iostream>
#include <thread>

GamepadServer::GamepadServer(){
    runtime = CommonAPI::Runtime::get();
    movingService = std::make_shared<MovingStubImpl>();

    std::string domain = "local";

    //battery stub
    std::string moving_instance = "MovingStatus";
    std::string moving_connection = "service-moving";
    while (!runtime->registerService(domain, moving_instance, movingService, moving_connection)) {
        std::cout << "Register Service failed, trying again in 100 milliseconds..." << std::endl;
        std::this_thread::sleep_for(std::chrono::milliseconds(100));
    }
    std::cout << "Successfully Registered Moving Service!" << std::endl;
}

void GamepadServer::setSteeringAttribute(float steering){
    movingService->setSteeringAttribute(steering);
}

void GamepadServer::setThrottleAttribute(float throttle){
    movingService->setThrottleAttribute(throttle);
}