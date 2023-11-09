#ifndef STATUS_HPP
#define STATUS_HPP

#include <memory>
#include <QObject>
#include <CommonAPI/CommonAPI.hpp>
#include <v1/commonapi/SpeedStatusProxy.hpp>
#include <v1/commonapi/BatteryStatusProxy.hpp>

using namespace v1::commonapi;

class ICSystem: public QObject{
    Q_OBJECT
    Q_PROPERTY(qreal speed READ getSpeed NOTIFY speedChanged)
    Q_PROPERTY(qreal battery READ getBattery NOTIFY batteryChanged)

public:
    ICSystem();
    float getSpeed() const;
    float getBattery() const;

signals:
    void speedChanged();
    void batteryChanged();

private:
    float speed = 0.0f;
    int battery = 0;
    std::shared_ptr<CommonAPI::Runtime> runtime;
    std::shared_ptr<SpeedStatusProxy<>> speedProxy;
    std::shared_ptr<BatteryStatusProxy<>> batteryProxy;

};

#endif // STATUS_HPP
