/*
 * This file was generated by the CommonAPI Generators.
 * Used org.genivi.commonapi.someip 3.2.0.v202012010944.
 * Used org.franca.core 0.13.1.201807231814.
 *
 * This Source Code Form is subject to the terms of the Mozilla Public License, v. 2.0.
 * If a copy of the MPL was not distributed with this file, You can obtain one at
 * http://mozilla.org/MPL/2.0/.
 */
#include <v1/commonapi/GearStatusSomeIPProxy.hpp>

#if !defined (COMMONAPI_INTERNAL_COMPILATION)
#define COMMONAPI_INTERNAL_COMPILATION
#define HAS_DEFINED_COMMONAPI_INTERNAL_COMPILATION_HERE
#endif

#include <CommonAPI/SomeIP/AddressTranslator.hpp>

#if defined (HAS_DEFINED_COMMONAPI_INTERNAL_COMPILATION_HERE)
#undef COMMONAPI_INTERNAL_COMPILATION
#undef HAS_DEFINED_COMMONAPI_INTERNAL_COMPILATION_HERE
#endif

namespace v1 {
namespace commonapi {

std::shared_ptr<CommonAPI::SomeIP::Proxy> createGearStatusSomeIPProxy(
    const CommonAPI::SomeIP::Address &_address,
    const std::shared_ptr<CommonAPI::SomeIP::ProxyConnection> &_connection) {
    return std::make_shared< GearStatusSomeIPProxy>(_address, _connection);
}

void initializeGearStatusSomeIPProxy() {
    CommonAPI::SomeIP::AddressTranslator::get()->insert(
        "local:commonapi.GearStatus:v1_0:GearStatus",
        0x1237, 0x567c, 1, 0);
    CommonAPI::SomeIP::Factory::get()->registerProxyCreateMethod(
        "commonapi.GearStatus:v1_0",
        &createGearStatusSomeIPProxy);
}

INITIALIZER(registerGearStatusSomeIPProxy) {
    CommonAPI::SomeIP::Factory::get()->registerInterface(initializeGearStatusSomeIPProxy);
}

GearStatusSomeIPProxy::GearStatusSomeIPProxy(
    const CommonAPI::SomeIP::Address &_address,
    const std::shared_ptr<CommonAPI::SomeIP::ProxyConnection> &_connection)
        : CommonAPI::SomeIP::Proxy(_address, _connection),
          gear_(*this, CommonAPI::SomeIP::eventgroup_id_t(0x80f5), CommonAPI::SomeIP::event_id_t(0x80f5), CommonAPI::SomeIP::method_id_t(0xbbb), false, CommonAPI::SomeIP::reliability_type_e::RT_UNRELIABLE, false, CommonAPI::SomeIP::method_id_t(0xbbc), false, static_cast< CommonAPI::SomeIP::IntegerDeployment<uint8_t>* >(nullptr))
{
}

GearStatusSomeIPProxy::~GearStatusSomeIPProxy() {
    completed_.set_value();
}

GearStatusSomeIPProxy::GearAttribute& GearStatusSomeIPProxy::getGearAttribute() {
    return gear_;
}


void GearStatusSomeIPProxy::gearselection(uint8_t _gear, CommonAPI::CallStatus &_internalCallStatus, std::string &_message, const CommonAPI::CallInfo *_info) {
    CommonAPI::Deployable< uint8_t, CommonAPI::SomeIP::IntegerDeployment<uint8_t>> deploy_gear(_gear, static_cast< CommonAPI::SomeIP::IntegerDeployment<uint8_t>* >(nullptr));
    CommonAPI::Deployable< std::string, CommonAPI::SomeIP::StringDeployment> deploy_message(static_cast< CommonAPI::SomeIP::StringDeployment* >(nullptr));
    CommonAPI::SomeIP::ProxyHelper<
        CommonAPI::SomeIP::SerializableArguments<
            CommonAPI::Deployable<
                uint8_t,
                CommonAPI::SomeIP::IntegerDeployment<uint8_t>
            >
        >,
        CommonAPI::SomeIP::SerializableArguments<
            CommonAPI::Deployable<
                std::string,
                CommonAPI::SomeIP::StringDeployment
            >
        >
    >::callMethodWithReply(
        *this,
        CommonAPI::SomeIP::method_id_t(0x7d0),
        false,
        false,
        (_info ? _info : &CommonAPI::SomeIP::defaultCallInfo),
        deploy_gear,
        _internalCallStatus,
        deploy_message);
    _message = deploy_message.getValue();
}

std::future<CommonAPI::CallStatus> GearStatusSomeIPProxy::gearselectionAsync(const uint8_t &_gear, GearselectionAsyncCallback _callback, const CommonAPI::CallInfo *_info) {
    CommonAPI::Deployable< uint8_t, CommonAPI::SomeIP::IntegerDeployment<uint8_t>> deploy_gear(_gear, static_cast< CommonAPI::SomeIP::IntegerDeployment<uint8_t>* >(nullptr));
    CommonAPI::Deployable< std::string, CommonAPI::SomeIP::StringDeployment> deploy_message(static_cast< CommonAPI::SomeIP::StringDeployment* >(nullptr));
    return CommonAPI::SomeIP::ProxyHelper<
        CommonAPI::SomeIP::SerializableArguments<
            CommonAPI::Deployable<
                uint8_t,
                CommonAPI::SomeIP::IntegerDeployment<uint8_t>
            >
        >,
        CommonAPI::SomeIP::SerializableArguments<
            CommonAPI::Deployable<
                std::string,
                CommonAPI::SomeIP::StringDeployment
            >
        >
    >::callMethodAsync(
        *this,
        CommonAPI::SomeIP::method_id_t(0x7d0),
        false,
        false,
        (_info ? _info : &CommonAPI::SomeIP::defaultCallInfo),
        deploy_gear,
        [_callback] (CommonAPI::CallStatus _internalCallStatus, CommonAPI::Deployable< std::string, CommonAPI::SomeIP::StringDeployment > _message) {
            if (_callback)
                _callback(_internalCallStatus, _message.getValue());
        },
        std::make_tuple(deploy_message));
}

void GearStatusSomeIPProxy::getOwnVersion(uint16_t& ownVersionMajor, uint16_t& ownVersionMinor) const {
    ownVersionMajor = 1;
    ownVersionMinor = 0;
}

std::future<void> GearStatusSomeIPProxy::getCompletionFuture() {
    return completed_.get_future();
}

} // namespace commonapi
} // namespace v1
