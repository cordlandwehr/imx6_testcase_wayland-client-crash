import QtQuick 2.0

Rectangle {
    width: 400
    height: width
    color: mouseArea.pressed ? "yellow" : "green"

    // do something expensive
    ListView {
        anchors.fill: parent
        model: 1000
        delegate: Rectangle {
            color: "grey"
        }
    }

    MouseArea {
        id: mouseArea
        anchors.fill: parent
        onClicked: gProxy.killLatestWindow();
    }
}
