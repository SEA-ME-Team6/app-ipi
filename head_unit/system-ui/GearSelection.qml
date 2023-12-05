import QtQuick 2.2
import QtQuick.Window 2.1
import QtQuick.Controls 2.2

Column{
    spacing: 50
    Button {
        id: p_gear
        background: Image {
            // source: valueSource.gear === 0 ? "qrc:/images/p_red.png" : "qrc:/images/p.png"
            source: "images/p_red.png"
            anchors.fill: parent
        }
        onClicked: {
            // husystem.changegear(0);
        }
    }

    Button {
        id: r_gear
        background: Image {
            // source: valueSource.gear === 1 ? "qrc:/images/r_red.png" : "qrc:/images/r.png"
            source: "images/r_red.png"
            anchors.fill: parent
        }
        onClicked: {
            // husystem.changegear(1);
        }
    }

    Button {
        id: n_gear
        background: Image {
            // source: valueSource.gear === 2 ? "qrc:/images/n_red.png" : "qrc:/images/n.png"
            source: "images/n_red.png"
            anchors.fill: parent
        }
        onClicked: {
            // husystem.changegear(2);
        }
    }

    Button {
        id: d_gear
        background: Image {
            // source: valueSource.gear === 3 ? "qrc:/images/d_red.png" : "qrc:/images/d.png"
            source: "images/d_red.png"
            anchors.fill: parent
        }
        onClicked: {
            // husystem.changegear(3);
        }
    }
}