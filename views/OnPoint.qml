import QtQuick 2.0

Rectangle {
    property bool  isOn: false
    id: rectE
    width: 10
    height: 10
    color: isOn? "#78f478" :"red"
    radius: 5
    anchors.right: parent.right
    anchors.top: parent.top
    anchors.topMargin: 0
    anchors.rightMargin: 0

}
