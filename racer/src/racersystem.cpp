#include "racersystem.hpp"

#include <iostream>
#include <thread>

RacerSystem::RacerSystem(Racer* racer) : racer(racer) {
    runtime = CommonAPI::Runtime::get();
    std::string domain = "local";

    //gear stub
    gearService = std::make_shared<GearStubImpl>(racer);
    std::string gear_instance = "GearStatus";
    std::string gear_connection = "service-gear";
    while (!runtime->registerService(domain, gear_instance, gearService, gear_connection)) {
        std::cout << "Register Service failed, trying again in 100 milliseconds..." << std::endl;
        std::this_thread::sleep_for(std::chrono::milliseconds(100));
    }
    std::cout << "Successfully Registered Gear Service!" << std::endl;

    //moving proxy
    std::string moving_instance = "MovingStatus";
    std::string moving_connection = "service-moving";
    movingProxy = runtime->buildProxy<MovingStatusProxy>(domain, moving_instance, moving_connection);

    std::cout << "Waiting for Moving service to become available." << std::endl;
    movingProxy->getSteeringAttribute().getChangedEvent().subscribe(
        [&](const float& steering_){
            racer->setSteering(steering_); 
	        std::cout << "Receiving steering: " << steering_ << std::endl;
        }
    );
    movingProxy->getThrottleAttribute().getChangedEvent().subscribe(
        [&](const float& throttle_){
            racer->setThrottle(throttle_); 
	        std::cout << "Receiving throttle: " << throttle_ << std::endl;
        }
    );

    //ligth stub
    lightService = std::make_shared<LightStubImpl>();
    std::string light_from_racer_instance = "LightStatus_from_racer";
    std::string light_from_racer_connection = "service-light";
    while (!runtime->registerService(domain, light_from_racer_instance, lightService, light_from_racer_connection)) {
        std::cout << "Register Service failed, trying again in 100 milliseconds..." << std::endl;
        std::this_thread::sleep_for(std::chrono::milliseconds(100));
    }
    std::cout << "Successfully Registered Light Service!" << std::endl;

    //light proxy
    std::string light_from_game_instance = "LightStatus_from_gamepad";
    std::string light_from_game_connection = "client-light";
    lightProxy = runtime->buildProxy<LightStatusProxy>(domain, light_from_game_instance, light_from_game_connection);

    std::cout << "Waiting for Light service to become available." << std::endl;
    lightProxy->getLightAttribute().getChangedEvent().subscribe(
        [&](const bool& light_){
            racer->setLight(light_); 
            bool currentlight = racer->getLight();
            lightService->setLightAttribute(currentlight);
        }
    );
}

float RacerSystem::getSteering() {
    float steering = racer->getSteering();
    return steering;
}

float RacerSystem::getThrottle() {
    float throttle = racer->getThrottle();
    return throttle;
}