import QtQuick 2.0
import QtQuick.Controls 2.0
import QtQuick.Layouts 1.3

Item {
    id: phaseItem
    property alias rectcolor:rect.color
    property alias source: phase.source
    Rectangle {
        id: rect
        color: "#96969b"
        anchors.rightMargin: 0
        anchors.bottomMargin: 0
        anchors.leftMargin: 0
        anchors.topMargin: 0
        anchors.fill: parent

        Image {
            id: phaseE
            x: 0
            y: 50
            width: 118
            height: 102
            fillMode: Image.PreserveAspectFit
            source: "../images/entrada1.1.png"
            Rectangle {
                id: rectE
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
            id: phaseS
            x: 524
            y: 50
            width: 116
            height: 102
            fillMode: Image.PreserveAspectFit
            source: "../images/salida1.1.png"
            Rectangle {
                id: rectS
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

    Image {
        id: phaseR
        x: 265
        y: 245
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
        x: 161
        y: 44
        width: 44
        height: 50
        fillMode: Image.PreserveAspectFit
        source: "../images/product2.png"
    }
    Image {
        id: phaseC
        x: 389
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
        width: 405
        height: 71
        anchors.horizontalCenter: parent.horizontalCenter
        fillMode: Image.PreserveAspectFit
        source: "../images/banda1.1.png"
    }

    Image {
        id: bgrande
        x: 22
        y: 100
        width: 407
        height: 62
        anchors.horizontalCenterOffset: 1
        anchors.horizontalCenter: parent.horizontalCenter
        fillMode: Image.PreserveAspectFit
        source: "../images/banda1.1.png"
    }
//    states : [
//        State{
//            name:'apagadoR'
//            PropertyChanges {
//                target: rectR
//                color: "#ba0505"
//            }
//            PropertyChanges {
//                target: phaseR
//                source: "../images/repair3.1.png"

//            }
//        },
//        State{
//            name:'apagadoC'
//            PropertyChanges {
//                target: rectC
//                color: "#ba0505"
//            }
//            PropertyChanges {
//                target: phaseC
//                source: "../images/check2.1.png"

//            }
//        },
//        State{
//            name:'apagadoP'
//            PropertyChanges {

//            }
//        },
//        State{
//            name:'apagadoE'
//            PropertyChanges {
//                target: rectE
//                color: "#ba0505"
//            }
//            PropertyChanges {
//                target: phaseE
//                source: "../images/entrada1.2.png"

//            }
//        },
//        State{
//            name:'apagadoS'
//            PropertyChanges {
//                target: rectS
//                color: "#ba0505"
//            }
//            PropertyChanges {
//                target: phaseS
//                source: "../images/salida1.2.png"

//            }
//        }
//    ]
}
