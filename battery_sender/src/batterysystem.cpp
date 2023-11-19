#include "batterysystem.hpp"
#include <iostream>
#include <thread>

BatterySystem::BatterySystem() : current_battery(0), filtered_battery(0), prev_filtered_battery(0), alpha(0.3){
    runtime = CommonAPI::Runtime::get();
    batteryService = std::make_shared<BatteryStubImpl>();

    std::string domain = "local";

    //battery stub
    batteryService = std::make_shared<BatteryStubImpl>();
    std::string battery_instance = "BatteryStatus";
    std::string battery_connection = "service-battery";
    while (!runtime->registerService(domain, battery_instance, batteryService, battery_connection)) {
        std::cout << "Register Service failed, trying again in 100 milliseconds..." << std::endl;
        std::this_thread::sleep_for(std::chrono::milliseconds(100));
    }
    std::cout << "Successfully Registered Battey Service!" << std::endl;

}

void BatterySystem::setBattery(uint32_t batteryStatus) {
    std::cout << "Battery Voltage: " << batteryStatus << " V" << std::endl;
    batteryService->setBatteryAttribute(batteryStatus);
}

uint32_t BatterySystem::getBattery() {
    current_battery = battery->getBatttery(); 
    
    //filtering
    filtered_battery = alpha * current_battery + (1 - alpha) * prev_filtered_battery;
    prev_filtered_battery = filtered_battery;
    return filtered_battery;
}