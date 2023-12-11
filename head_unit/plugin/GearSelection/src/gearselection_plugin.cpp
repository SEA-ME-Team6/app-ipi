#include "gearselection_plugin.h"

#include "gearselection.h"
#include <QtQml>

void GearSelectionPlugin::registerTypes(const char* uri)
{
    qmlRegisterType<GearSelection>(uri, 1, 0, "GearSelection");
}
