import QtQuick

Window {
    id: window
    width: 1280
    height: 720
    visible: true
    title: qsTr("SoundMixer")

    Rectangle {
        anchors.fill: parent
        color: "#333333"


        SoundList {
            anchors.centerIn: parent
            height: parent.height
            width: parent.width / 2
        }

    }

}
