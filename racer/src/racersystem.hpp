#ifndef RACERSYSTEM_HPP_
#define RACERSYSTEM_HPP_

#include <memory>
#include <CommonAPI/CommonAPI.hpp>
#include <v1/commonapi/MovingStatusProxy.hpp>
#include "batterystubImpl.hpp"
#include "gearstubImpl.hpp"
#include "racer.h"

using namespace v1::commonapi;

class RacerSystem {
public:
    RacerSystem();
    ~RacerSystem();
    void setBatteryAttribute(uint32_t batteryStatus); //attribute
    uint32_t getBattery();
    
private:
    Racer* racer = new Racer();;
    std::shared_ptr<CommonAPI::Runtime> runtime;
    std::shared_ptr<BatteryStubImpl> batteryService;
    std::shared_ptr<GearStubImpl> gearService;
    std::shared_ptr<MovingStatusProxy<>> movingProxy;

    uint32_t current_battery;
    uint32_t filtered_battery, prev_filtered_battery;
    float alpha;
    
};

#endif 
