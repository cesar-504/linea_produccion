import QtQuick 2.0
import QtQuick.Controls 2.0
import QtQuick.Layouts 1.3
Item {
    property var station : 0

    id: item1
    Rectangle {
        id: rect1
        color: "#adadad"
        anchors.bottom: parent.bottom
        anchors.bottomMargin: parent.height/3
        anchors.right: parent.right
        anchors.rightMargin:  parent.width/12
        anchors.left: parent.left
        anchors.leftMargin:  parent.width/12
        anchors.top: parent.top
        anchors.topMargin: parent.height/19

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

        Image {
            id: prod
            x: 38
            y: 44
            width: 44
            height: 50
            fillMode: Image.PreserveAspectFit
            source: "../images/product2.png"
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
                id: rectangle1
                x: 0
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
                id: rectangle
                x: 0
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
    }

}
