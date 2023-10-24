import QtQuick 2.9
import QtQuick.Controls 2.2

Item{
    Row{
        id: functionality
        spacing: 80
        anchors.centerIn: parent
        Button{
            id: light
            width:120
            height:120
            background: Rectangle{
                color: "transparent"
            }
            Image{
                source: "/img/shine2.png"
                sourceSize.width :parent.width
                sourceSize.height :parent.height
            }
            
            onClicked:
            {
                stackview.push(Qt.resolvedUrl("/qml/light.qml"))
            }
            
            
        }

        Button{
            id: music
            width:120
            height:120
            background: Rectangle{
                color: "transparent"
            }
            Image{
                source: "/img/music2.svg"
                sourceSize.width :parent.width
                sourceSize.height :parent.height
            }
        }

        Button{
            id: video
            width:120
            height:120
            background: Rectangle{
                color: "transparent"
            }
            Image{
                source: "/img/video.svg"
                sourceSize.width :parent.width
                sourceSize.height :parent.height
            }
        }


    }



}