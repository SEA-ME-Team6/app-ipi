#ifndef STATUS_HPP
#define STATUS_HPP

#include <memory>
#include <QObject>
#include <CommonAPI/CommonAPI.hpp>
#include <v1/commonapi/SpeedStatusProxy.hpp>
#include <v1/commonapi/BatteryStatusProxy.hpp>
#include <v1/commonapi/GearStatusProxy.hpp>

using namespace v1::commonapi;

class ICSystem: public QObject{
    Q_OBJECT
    Q_PROPERTY(qreal speed READ getSpeed NOTIFY speedChanged)
    Q_PROPERTY(qreal rpm READ getRpm NOTIFY RpmChanged)
    Q_PROPERTY(qreal battery READ getBattery NOTIFY batteryChanged)
    Q_PROPERTY(qreal gear READ getGear NOTIFY gearChanged)

public:
    ICSystem();
    float getSpeed() const;
    float getRpm() const;
    uint32_t getBattery() const;
    uint8_t getGear() const;

signals:
    void speedChanged();
    void RpmChanged();
    void batteryChanged();
    void gearChanged();

private:
    float speed = 0.0f;
    float rpm = 0.0f;
    uint32_t battery = 0;
    uint8_t gear = 0;
    std::shared_ptr<CommonAPI::Runtime> runtime;
    std::shared_ptr<SpeedStatusProxy<>> speedProxy;
    std::shared_ptr<BatteryStatusProxy<>> batteryProxy;
    std::shared_ptr<GearStatusProxy<>> gearProxy;

};

#endif // STATUS_HPP
