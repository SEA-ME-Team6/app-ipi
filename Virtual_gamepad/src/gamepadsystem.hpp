#ifndef GAMEPADSYSTEM_HPP_
#define GAMEPADSYSTEM_HPP_

#include <memory>
#include <CommonAPI/CommonAPI.hpp>
#include "lightstubImpl.hpp"


using namespace v1::commonapi;

class GamepadSystem {
public:
    GamepadSystem();
    void setLightAttribute(bool light);
    
private:
    std::shared_ptr<CommonAPI::Runtime> runtime;
    std::shared_ptr<LightStubImpl> lightService;
    
};

#endif 
