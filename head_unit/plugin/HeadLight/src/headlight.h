#ifndef HEADLIGHT_H
#define HEADLIGHT_H

#include <memory>
#include <QObject>
#include <stdint.h>
#include <CommonAPI/CommonAPI.hpp>
#include <v1/commonapi/LightStatusProxy.hpp>

using namespace v1::commonapi;

class HeadLight: public QObject{
    Q_OBJECT
    Q_PROPERTY(bool light READ getLight NOTIFY lightChanged)

public:
    HeadLight();
    bool getLight() const;

signals:
    void lightChanged();

private:
    std::shared_ptr<CommonAPI::Runtime> runtime;
    std::shared_ptr<LightStatusProxy<>> lightProxy;

    bool light = false;
};

#endif // HEADLIGHT_H
