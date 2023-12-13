import QtQuick 2.2
import QtQuick.Window 2.1
import QtQuick.Controls 2.2
import QtApplicationManager.Application 2.0

ApplicationManagerWindow{
    IntentHandler {
        intentIds: "set-light"
        onRequestReceived: {
            var lightValue = request.parameters.huLightValue;

            head_light_left.visible = lightValue;
            head_light_right.visible = lightValue;

            request.sendReply({ "done": true });
        }
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
            visible: false
        }

        Image {
            id:head_light_right
            anchors{
                verticalCenter: parent.verticalCenter
                right: parent.right
            }
            source: "images/head_light.png"
            visible: false
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
