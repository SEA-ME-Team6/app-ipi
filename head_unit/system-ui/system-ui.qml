
import QtQuick 2.4
import QtApplicationManager.SystemUI 2.0
import QtQuick.Window 2.1

Window {
    id:root
    width: 1024
    height: 600
    visible: true
    color: "black"

    GearSelection {
        id: gearselection
        anchors{
            verticalCenter: parent.verticalCenter
            left: parent.left
            leftMargin: 32
        }
        
    }

    // Show application names and icons
    Row {
        anchors{
            right: parent.right
            top: parent.top
            topMargin: 52
            rightMargin: 180
        }
        id: functionality
        spacing: 200
        Repeater {
            model: ApplicationManager
            Image {
                source: model.icon
                MouseArea {
                    anchors.fill: parent
                    onClicked: model.isRunning ? application.stop() : application.start()
                }
            }
        }
    }

    // Show windows
    Repeater {
        model: WindowManager
        WindowItem {
            anchors{
                right: parent.right
                top: parent.top
                topMargin: 130
                rightMargin: 100
            }
            width: 800
            height: 450
            window: model.window
        }
    }

}