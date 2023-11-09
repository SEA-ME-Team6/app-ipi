#include "icsystem.hpp"

#include <iostream>
#include <thread>

using namespace v1::commonapi;

ICSystem::ICSystem() {
    runtime = CommonAPI::Runtime::get();

    std::string domain = "local";

    //speed
    std::string speed_instance = "SpeedStatus";
    std::string speed_connection = "client-speed";
    speedProxy = runtime->buildProxy<SpeedStatusProxy>(domain, speed_instance, speed_connection);

    std::cout << "Waiting for Speed service to become available." << std::endl;
    speedProxy->getSpeedAttribute().getChangedEvent().subscribe(
        [&](const float& speed){
            this->speed = speed;
            emit speedChanged();
        }
    );

    //battery
    std::string battery_instance = "BatteryStatus";
    std::string battery_connection = "client-battery";
    batteryProxy = runtime->buildProxy<BatteryStatusProxy>(domain, battery_instance, battery_connection);

    std::cout << "Waiting for GearSelection service to become available." << std::endl;
    batteryProxy->getBatteryAttribute().getChangedEvent().subscribe(
        [&](const float& battery){
            this->battery = battery;
            emit batteryChanged();
        }
    );

}

float ICSystem::getSpeed() const {
    std::cout << "IC Speed: " << this->speed << std::endl;
    return this->speed;
}

float ICSystem::getBattery() const {
    std::cout << "IC Battery: " << this->battery << std::endl;
    return this->battery;
}

