import QtQuick 2.2
import QtQuick.Window 2.1
import QtQuick.Controls 2.2
import QtApplicationManager 2.0
import QtApplicationManager.Application 2.0

ApplicationManagerWindow{
    Component.onCompleted: {
        lightIntentTimer.start();
    }

    Timer {
        id: lightIntentTimer
        interval: 100
        repeat: true
        onTriggered: sendHuLightIntent()
    }

    function sendHuLightIntent() {
        var request = IntentClient.sendIntentRequest("get-light", {});
        request.onReplyReceived.connect(function() {
            if (request.succeeded) {
                var lightValue = request.result.huLightValue;
                head_light_left.visible = lightValue;
                head_light_right.visible = lightValue;
            }
            else{
                test.visible = false
                console.error("Intent request failed:", request.errorMessage);
            }
        });
    }

    Image{
        id:background
        width: parent.width
        height: parent.height
        source: "images/benz.jpg"
        Image{
            id:head_light_left
            width: 400
            height: 222
            anchors{
                left: parent.left
                top: parent.top
                topMargin: 100
            }
            source: "images/head_light.png"
        }

        Image {
            id:head_light_right
            width: 400
            height: 222
            anchors{
                right: parent.right
                top: parent.top
                topMargin: 100
            }
            source: "images/head_light.png"
        }

        Image {
            anchors{
                horizontalCenter: parent.horizontalCenter
                top: head_light_right.bottom
            }
            source: "images/ground_shadow.png"
        }
    }
}
