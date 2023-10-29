import QtQuick 2.2

Item {
    id: valueSource
    property real kph:  car.speed
    //property real rpm:  car.rpm
    property real fuel: car.battery
}

