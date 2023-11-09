#ifndef GAMEPADSYSTEM_HPP_
#define GAMEPADSYSTEM_HPP_

#include <memory>
#include <CommonAPI/CommonAPI.hpp>
#include "movingStubImpl.hpp"

using namespace v1::commonapi;

class GamepadSystem {
public:
    GamepadSystem();
    void setSteeringAttribute(float steering);
    void setThrottleAttribute(float throttle);
    
private:
    std::shared_ptr<CommonAPI::Runtime> runtime;
    std::shared_ptr<MovingStubImpl> movingService;
    
};

#endif 
