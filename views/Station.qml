import QtQuick 2.0
import QtQuick.Controls 2.0
import QtQuick.Layouts 1.3

Item {
    id: phaseItem
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
            y: bgrande.y-bgrande.height
            width: parent.width/5.4
            height: parent.height/4.4
            anchors.rightMargin: 1
            anchors.right: bgrande.left
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
            y: bgrande.y-bgrande.height
            width: parent.width/5.4 //640
            height: parent.height/4.4 //480
            anchors.left: bgrande.right
            anchors.leftMargin: 0
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

        Image {
            id: phaseR
            y: bchica.y + bchica.height+ phaseP.height //640
            //480
            width: parent.width/12
            height: parent.height/10
            anchors.horizontalCenterOffset: 0
            anchors.horizontalCenter: parent.horizontalCenter
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
            x: phaseE.x+phaseE.width
            y: phaseE.y
            width: parent.width/14.5
            height: parent.height/9
            fillMode: Image.PreserveAspectFit
            source: "../images/product2.png"
        }

        Image {
            id: bchica
            x: 117
            width: parent.width/1.6 //640
            height: parent.height/8 //480
            anchors.horizontalCenter: parent.horizontalCenter
            anchors.top: bgrande.bottom
            fillMode: Image.PreserveAspectFit
            source: "../images/banda1.1.png"
        }

        Image {
            id: phaseC
            x: phaseR.x+phaseR.width
            y: bgrande.y-phaseP.height-bgrande.height
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
            id: bgrande
            y: 120
            width: parent.width/1.6 //640
            height: parent.height/8
            anchors.verticalCenter: parent.verticalCenter //480
            anchors.horizontalCenter: parent.horizontalCenter
            fillMode: Image.PreserveAspectFit
            source: "../images/banda1.1.png"
        }
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
