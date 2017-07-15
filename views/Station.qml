import QtQuick 2.0
import QtQuick.Controls 2.0
import QtQuick.Layouts 1.3

Item {
        property alias rectcolor:rect.color
        property alias source: phase.source

    Image {
        id: phase
        x: 384
        y: 223
        width: 41
        height: 52
        fillMode: Image.PreserveAspectFit
        source: "../images/repair3.png"

        Rectangle {
            id: rect
            width: 10
            height: 10
            color: "#78f478"
            radius: 5
            anchors.right: parent.right
            anchors.top: parent.top
            anchors.topMargin: 0
            anchors.rightMargin: 0
        }
    }
}
