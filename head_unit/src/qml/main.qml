import QtQuick 2.9
import QtQuick.Window 2.2
import QtQuick.Controls 2.2

Window {
    id:root
    width: 512
    height: 300
    title: qsTr("Head Unit")

    Image{
        id:background
        source: "/img/benz.jpg"
        anchors{
            verticalCenter: parent.verticalCenter
            right: parent.right
        }
    }

    Column{
        Button {
            text: "0"
            onClicked: {
                server.buttonPressed(0)
            }
        }

        Button {
            text: "1"
            onClicked: {
                server.buttonPressed(1)
            }
        }

        Button {
            text: "2"
            onClicked: {
                server.buttonPressed(2)
            }
        }

        Button {
            text: "3"
            onClicked: {
                server.buttonPressed(3)
            }
        }
    }
/*
    StackView{
        id:stackview
        anchors.fill:parent
        initialItem: "/qml/home.qml"
    }
*/

}
