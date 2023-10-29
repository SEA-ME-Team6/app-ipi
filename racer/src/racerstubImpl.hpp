#ifndef RACERSTUBIMPL_HPP
#define RACERSTUBIMPL_HPP

#include <CommonAPI/CommonAPI.hpp>
#include <v1/commonapi/BatteryStatusStubDefault.hpp>

class RacerStubImpl : public v1_0::commonapi:: BatteryStatusStubDefault {
public:
    RacerStubImpl();
    ~RacerStubImpl();
};

#endif


