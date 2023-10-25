import QtQuick 2.12
import QtQuick.Window 2.12
import QtQuick.Controls 2.12

Window {
    id:root
    width: 512
    height: 300
    color: "black"

    Image{
        id:background
        anchors.verticalCenterOffset: 0
        anchors.rightMargin: 0
        source: "img/benz.jpg"
        anchors{
            verticalCenter: parent.verticalCenter
            right: parent.right
        }
        Image{
            id:head_light_left
            anchors{
                verticalCenter: parent.verticalCenter
                right: parent.right
            }
            source: "img/head_light.png"
        }

        Image {
            id:head_light_right
            anchors{
                verticalCenter: parent.verticalCenter
                left: parent.left
            }
            source: "img/head_light.png"
        }
        Image {
            id:ground
            y: 208
            anchors.horizontalCenterOffset: 0
            anchors{
                horizontalCenter: parent.horizontalCenter
                verticalCenter: parent.verticalCenter + 185
            }
            source: "img/ground_shadow.png"
        }

    }

}
