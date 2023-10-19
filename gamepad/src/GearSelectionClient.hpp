#ifndef GEARSELECTIONCLIENT_HPP
#define GEARSELECTIONCLIENT_HPP

#include <memory>
#include <CommonAPI/CommonAPI.hpp>
#include <v1/commonapi/GearSelectionProxy.hpp>

using namespace v1::commonapi;

class GearSelectionClient {
public:
    GearSelectionClient();
    void run();

private:
    std::shared_ptr<CommonAPI::Runtime> runtime;
    std::shared_ptr<GearSelectionProxy<>> gearProxy_;
};

#endif // GEARSELECTIONCLIENT
