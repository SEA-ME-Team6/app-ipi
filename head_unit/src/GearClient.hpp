#ifndef GEARCLIENT_HPP
#define GEARCLIENT_HPP

#include <memory>
#include <QObject>
#include <stdint.h>
#include <CommonAPI/CommonAPI.hpp>
#include <v1/commonapi/GearStatusProxy.hpp>

using namespace v1::commonapi;

class GearClient: public QObject{
    Q_OBJECT

public:
    GearClient();

public slots:
    void changegear(quint8 gearselect);

private:
    std::shared_ptr<CommonAPI::Runtime> runtime;
    std::shared_ptr<GearStatusProxy<>> gearProxy;
};

#endif // GEARCLIENT_HPP
