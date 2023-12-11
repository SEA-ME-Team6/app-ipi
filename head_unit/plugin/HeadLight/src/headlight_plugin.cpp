#include <QtQml>
#include "headlight.h"
#include "headlight_plugin.h"


void HeadLightPlugin::registerTypes(const char* uri)
{
    qmlRegisterType<HeadLight>(uri, 1, 0, "HeadLight");
}
