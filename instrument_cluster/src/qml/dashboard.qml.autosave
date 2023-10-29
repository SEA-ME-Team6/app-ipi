import QtQuick 2.2
import QtQuick.Window 2.1
import QtQuick.Controls 1.4
import QtQuick.Extras 1.4

Window {
    id: root
    visible: true
    width: 1280
    height: 400
    color: "#161616"
    title: "INSTRUMENT CLUSTER"
    visibility: Window.FullScreen

    Image {
        id: background
        width: parent.width
        height: parent.height
        source: "qrc:/images/images.jpg"
    }

    ValueSource {
        id: valueSource
    }

    Item {
        id: container
        width: root.width
        height: Math.min(root.width, root.height)
        anchors.centerIn: parent

        Row {
            id: gaugeRow
            spacing: container.width * 0.02
            anchors.centerIn: parent

            Item {
                width: height
                height: container.height * 0.25 - gaugeRow.spacing
                anchors.verticalCenter: parent.verticalCenter

                CircularGauge {
                    id: fuelGauge
                    value: valueSource.fuel
                    minimumValue: 0
                    maximumValue: 100
                    y: parent.height / 2 - height / 2 - container.height * 0.01
                    width: parent.width
                    height: parent.height

                    style: IconGaugeStyle {
                        icon: "qrc:/images/battery.png"
                        minWarningColor: Qt.rgba(0.5, 0, 0, 1)
                    }

                    Behavior on value {
                        NumberAnimation {
                            duration: 200
                        }
                    }
                }
            }

            CircularGauge {
                id: speedometers
                value: valueSource.kph
                anchors.verticalCenter: parent.verticalCenter
                maximumValue: 100
                width: height
                height: container.height * 0.5

                style: DashboardGaugeStyle {}

                Behavior on value {
                    NumberAnimation {
                        duration: 200
                    }
                }
            }

            CircularGauge {
                id: tachometer
                width: height
                height: container.height * 0.25 - gaugeRow.spacing
                value: valueSource.rpm
                maximumValue: 8
                anchors.verticalCenter: parent.verticalCenter

                style: TachometerStyle {}

                Behavior on value {
                    NumberAnimation {
                        duration: 200
                    }
                }
            }
        }

        Connections {
            target: car // This assumes you've set a "car" context property from C++.
            onCandisconnected: {
                cantimeoutText.visible = true
                canimage.visible = true
                speedtimeoutText.visible = false
                rpmtimeoutText.visible = false
                batterytimeoutText.visible = false
            }
            onCanconnected: {
                cantimeoutText.visible = false
            }
            onSpeeddisconnected: {
                speedtimeoutText.visible = true
            }
            onSpeedChanged:{
                speedtimeoutText.visible = false
            }
            onRpmdisconnected: {
                rpmtimeoutText.visible = true
            }
            onRpmChanged: {
                rpmtimeoutText.visible = false
            }
            onBatterydisconnected: {
                batterytimeoutText.visible = true
            }
            onBatteryChanged: {
                batterytimeoutText.visible = false
            }
        }

        Text {
            id: cantimeoutText
            anchors.top: parent.top
            anchors.horizontalCenter: parent.horizontalCenter
            text: "CAN"
            color: "white"
            visible: false // Initially, the text is hidden.
            anchors.topMargin: 50
            Image {
                id: canimage
                source: "qrc:/images/warning.jpg"
                width:16
                height:16
                anchors.left: cantimeoutText.right
                anchors.verticalCenter: cantimeoutText.verticalCenter


            }




        }


        Text {
            id: speedtimeoutText
            anchors.top: cantimeoutText.bottom
            anchors.horizontalCenter: parent.horizontalCenter
            text: "Speed"
            color: "white"
            visible: false // Initially, the text is hidden.
            anchors.margins: 5 // Adjust this value as needed for spacing
            Image {
                id: speedimage
                source: "qrc:/images/warning.jpg"
                width:16
                height:16
                anchors.left: speedtimeoutText.right
                anchors.verticalCenter: speedtimeoutText.verticalCenter


            }
        }

        Text {
            id: rpmtimeoutText
            anchors.top: speedtimeoutText.bottom
            anchors.horizontalCenter: parent.horizontalCenter
            text: "RPM"
            color: "white"
            visible: false // Initially, the text is hidden.
            anchors.margins: 5 // Adjust this value as needed for spacing
            Image {
                id: rpmimage
                source: "qrc:/images/warning.jpg"
                width:16
                height:16
                anchors.left: rpmtimeoutText.right
                anchors.verticalCenter: rpmtimeoutText.verticalCenter
            }

        }

        Text {
            id: batterytimeoutText
            anchors.top: rpmtimeoutText.bottom
            anchors.horizontalCenter: parent.horizontalCenter
            text: "Battery"
            color: "white"
            visible: false // Initially, the text is hidden.
            anchors.margins: 5 // Adjust this value as needed for spacing
            Image {
                id: batteryimage
                source: "qrc:/images/warning.jpg"
                width:16
                height:16
                anchors.left: batterytimeoutText.right
                anchors.verticalCenter: batteryText.verticalCenter
            }

        }
    }
}
