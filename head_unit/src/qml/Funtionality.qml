import QtQuick 2.2
import QtQuick.Window 2.1
import QtQuick.Controls 2.2


Row{
    anchors{
        right: parent.right
        top: parent.top
        topMargin: 52
        rightMargin: 180
    }
    spacing: 200
    Button {
        id: music_icon
        background: Image {
            source: "qrc:/images/music.jpeg"
            anchors.fill: parent
            fillMode: Image.PreserveAspectFit
        }
        onClicked: {
            stackview.push(Qt.resolvedUrl("/music.qml"))
        }
    }

    Button {
        id: light_icon
        background: Image {
            source: "qrc:/images/setting.jpeg"
            anchors.fill: parent
            fillMode: Image.PreserveAspectFit
        }
        onClicked: {
            stackview.push(Qt.resolvedUrl("qrc:/qml/Light.qml"))
        }
    }

    Button {
        id: video_icon
        background: Image {
            source: "qrc:/images/video.png"
            anchors.fill: parent
            fillMode: Image.PreserveAspectFit
        }
        onClicked: {
            stackview.push(Qt.resolvedUrl("qrc:/qml/music.qml"))
        }
    }
}