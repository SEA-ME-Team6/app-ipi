#include "racersystem.hpp"

#include <iostream>
#include <thread>

RacerSystem::RacerSystem() {
    runtime = CommonAPI::Runtime::get();
    myService = std::make_shared<RacerStubImpl>();

    std::string domain = "local";
    std::string instance = "BatteryStatus";
    std::string connection = "service-battery";

    while (!runtime->registerService(domain, instance, myService, connection)) {
        std::cout << "Register Service failed, trying again in 100 milliseconds..." << std::endl;
        std::this_thread::sleep_for(std::chrono::milliseconds(100));
    }

    std::cout << "Successfully Registered Battey Service!" << std::endl;
}

void RacerSystem::setBattery(int battery) {
    myService->setBatteryAttribute(battery);
}
