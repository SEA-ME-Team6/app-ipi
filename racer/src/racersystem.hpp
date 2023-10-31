#ifndef RACERSYSTEM_HPP_
#define RACERSYSTEM_HPP_

#include <memory>
#include <CommonAPI/CommonAPI.hpp>
#include "batterystubImpl.hpp"
#include "gearstubImpl.hpp"
#include "racer.h"

using namespace v1::commonapi;

class RacerSystem {
public:
    RacerSystem();
    ~RacerSystem();
    void setBattery(uint32_t batteryStatus); //attribute
    
private:
    Racer* racer = new Racer();;
    std::shared_ptr<CommonAPI::Runtime> runtime;
    std::shared_ptr<BatteryStubImpl> batteryService;
    std::shared_ptr<GearStubImpl> gearService;
    
};

#endif 
