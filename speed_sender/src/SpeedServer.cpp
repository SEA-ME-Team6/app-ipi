#include "SpeedServer.hpp"

#include <iostream>
#include <thread>

SpeedServer::SpeedServer() {
    runtime = CommonAPI::Runtime::get();
    myService_ = std::make_shared<SpeedStubImpl>();

    std::string domain = "local";
    std::string instance = "SpeedStatus";
    std::string connection = "service-speed";

    while (!runtime->registerService(domain, instance, myService_, connection)) {
        std::cout << "Register Service failed, trying again in 100 milliseconds..." << std::endl;
        std::this_thread::sleep_for(std::chrono::milliseconds(100));
    }

    std::cout << "Successfully Registered Service!" << std::endl;
}

void SpeedServer::run(float speed) {
    myService_->setSpeedAttribute(speed);
}
