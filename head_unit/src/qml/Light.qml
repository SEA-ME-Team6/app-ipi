import QtQuick 2.2
import QtQuick.Window 2.1
import QtQuick.Controls 2.2
import QtQuick.Layouts 1.12

Item {
    id: ambient
    width: parent.parent.width
    height: parent.parent.height

    property string ambient_color: "#808080"

    Image {
        id: benz_logo
        source: "qrc:/images/benz_logo.jpg"
        anchors.horizontalCenter: parent.horizontalCenter
        Rectangle{
            id: color_overlap
            width: parent.height * 0.5
            height: parent.height * 0.5
            anchors{
                verticalCenter: parent.verticalCenter
                horizontalCenter: parent.horizontalCenter
            }
            color: ambient.ambient_color
            opacity: 0.2
            radius: 1000
        }
    }

    Column {
        anchors {
            top: benz_logo.bottom
            horizontalCenter: parent.horizontalCenter
        } 
        spacing:1

        Slider {
            id: redSlider
            from: 0
            to: 255
            value: 128
            stepSize: 1
            onValueChanged: {
                ambient.ambient_color = "#" + (redSlider.value.toString(16).length === 1 ? "0" : "") + redSlider.value.toString(16) + ambient.ambient_color.substring(3, 7)
            }
        }

        Slider {
            id: greenSlider
            from: 0
            to: 255
            value: 128
            stepSize: 1
            onValueChanged: {
                ambient.ambient_color = "#" + ambient.ambient_color.substring(1, 3) + (greenSlider.value.toString(16).length === 1 ? "0" : "") + greenSlider.value.toString(16) + ambient.ambient_color.substring(5, 7)
            }
        }

        Slider {
            id: blueSlider
            from: 0
            to: 255
            value: 128
            stepSize: 1
            onValueChanged: {
                ambient.ambient_color = "#" + ambient.ambient_color.substring(1, 5) + (blueSlider.value.toString(16).length === 1 ? "0" : "") + blueSlider.value.toString(16)
            }
        }
    }
}