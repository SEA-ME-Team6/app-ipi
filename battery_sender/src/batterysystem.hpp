#ifndef BATTERYSYSTEM_HPP_
#define BATTERYSYSTEM_HPP_

#include <memory>
#include <CommonAPI/CommonAPI.hpp>
#include "batterystubImpl.hpp"
#include "battery.h"

using namespace v1::commonapi;

class BatterySystem {
public:
    BatterySystem();
    void setBattery(uint32_t batteryStatus);
    uint32_t getBattery();
    
private:
    Battery* battery = new Battery();
    std::shared_ptr<CommonAPI::Runtime> runtime;
    std::shared_ptr<BatteryStubImpl> batteryService;

    uint32_t current_battery;
    uint32_t filtered_battery, prev_filtered_battery;
    float alpha;
};

#endif 
