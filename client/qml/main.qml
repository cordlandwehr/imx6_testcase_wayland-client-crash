import QtQuick 2.0

Rectangle {
    width: 800
    height: width
    color: "red"

    MouseArea {
        anchors.fill: parent
        onClicked: gProxy.spawnWindow();
    }
}
