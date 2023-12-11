#ifndef GEARSELECTION_H
#define GEARSELECTION_H

#include <memory>
#include <QObject>
#include <stdint.h>
#include <CommonAPI/CommonAPI.hpp>
#include <v1/commonapi/RPMStatusProxy.hpp>
#include <v1/commonapi/GearStatusProxy.hpp>

using namespace v1::commonapi;

class GearSelection: public QObject{
    Q_OBJECT
    Q_PROPERTY(uint8_t gear READ getGear NOTIFY gearChanged)

public:
    GearSelection();
    uint8_t getGear() const;

public slots:
    void changegear(quint8 gearselect);

signals:
    void gearChanged();

private:

    std::shared_ptr<CommonAPI::Runtime> runtime;
    std::shared_ptr<RPMStatusProxy<>> rpmProxy;
    std::shared_ptr<GearStatusProxy<>> gearProxy;

    float rpm_check = 0.0;
    uint8_t gear = 0;
};

#endif // GEARCLIENT_HPP