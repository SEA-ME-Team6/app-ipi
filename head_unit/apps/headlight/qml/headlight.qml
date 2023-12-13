import QtQuick 2.2
import QtQuick.Window 2.1
import QtQuick.Controls 2.2
import QtApplicationManager 2.0
import QtApplicationManager.Application 2.0

ApplicationManagerWindow{

    function sendHuLightIntent() {
        var request = IntentClient.sendIntentRequest("set-light", {});
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

    Component.onCompleted: {
        lightIntentTimer.start();
    }

    Timer {
        id: lightIntentTimer
        interval: 100
        repeat: true
        onTriggered: sendHuLightIntent()
    }

    Image{
        id:background
        width: parent.width
        height: parent.height
        source: "images/benz.jpg"
        Image{
            id:head_light_left
            anchors{
                verticalCenter: parent.verticalCenter
                left: parent.left
            }
            source: "images/head_light.png"
        }

        Image {
            id:head_light_right
            anchors{
                verticalCenter: parent.verticalCenter
                right: parent.right
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
    Image{
        id: test
        source: "images/d_red.png"
    }
}
