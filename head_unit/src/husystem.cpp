#include <iostream>
#include <thread>
#include <QDebug>
#include <CommonAPI/CommonAPI.hpp>
#include <v1/commonapi/GearStatusProxy.hpp>
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
        [&](const float& speed){
            speed_check = speed;
        }
    );
}

void HUSystem::changegear(quint8 gearselect){
    CommonAPI::CallStatus callStatus;
    uint8_t returnedGear;

    if(speed_check < 5) {
        gearProxy->gearselection(gearselect, callStatus, returnedGear);
        if (callStatus == CommonAPI::CallStatus::SUCCESS) {
            qDebug() << "Gear set successfully. Returned gear: " << returnedGear;
        } else {
            qDebug() << "Failed to set gear.";
        }
    }
}

