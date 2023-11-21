#ifndef RACERSYSTEM_HPP_
#define RACERSYSTEM_HPP_

#include <memory>
#include <CommonAPI/CommonAPI.hpp>
#include <v1/commonapi/MovingStatusProxy.hpp>
#include <v1/commonapi/LightStatusProxy.hpp>
#include "gearstubImpl.hpp"
#include "lightstubImpl.hpp"
#include "racer.h"

using namespace v1::commonapi;

class RacerSystem {
public:
    RacerSystem(Racer* racer);
    
private:
    std::shared_ptr<CommonAPI::Runtime> runtime;
    std::shared_ptr<GearStubImpl> gearService;
    std::shared_ptr<LightStubImpl> lightService;

    std::shared_ptr<MovingStatusProxy<>> movingProxy;
    std::shared_ptr<LightStatusProxy<>> lightProxy;
    
};

#endif 
