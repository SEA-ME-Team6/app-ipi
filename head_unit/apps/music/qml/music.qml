import QtQuick 2.15
import QtQuick.Controls 2.15
import QtMultimedia 5.15
import QtQuick.Dialogs 1.3
import QtQuick.Layouts 1.0
import QtApplicationManager.Application 2.0

import User.Music 1.0

ApplicationManagerWindow {
    color: "black"
    Music {
        id: usbManager
        property bool usbStatus: true;
    }

    MediaPlayer {
        id: mediaPlayer
        autoPlay: false
    }

    Connections {
        target: usbManager

        onFileListChanged: {
                   var files = usbManager.fileList;
                   console.log("File list changed. New list1:", files);
                   console.log("File list changed", usbManager.fileList.filePath);
                   playlistModel.clear();

                    // Add songs to the playlistModel
                    for (var i = 0; i < files.length; i++) {
                        var source ="file://" + files[i];

                        var title = source.substring(source.lastIndexOf("/") + 1);

                        playlistModel.append({ title: title, source: source });
                    }
               }
        onUsbRemoved: {
            usbManager.usbStatus = status
            console.log("i: ", usbManager.usbStatus);
            playlistModel.clear();
        }
    }

    Button {
        id: music_list_button
        width: 80
        height: 80
        anchors {
            top: parent.top
            left: parent.left
            margins: 40
        }
        background: Image {
            anchors.fill: parent
            source: "images/queue-music.png"
        }
        onClicked:
        {
            usbManager.startUSBScan();
            myImage.visible = true;
            console.log("button clicked");
        }
    }

    Text {
        visible: !usbManager.usbStatus
        id: usbStatusText
        text: "USB device is not detected!"
        color: "white"
        font.pixelSize: 18
        anchors {
            top: parent.top
            left: parent.left
            topMargin: 150
        }
    }

    ListView {
        id: playlistView
        visible: usbManager.usbStatus
        width: parent.width / 3
        height: parent.height * 0.8
        anchors {
            top: parent.top
            left: parent.left
            margins: 50
        }
        model: ListModel {
            id: playlistModel
        }
        delegate: Item {
            width: 300
            height: 50
            Rectangle {
                width: parent.width
                height: 50
                color: "black"
                border.color: "#a1a1a3"
                Text {
                    anchors.centerIn: parent
                    text: model.title
                    color: "white"
                }
                MouseArea {
                    anchors.fill: parent
                    onClicked: {
                        mediaPlayer.stop()
                        mediaPlayer.source = model.source
                        mediaPlayer.play()
                        playlistView.currentIndex = index
                    }
                }
            }
        }
    }

    Rectangle {
        id: music_background
        anchors {
            top: parent.top
            topMargin: 40
            right: parent.right
        }
        width: 400
        height: 350
        color: "#a1a1a3"
        opacity: 0.4
        border.color: "black"
        border.width: 0.5
        radius: 10

        Slider {
            id: volume_slider
            anchors {
                top: parent.bottom
                topMargin: 20
                horizontalCenter: parent.horizontalCenter
            }
            width: 340
            from: 0
            to: 1
            value: mediaPlayer.volume
            onValueChanged: {
                mediaPlayer.volume = value
            }
        }
        
        Text {
            id: currentlyPlayingText
            anchors {
                horizontalCenter: parent.horizontalCenter
                top: parent.top
                topMargin: 230
            }
            text: (playlistModel.get(playlistView.currentIndex) ? playlistModel.get(playlistView.currentIndex).title : "")
            color: "white"
            font.pixelSize: 16
            horizontalAlignment: Text.AlignHCenter
            verticalAlignment: Text.AlignVCenter
            wrapMode: Text.WrapAtWordBoundaryOrAnywhere
        }

        Image {
            id: playingimg
            width: 200
            height: 200
            source: "images/musicplaying.jpg"
            visible: currentlyPlayingText.text !== ""
            anchors {
                horizontalCenter: parent.horizontalCenter
                top: parent.top
                topMargin: 20
            }
        }

        Slider {
            id: playerPosition
            width: 340
            anchors {
                horizontalCenter: parent.horizontalCenter
                top: parent.top
                topMargin: 250
            }
            from: 0
            to: mediaPlayer.duration
            value: mediaPlayer.position
            onValueChanged: {
                mediaPlayer.seek(value)
            }

        }

        Row {
            spacing: 50
            anchors {
                horizontalCenter: parent.horizontalCenter
                top: parent.top
                topMargin: 280
            }

            Button {
                width: 50
                height: 50
                background: Image {
                    source: "images/skip-previous_icon.png"
                }
                onClicked: {
                    var newIndex = playlistView.currentIndex - 1;
                    if (newIndex >= 0) {
                        mediaPlayer.stop();
                        mediaPlayer.source = playlistModel.get(newIndex).source;
                        mediaPlayer.play();
                        playlistView.currentIndex = newIndex;
                    }
                }
            }
            Button {
                width: 50
                height: 50
                background: Image{
                    source: mediaPlayer.playbackState === MediaPlayer.PlayingState ? "images/pause_icon.png" : "images/play_icon.png"
                }

                onClicked: {
                    if (mediaPlayer.playbackState === MediaPlayer.PlayingState) {
                        mediaPlayer.pause();
                    } else {
                        mediaPlayer.play();
                    }
                }
            }

            Button {
                id: next
                width: 50
                height: 50
                background: Image {
                    source: "images/skip-next_icon.png"
                }

                onClicked: {
                    var newIndex = playlistView.currentIndex + 1;
                    if (newIndex < playlistModel.count) {
                        mediaPlayer.stop();
                        mediaPlayer.source = playlistModel.get(newIndex).source;
                        mediaPlayer.play();
                        playlistView.currentIndex = newIndex;
                    }
                }
            }
        }
    }


}
