#include "racersystem.hpp"

#include <iostream>
#include <thread>

RacerSystem::RacerSystem() : current_battery(0), filtered_battery(0), prev_filtered_battery(0), alpha(0.3){
    runtime = CommonAPI::Runtime::get();
    batteryService = std::make_shared<BatteryStubImpl>();
    gearService = std::make_shared<GearStubImpl>(racer);

    std::string domain = "local";

    //battery stub
    std::string battery_instance = "BatteryStatus";
    std::string battery_connection = "service-battery";
    while (!runtime->registerService(domain, battery_instance, batteryService, battery_connection)) {
        std::cout << "Register Service failed, trying again in 100 milliseconds..." << std::endl;
        std::this_thread::sleep_for(std::chrono::milliseconds(100));
    }
    std::cout << "Successfully Registered Battey Service!" << std::endl;

    //gear stub
    std::string gear_instance = "GearStatus";
    std::string gear_connection = "service-gear";
    while (!runtime->registerService(domain, gear_instance, gearService, gear_connection)) {
        std::cout << "Register Service failed, trying again in 100 milliseconds..." << std::endl;
        std::this_thread::sleep_for(std::chrono::milliseconds(100));
    }
    std::cout << "Successfully Registered Gear Service!" << std::endl;

    //moving proxy
    std::string moving_instance = "MovingStatus";
    std::string moving_connection = "service-gear";
    movingProxy = runtime->buildProxy<MovingStatusProxy>(domain, moving_instance, moving_connection);

    std::cout << "Waiting for Moving service to become available." << std::endl;
    movingProxy->getSteeringAttribute().getChangedEvent().subscribe(
        [&](const float& steering){
            racer->set_steering_percent(steering); 
        }
    );
    movingProxy->getThrottleAttribute().getChangedEvent().subscribe(
        [&](const float& throttle){
            racer->set_throttle_percent(throttle); 
        }
    );

}

void RacerSystem::setBatteryAttribute(uint32_t batteryStatus) {
    std::cout << "Battery Voltage: " << batteryStatus << " V" << std::endl;
    batteryService->setBatteryAttribute(batteryStatus);
}

uint32_t RacerSystem::getBattery() {
    current_battery = racer->getBatttery(); 
    filtered_battery = alpha * current_battery + (1 - alpha) * prev_filtered_battery;
    prev_filtered_battery = filtered_battery;
    return filtered_battery;
}