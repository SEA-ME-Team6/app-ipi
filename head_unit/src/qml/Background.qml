import QtQuick 2.2
import QtQuick.Window 2.1
import QtQuick.Controls 2.2

Image{
    id:background
    source: "qrc:/images/benz.jpg"
    anchors{
        right: parent.right
        bottom: parent.bottom
    }
    Image{
        id:head_light_left
        anchors{
            verticalCenter: parent.verticalCenter
            left: parent.left
        }
        source: "qrc:/images/head_light.png"
        visible: valueSource.light
    }

    Image {
        id:head_light_right
        anchors{
            verticalCenter: parent.verticalCenter
            right: parent.right
        }
        source: "qrc:/images/head_light.png"
        visible: valueSource.light
    }

    Image {
        anchors{
            horizontalCenter: parent.horizontalCenter
            top: head_light_right.bottom
        }
        source: "qrc:/images/ground_shadow.png"
    }
}