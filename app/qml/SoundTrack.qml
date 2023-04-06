import QtQuick
Item {
    id: name
    property alias trackName: trackName.text


    function durationToString(duration)
    {
        var minutes = Math.floor(duration / 60);
        var seconds = duration % 60;
        return minutes + ":" + seconds;
    }


    // Background
    Rectangle {
        id: backgroundRectangle
        z: -1
        anchors.fill: parent
        radius: 5
        color: "#555555"
        opacity: 0.5
    }


    // Start time
    Item {
        id: startTime

        height: parent.height / 4
        width:  parent.width / 4

        anchors.bottom: backgroundRectangle.bottom
        anchors.left:   backgroundRectangle.left
        anchors.margins: 10

        Rectangle {
            id: time1
            height: parent.height
            width: parent.width / 4
            radius: height / 4

            Text {
                anchors.centerIn: parent
                text: durationToString(model.display.startTime)
                color: "#111111"
            }

            color: "#cccccc"
        }

        Rectangle {
            id: minusButton1
            height: parent.height
            width: height
            radius: parent.height / 4

            anchors.left: time1.right
            anchors.leftMargin: 2

            color: "#333333"
            border.color: "#111111"

            Text {
                anchors.centerIn: parent
                text: qsTr("-")
                color: "#FFFFFF"
            }

            MouseArea {
                anchors.fill: parent
                onClicked: {
                    model.display.decreaseStartTime()
                }
            }
        }


        Rectangle {
            id: plusButton1
            height: parent.height
            width: height
            radius: parent.height / 4

            anchors.left: minusButton1.right
            anchors.leftMargin: 2

            color: "#333333"
            border.color: "#111111"

            Text {
                anchors.centerIn: parent
                text: qsTr("+")
                color: "#FFFFFF"
            }

            MouseArea {
                anchors.fill: parent
                onClicked: {
                    model.display.increaseStartTime();
                }
            }
        }
    }

    // End time
    Item {
        id: endTime

        height: parent.height / 4
        width:  parent.width / 4

        anchors.bottom: backgroundRectangle.bottom
        anchors.left:   backgroundRectangle.horizontalCenter
        anchors.margins: 10
        Rectangle {
            id: time2
            height: parent.height
            width: parent.width / 4
            radius: height / 4

            Text {
                anchors.centerIn: parent
                text: durationToString(model.display.endTime)
                color: "#111111"
            }

            color: "#cccccc"
        }

        Rectangle {
            id: minusButton2
            height: parent.height
            width: height
            radius: parent.height / 4

            anchors.left: time2.right
            anchors.leftMargin: 2

            color: "#333333"
            border.color: "#111111"

            Text {
                anchors.centerIn: parent
                text: qsTr("-")
                color: "#FFFFFF"
            }

            MouseArea {
                anchors.fill: parent
                onClicked: {
                    model.display.decreaseEndTime()
                }
            }
        }


        Rectangle {
            id: plusButton2
            height: parent.height
            width: height
            radius: parent.height / 4

            anchors.left: minusButton2.right
            anchors.leftMargin: 2

            color: "#333333"
            border.color: "#111111"

            Text {
                anchors.centerIn: parent
                text: qsTr("+")
                color: "#FFFFFF"
            }

            MouseArea {
                anchors.fill: parent
                onClicked: {
                    model.display.increaseEndTime();
                }
            }
        }
    }

    Text {
        id: trackName
        anchors.left: parent.left
        anchors.bottom: parent.verticalCenter
        anchors.leftMargin: 10

        color: "#FFFFFF"
        font {
            pointSize: 14
        }
    }
}

