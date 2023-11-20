import QtQuick 2.2
import QtQuick.Window 2.1
import QtQuick.Controls 2.2

Item {
    id:home
    width: 1024
    height: 600
    scale: 0.5
    x: -256
    y: -150

    ValueSource {
        id: valueSource
    }

    Background {
        id: backgroundImage
    }

    Funtionality {
        id: functionality
    }

    GearSelection {
        id: gearselection
    }
}
