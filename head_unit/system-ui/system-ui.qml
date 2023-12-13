
import QtQuick 2.4
import QtQuick.Window 2.1
import QtApplicationManager 2.0
import QtApplicationManager.SystemUI 2.0

import User.HUSystem 1.0

Window {
    id:root
    width: 1024
    height: 600
    visible: true
    color: "black"

    IntentServerHandler {
        intentIds: [ "set-light" ]
        visibility: IntentObject.Public
        onRequestReceived: {
            request.sendReply({ huLightValue: husystem.hu_light});
        }
    }

    HUSystem {
        id: husystem
        property var hu_gear: gear // source data 
        property var hu_light: light // source data
    }

    GearSelection {
        id: gearselection
        anchors{
            top: parent.top
            topMargin: 150
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