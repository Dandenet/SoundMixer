import QtQuick
import SoundMixer 1.0
import QtQuick.Dialogs

Item {

    ListView {
        id: soundList
        anchors.fill: parent
        model: controller.getModel()
        delegate: Item {
            height: 75
            width: soundList.width

            SoundTrack {
                anchors.fill: parent
                anchors.margins: 5
                trackName: display.name





                Rectangle {
                    id: deleteButton
                    anchors.right: parent.right
                    anchors.verticalCenter: parent.verticalCenter
                    anchors.rightMargin: 20

                    height: parent.height / 2
                    width: height
                    radius: height / 2

                    color: "#333333"

                    Image {
                        id: deleteImage
                        anchors.margins: 5
                        anchors.fill: parent
                        source: "qrc:/app/images/delete.svg"
                    }


                    MouseArea {
                        anchors.fill: parent

                        onClicked: {
                            controller.removeSoundTrack(index);
                        }
                    }
                }
            }
        }


        footer: Item {
            height: soundList.height / 14 * 2
            width: soundList.width

            Item {
                id: addButton
                height: parent.height / 2
                width: parent.width

                Rectangle {
                    anchors.fill: parent
                    anchors.margins: 5
                    radius: 5

                    color: "#a83305"

                    Text {
                        anchors.centerIn: parent
                        color: "#FFFFFF"
                        text: qsTr("+")

                        font.bold: true
                        font.pointSize: parent.height * 2 / 3
                    }

                    MouseArea {
                        anchors.fill: parent

                        onClicked: {
                            var fileDialog = Qt.createQmlObject('import QtQuick.Dialogs; FileDialog {}', parent);
                            fileDialog.open();
                            fileDialog.accepted.connect(function() {
                                controller.addSoundTrack(fileDialog.selectedFile);
                            });
                        }

                    }
                }
            }

            Item {
                visible: soundList.count >= 2
                height: parent.height / 2
                width: parent.width
                anchors.top: addButton.bottom

                Rectangle {
                    anchors.fill: parent
                    anchors.margins: 5
                    radius: 5

                    color: "#242a6e"

                    Image {
                        height: parent.height - 5
                        width: height
                        anchors.centerIn: parent
                        source: "qrc:/app/images/merge.svg"
                    }

                    MouseArea {
                        anchors.fill: parent

                        onClicked: {
                            console.log("Merge start");
                            controller.mix();
                            console.log("Merge end");
                        }

                    }
                }
            }

        }
    }

    Controller_qml {
        id: controller
    }


}
