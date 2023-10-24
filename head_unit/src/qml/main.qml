import QtQuick 2.9
import QtQuick.Window 2.2
import QtQuick.Controls 2.2

Window {
    id:root
    width: 1024
    height: 600
    visible: true
    title: qsTr("Head Unit")

    Image{
        id:background
        anchors.fill: parent
        source: "/img/benz.jpg"
    }

    StackView{
        id:stackview
        anchors.fill:parent
        initialItem: "/qml/home.qml"
    }

}
