import QtQuick 2.9
import QtQuick.Controls 2.2
import QtGraphicalEffects 1.0

Rectangle{
    width: 200
    height: 200
    radius: 100
    anchors.centerIn: parent

    gradient: Gradient {
        GradientStop {
            id: gradientStop
            position: 0.5
        }
    }

    Slider {
        id: slider
        anchors.centerIn: parent.top
        from: 0
        to: 100
        value: 0

        onValueChanged: {
            var newColor = Qt.lighter("#5230f4", value / 50); 
            gradientStop.color = newColor;
        }
    }


}



/*
Item{
    function updateColor(){
        root.color = Qt.rgba(redSlider.value / 255, greenSlider.value / 255, blueSlider.value / 255, 1);
    }
    Column {
        id: slider
        anchors.centerIn: parent

        Slider {
            id: redSlider
            from: 0
            to: 255
            value: 128
            onValueChanged: updateColor()
            Image {
                width:20
                height:20
                anchors.right:parent.left
                source: "red.png"
            }
        }

        Slider {
            id: greenSlider
            from: 0
            to: 255
            value: 128
            onValueChanged: updateColor()
            Image {
                width:20
                height:20
                anchors.right:greenSlider.left
                source: "green.png"
            }
        }

        Slider {
            id: blueSlider
            from: 0
            to: 255
            value: 128
            onValueChanged: updateColor()
            Image {
                width:20
                height:20
                anchors.right:blueSlider.left
                source: "blue.png"
            }
        }

        Slider {
            id: opacitySlider
            from: 0
            to: 100
            value: 0

            visible: slidersVisible
            onValueChanged: {
                            updateColor();
                            colorChanged(color);
                        }
        }
    }
}
*/
 
 
 
 
 
 
 
 
 