#include "gearstubImpl.hpp"


GearStubImpl::GearStubImpl() : gear(0) {

}

void GearStubImpl::gearselection(const std::shared_ptr<CommonAPI::ClientId> _client,
                                 uint8_t _gearselect,
                                 gearselectionReply_t _reply) {

    if(_gearselect != 7){
        setGear(_gearselect);
        setGearAttribute(gear);
    }
    _reply(gear);
}

void GearStubImpl::setGear(uint8_t gear_) {
    gear = gear_;
}

uint8_t GearStubImpl::getGear() {
    return gear;
}