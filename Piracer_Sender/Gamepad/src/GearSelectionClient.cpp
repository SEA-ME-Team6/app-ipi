#include "GearSelectionClient.hpp"

#include <iostream>
#include <thread>

using namespace v1::commonapi;

GearSelectionClient::GearSelectionClient() {
    CommonAPI::Runtime::setProperty("LogContext", "GS_S");
    CommonAPI::Runtime::setProperty("LogApplication", "GS_S");
    CommonAPI::Runtime::setProperty("LibraryBase", "GearSelection");

    runtime = CommonAPI::Runtime::get();

    std::string domain = "local";
    std::string Gear_instance = "commonapi.Gear";
    std::string connection = "client-gear";

    gearProxy_ = runtime->buildProxy<GearSelectionProxy>(domain, Gear_instance, connection);

    std::cout << "Successfully GearSelection Constructure" << std::endl;
}

void GearSelectionClient::run() {

    //std::cout << "Waiting for GearSelection service to become available." << std::endl;
    
    
    while (!gearProxy_->isAvailable()) {
        std::this_thread::sleep_for(std::chrono::milliseconds(10));
    }

    gearProxy_->getGearAttribute().getChangedEvent().subscribe(
        [&](const int32_t& gear){std::cout << "Gamepad Gear: " << gear << std::endl;}
    );

}

