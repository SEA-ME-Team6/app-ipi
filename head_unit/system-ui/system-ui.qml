
import QtQuick 2.4
import QtApplicationManager.SystemUI 2.0
import QtQuick.Window 2.1

import User.HUSystem 1.0

Window {
    id:root
    width: 1024
    height: 600
    visible: true
    color: "black"

    function sendHuLightIntent() {
        var lightValue = husystem.light;
        var parameters = { huLightValue: lightValue };

        var request = IntentClient.sendIntentRequest("set-light", "headlight", parameters);

        request.onReplyReceived.connect(function() {
            if (request.succeeded) {
                console.log("Success intent: ", request.result);
            } else {
                console.error("Fail intent: ", request.errorMessage);
            }
        });
    }

    HUSystem {
        id: husystem
        property var hu_gear: gear
    }

    Connections {
        target: husystem
        onLightChanged: {
            sendHuLightIntent
        }
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