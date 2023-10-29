#ifndef RACERSYSTEM_HPP_
#define RACERSYSTEM_HPP_

#include <memory>
#include <CommonAPI/CommonAPI.hpp>
#include "racerstubImpl.hpp"

using namespace v1::commonapi;

class RacerSystem {
public:
    RacerSystem();
    void setBattery(int battery);
    
private:
    std::shared_ptr<CommonAPI::Runtime> runtime;
    std::shared_ptr<RacerStubImpl> myService;
    
};

#endif 
