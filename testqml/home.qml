import QtQuick 2.12
import QtQuick.Window 2.12
import QtQuick.Controls 2.12

Window {
    width: 1024
    height: 600
    color: "black"

    Image{
        id:background
        width: 650
        height: 400
        source: "img/benz.jpg"
        anchors{
            horizontalCenter: parent.horizontalCenter
            verticalCenter: parent.verticalCenter
        }
        Image{
            id:head_light_left
            width: 315
            height: 126
            anchors{
                verticalCenter: parent.verticalCenter
                right: parent.right
            }
            source: "img/head_light.png"
        }

        Image {
            id:head_light_right
            width: 315
            height: 126
            anchors{
                verticalCenter: parent.verticalCenter
                left: parent.left
            }
            source: "img/head_light.png"
        }
        Image {
            width: 563
            height: 161
            anchors{
                horizontalCenter: parent.horizontalCenter
                top: head_light_right.bottom
                topMargin: 50
            }
            source: "img/ground_shadow.png"
        }

    }
    Column{
        anchors{
            verticalCenter: parent.verticalCenter
            right: parent.right
            rightMargin: 50
        }
        spacing: 100
        Button {
            id: music_icon
            width: 70
            height: 70
            background: Image {
                source: "img/music.png"
                anchors.fill: parent
                fillMode: Image.PreserveAspectFit
            }
            contentItem: Text {
                text: qsTr("Music")
            }
            onClicked: {
                stackview.push(Qt.resolvedUrl("/music.qml"))
            }
        }

        Button {
            id: light_icon
            width: 70
            height: 70
            background: Image {
                source: "img/light.png"
                anchors.fill: parent
                fillMode: Image.PreserveAspectFit
            }
            contentItem: Text {
                text: qsTr("Light")
            }
            onClicked: {
                stackview.push(Qt.resolvedUrl("/light.qml"))
            }
        }

        Button {
            id: video_icon
            width: 70
            height: 70
            background: Image {
                source: "img/video.png"
                anchors.fill: parent
                fillMode: Image.PreserveAspectFit
            }
            contentItem: Text {
                text: qsTr("video")
            }
            onClicked: {
                stackview.push(Qt.resolvedUrl("/video.qml"))
            }
        }
    }

}
