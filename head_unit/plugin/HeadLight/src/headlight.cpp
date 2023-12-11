#include <iostream>
#include <thread>
#include <CommonAPI/CommonAPI.hpp>
#include "headlight.h"

using namespace v1::commonapi;

HeadLight::HeadLight() {
    runtime = CommonAPI::Runtime::get();

    std::string domain = "local";;
    
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

bool HeadLight::getLight() const {
    std::cout << "HU Light: " << light << std::endl;
    return light;
}