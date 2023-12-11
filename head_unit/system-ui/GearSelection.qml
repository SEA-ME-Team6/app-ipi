import QtQuick 2.2
import QtQuick.Window 2.1
import QtQuick.Controls 2.2

import User.GearSelection 1.0

Item{
    GearSelection {
        id: gearselection
        property int hu_gear: gear
    }

    Column{
        spacing: 50
        Button {
            id: p_gear
            background: Image {
                source: gearselection.hu_gear === 0 ? "images/p_red.png" : "images/p.png"
                anchors.fill: parent
            }
            onClicked: {
                gearselection.changegear(0);
            }
        }

        Button {
            id: r_gear
            background: Image {
                source: gearselection.hu_gear === 1 ? "images/r_red.png" : "images/r.png"
                anchors.fill: parent
            }
            onClicked: {
                gearselection.changegear(1);
            }
        }

        Button {
            id: n_gear
            background: Image {
                source: gearselection.hu_gear === 2 ? "images/n_red.png" : "images/n.png"
                anchors.fill: parent
            }
            onClicked: {
                gearselection.changegear(2);
            }
        }

        Button {
            id: d_gear
            background: Image {
                source: gearselection.hu_gear === 3 ? "images/d_red.png" : "images/d.png"
                anchors.fill: parent
            }
            onClicked: {
                gearselection.changegear(3);
            }
        }
    }
}