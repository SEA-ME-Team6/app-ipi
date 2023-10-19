#ifndef BATTERYSERVER_HPP_
#define BATTERYSERVER_HPP_

#include <memory>
#include <CommonAPI/CommonAPI.hpp>
#include "BatteryStubImpl.hpp"

using namespace v1::commonapi;

class BatteryServer {
public:
    BatteryServer();
    void run(int battery);
    
private:
    std::shared_ptr<CommonAPI::Runtime> runtime;
    std::shared_ptr<BatteryStubImpl> myService_;
    
};

#endif 
