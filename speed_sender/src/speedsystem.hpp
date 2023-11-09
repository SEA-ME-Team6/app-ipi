#ifndef SPEEDSYSTEM_HPP_
#define SPEEDSYSTEM_HPP_

#include <memory>
#include <CommonAPI/CommonAPI.hpp>
#include "speedstubImpl.hpp"

using namespace v1::commonapi;

class SpeedSystem {
public:
    SpeedSystem();
    void setSpeedAttribute(float speed);
    
private:
    std::shared_ptr<CommonAPI::Runtime> runtime;
    std::shared_ptr<SpeedStubImpl> myService_;
    
};

#endif 
