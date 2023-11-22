#ifndef GEARSTUBIMPL_HPP
#define GEARSTUBIMPL_HPP

#include <CommonAPI/CommonAPI.hpp>
#include <v1/commonapi/GearStatusStubDefault.hpp>

class GearStubImpl : public v1_0::commonapi:: GearStatusStubDefault {

public:
    GearStubImpl();
    void setGear(uint8_t gear_);
    virtual void gearselection(const std::shared_ptr<CommonAPI::ClientId> _client,
                               uint8_t _gearselect,
                               gearselectionReply_t _reply) override;

private:
    uint8_t gear;
};

#endif


