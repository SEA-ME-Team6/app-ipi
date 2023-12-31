/*
 * This file was generated by the CommonAPI Generators.
 * Used org.genivi.commonapi.someip 3.2.0.v202012010944.
 * Used org.franca.core 0.13.1.201807231814.
 *
 * This Source Code Form is subject to the terms of the Mozilla Public License, v. 2.0.
 * If a copy of the MPL was not distributed with this file, You can obtain one at
 * http://mozilla.org/MPL/2.0/.
 */
#include <v1/commonapi/LightStatusSomeIPProxy.hpp>

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

std::shared_ptr<CommonAPI::SomeIP::Proxy> createLightStatusSomeIPProxy(
    const CommonAPI::SomeIP::Address &_address,
    const std::shared_ptr<CommonAPI::SomeIP::ProxyConnection> &_connection) {
    return std::make_shared< LightStatusSomeIPProxy>(_address, _connection);
}

void initializeLightStatusSomeIPProxy() {
    CommonAPI::SomeIP::AddressTranslator::get()->insert(
        "local:commonapi.LightStatus:v1_0:LightStatus",
        0x1239, 0x567d, 1, 0);
    CommonAPI::SomeIP::Factory::get()->registerProxyCreateMethod(
        "commonapi.LightStatus:v1_0",
        &createLightStatusSomeIPProxy);
}

INITIALIZER(registerLightStatusSomeIPProxy) {
    CommonAPI::SomeIP::Factory::get()->registerInterface(initializeLightStatusSomeIPProxy);
}

LightStatusSomeIPProxy::LightStatusSomeIPProxy(
    const CommonAPI::SomeIP::Address &_address,
    const std::shared_ptr<CommonAPI::SomeIP::ProxyConnection> &_connection)
        : CommonAPI::SomeIP::Proxy(_address, _connection),
          light_(*this, CommonAPI::SomeIP::eventgroup_id_t(0x84dd), CommonAPI::SomeIP::event_id_t(0x84dd), CommonAPI::SomeIP::method_id_t(0xc1f), false, CommonAPI::SomeIP::reliability_type_e::RT_UNRELIABLE, false, CommonAPI::SomeIP::method_id_t(0xc20), false, static_cast< CommonAPI::EmptyDeployment* >(nullptr))
{
}

LightStatusSomeIPProxy::~LightStatusSomeIPProxy() {
    completed_.set_value();
}

LightStatusSomeIPProxy::LightAttribute& LightStatusSomeIPProxy::getLightAttribute() {
    return light_;
}


void LightStatusSomeIPProxy::changedlight(bool _light, CommonAPI::CallStatus &_internalCallStatus, std::string &_message, const CommonAPI::CallInfo *_info) {
    CommonAPI::Deployable< bool, CommonAPI::EmptyDeployment> deploy_light(_light, static_cast< CommonAPI::EmptyDeployment* >(nullptr));
    CommonAPI::Deployable< std::string, CommonAPI::SomeIP::StringDeployment> deploy_message(static_cast< CommonAPI::SomeIP::StringDeployment* >(nullptr));
    CommonAPI::SomeIP::ProxyHelper<
        CommonAPI::SomeIP::SerializableArguments<
            CommonAPI::Deployable<
                bool,
                CommonAPI::EmptyDeployment
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
        CommonAPI::SomeIP::method_id_t(0x83f),
        false,
        false,
        (_info ? _info : &CommonAPI::SomeIP::defaultCallInfo),
        deploy_light,
        _internalCallStatus,
        deploy_message);
    _message = deploy_message.getValue();
}

std::future<CommonAPI::CallStatus> LightStatusSomeIPProxy::changedlightAsync(const bool &_light, ChangedlightAsyncCallback _callback, const CommonAPI::CallInfo *_info) {
    CommonAPI::Deployable< bool, CommonAPI::EmptyDeployment> deploy_light(_light, static_cast< CommonAPI::EmptyDeployment* >(nullptr));
    CommonAPI::Deployable< std::string, CommonAPI::SomeIP::StringDeployment> deploy_message(static_cast< CommonAPI::SomeIP::StringDeployment* >(nullptr));
    return CommonAPI::SomeIP::ProxyHelper<
        CommonAPI::SomeIP::SerializableArguments<
            CommonAPI::Deployable<
                bool,
                CommonAPI::EmptyDeployment
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
        CommonAPI::SomeIP::method_id_t(0x83f),
        false,
        false,
        (_info ? _info : &CommonAPI::SomeIP::defaultCallInfo),
        deploy_light,
        [_callback] (CommonAPI::CallStatus _internalCallStatus, CommonAPI::Deployable< std::string, CommonAPI::SomeIP::StringDeployment > _message) {
            if (_callback)
                _callback(_internalCallStatus, _message.getValue());
        },
        std::make_tuple(deploy_message));
}

void LightStatusSomeIPProxy::getOwnVersion(uint16_t& ownVersionMajor, uint16_t& ownVersionMinor) const {
    ownVersionMajor = 1;
    ownVersionMinor = 0;
}

std::future<void> LightStatusSomeIPProxy::getCompletionFuture() {
    return completed_.get_future();
}

} // namespace commonapi
} // namespace v1
