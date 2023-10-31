#include <iostream>
#include <thread>
#include <QDebug>
#include <CommonAPI/CommonAPI.hpp>
#include <v1/commonapi/GearStatusProxy.hpp>
#include "GearClient.hpp"

using namespace v1::commonapi;

GearClient::GearClient() {
    runtime = CommonAPI::Runtime::get();

    std::string domain = "local";

    //gear client
    std::string gear_instance = "GearStatus";
    std::string gear_connection = "client-gear";
    gearProxy = runtime->buildProxy<GearStatusProxy>(domain, gear_instance, gear_connection);
    /*
    while (!gearProxy->isAvailable()){
        std::this_thread::sleep_for(std::chrono::microseconds(10));
    }
    */
    std::cout << "Successfully Accessed Battey Service!" << std::endl;

}

void GearClient::gearselection(quint8 gearselect){
    CommonAPI::CallStatus callStatus;
    uint8_t returnedGear;

    gearProxy->gearselection(gearselect, callStatus, returnedGear);
    if (callStatus == CommonAPI::CallStatus::SUCCESS) {
        qDebug() << "Gear set successfully. Returned gear: " << returnedGear;
    } else {
        qDebug() << "Failed to set gear.";
    }
}

