#ifndef HEADUNITSYSTEM_HPP
#define HEADUNITSYSTEM_HPP

#include <memory>
#include <QObject>
#include <stdint.h>
#include <CommonAPI/CommonAPI.hpp>
#include <v1/commonapi/GearStatusProxy.hpp>
#include <v1/commonapi/SpeedStatusProxy.hpp>

using namespace v1::commonapi;

class HUSystem: public QObject{
    Q_OBJECT

public:
    HUSystem();

public slots:
    void changegear(quint8 gearselect);

private:
    std::shared_ptr<CommonAPI::Runtime> runtime;
    std::shared_ptr<GearStatusProxy<>> gearProxy;
    std::shared_ptr<SpeedStatusProxy<>> speedProxy;

    float speed_check;
};

#endif // GEARCLIENT_HPP
