import QtQuick 2.0
import QtQuick.Controls 2.0
import QtQuick.Layouts 1.3

Item {
    id: phaseItem
    property alias rectcolor:rect.color
    property alias source: phase.source
    Rectangle {
        id: rect
        color: "#adadad"
        anchors.fill: parent
    }

    Image {
        id: phaseR
        x: 384
        y: 223
        width: 41
        height: 52
        fillMode: Image.PreserveAspectFit
        source: "../images/repair3.png"

        Rectangle {
            id: rectR
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
    Image {
        id: phaseP
        x: 38
        y: 44
        width: 44
        height: 50
        fillMode: Image.PreserveAspectFit
        source: "../images/product2.png"
        Rectangle {
            id: rectP
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
    Image {
        id: phaseC
        x: 312
        y: 8
        width: 54
        height: 51
        source: "../images/check2.png"

        Rectangle {
            id: rectC
            width: 10
            height: 10
            color: "#78f478"
            radius: 5
            anchors.top: parent.top
            anchors.topMargin: 0
            anchors.right: parent.right
            anchors.rightMargin: 0
        }
    }
    Image {
        id: bchica
        x: 164
        y: 168
        width: 217
        height: 50
        anchors.horizontalCenter: parent.horizontalCenter
        fillMode: Image.PreserveAspectFit
        source: "../images/banda1.1.png"
    }

    Image {
        id: bgrande
        x: 22
        y: 100
        width: 487
        height: 54
        anchors.horizontalCenter: parent.horizontalCenter
        fillMode: Image.PreserveAspectFit
        source: "../images/banda1.4.png"
    }
    states : [
        State{
            name:'apagadoR'
            PropertyChanges {
                target: rectR
                color: "#ba0505"
            }
            PropertyChanges {
                target: phaseR
                source: "../images/repair3.1.png"

            }
        },
        State{
            name:'apagadoC'
            PropertyChanges {
                target: rectC
                color: "#ba0505"
            }
            PropertyChanges {
                target: phaseC
                source: "../images/repair3.1.png"

            }
        },
        State{
            name:'apagadoP'
            PropertyChanges {
                target: rectP
                color: "#ba0505"
            }
            PropertyChanges {
                target: phaseP
                source: "../images/repair3.1.png"

            }
        }
    ]
}
