#include "racersystem.hpp"

#include <iostream>
#include <thread>

RacerSystem::RacerSystem(){
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

}

/*
RacerSystem::~RacerSystem() {
    delete racer;
}
*/

void RacerSystem::setBattery(uint32_t batteryStatus) {
    batteryService->setBatteryAttribute(batteryStatus);
}