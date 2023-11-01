#ifndef GAMEPADSERVER_HPP_
#define GAMEPADSERVER_HPP_

#include <memory>
#include <CommonAPI/CommonAPI.hpp>
#include "movingStubImpl.hpp"

using namespace v1::commonapi;

class GamepadServer {
public:
    GamepadServer();
    void setSteeringAttribute(float steering);
    void setThrottleAttribute(float throttle);
    
private:
    std::shared_ptr<CommonAPI::Runtime> runtime;
    std::shared_ptr<MovingStubImpl> movingService;
    
};

#endif 
