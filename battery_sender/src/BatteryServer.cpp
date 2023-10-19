#include "BatteryServer.hpp"

#include <iostream>
#include <thread>

BatteryServer::BatteryServer() {
    CommonAPI::Runtime::setProperty("LogContext", "BS_S");
    CommonAPI::Runtime::setProperty("LogApplication", "BS_S");
    CommonAPI::Runtime::setProperty("LibraryBase", "BatteryServer");

    runtime = CommonAPI::Runtime::get();
    myService_ = std::make_shared<BatteryStubImpl>();

    std::string domain = "local";
    std::string instance = "commonapi.BatteryStatus";
    std::string connection = "service-sample";

    while (!runtime->registerService(domain, instance, myService_, connection)) {
        std::cout << "Register Service failed, trying again in 100 milliseconds..." << std::endl;
        std::this_thread::sleep_for(std::chrono::milliseconds(100));
    }

    std::cout << "Successfully Registered Service!" << std::endl;
}

void BatteryServer::run(int battery) {
    myService_->setBatteryAttribute(battery);
}
