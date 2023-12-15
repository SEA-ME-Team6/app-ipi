#include <iostream>
#include "gearstubImpl.hpp"

GearStubImpl::GearStubImpl() : gear(0) {

}

void GearStubImpl::gearselection(const std::shared_ptr<CommonAPI::ClientId> _client,
                                 uint8_t _gearselect,
                                 gearselectionReply_t _reply) {

    if(_gearselect != 7){
        gear = _gearselect;
        std::cout << "racer change gear to " << _gearselect << std::endl;
        setGearAttribute(gear);
    }
    _reply(gear);
}

uint8_t GearStubImpl::getGear() {
    return gear;
}