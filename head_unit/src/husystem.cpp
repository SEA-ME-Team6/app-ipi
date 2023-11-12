#include <iostream>
#include <thread>
#include <CommonAPI/CommonAPI.hpp>
#include "husystem.hpp"

using namespace v1::commonapi;

HUSystem::HUSystem() {
    runtime = CommonAPI::Runtime::get();

    std::string domain = "local";

    //gear client
    std::string gear_instance = "GearStatus";
    std::string gear_connection = "client-gear";
    gearProxy = runtime->buildProxy<GearStatusProxy>(domain, gear_instance, gear_connection);
    std::cout << "Waiting for GearSelection service to become available." << std::endl;

    //speed client
    std::string speed_instance = "SpeedStatus";
    std::string speed_connection = "client-speed";
    speedProxy = runtime->buildProxy<SpeedStatusProxy>(domain, speed_instance, speed_connection);
    std::cout << "Waiting for Speed service to become available." << std::endl;
    speedProxy->getSpeedAttribute().getChangedEvent().subscribe(
        [&](const float& speed_){
            speed_check = speed_;
        }
    );
    
    //light client
    std::string light_from_racer_instance = "LightStatus_from_racer";
    std::string light_from_racer_connection = "client-light";
    lightProxy = runtime->buildProxy<LightStatusProxy>(domain, light_from_racer_instance, light_from_racer_connection);
    std::cout << "Waiting for Light service to become available." << std::endl;
    lightProxy->getLightAttribute().getChangedEvent().subscribe(
        [&](const bool& light_){
            light = light_;
            emit lightChanged();
        }
    );

}
void HUSystem::changegear(quint8 gearselect){
    CommonAPI::CallStatus callStatus;
    uint8_t returnedGear;

    if(speed_check < 5) {
        gearProxy->gearselection(gearselect, callStatus, returnedGear);
        if (callStatus == CommonAPI::CallStatus::SUCCESS) {
            std::cout << "Gear set successfully. Returned gear: " << returnedGear <<std::endl;
        } else {
            std::cout << "Failed to set gear." << std::endl;
        }
    }
}

bool HUSystem::getLight() const {
    std::cout << "HU Light: " << light << std::endl;
    return light;
}