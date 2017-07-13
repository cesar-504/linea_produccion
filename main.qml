import QtQuick 2.7
import QtQuick.Controls 2.0
import QtQuick.Layouts 1.3
import my 1.0
ApplicationWindow {
    visible: true
    width: 640
    height: 480
    title: qsTr("Linea de producción")
//
    property bool isLandscape: width > height
    property bool isSmallDevice: !isLandscape && width < 360

    StackView {
        id: swipeView
        anchors.fill: parent
        //currentIndex: tabBar.currentIndex

        replaceEnter: Transition{
            PropertyAnimation{
                property: "opacity"
                from:0
                to:1
                duration: 300

            }
        }
        replaceExit: Transition {
            PropertyAnimation{
                property: "opacity"
                from:1
                to:0
                duration:300
            }

        }

    }

//    footer: TabBar {
//        id: tabBar
//        currentIndex: swipeView.currentIndex
//        TabButton {
//            text: qsTr("First")
//        }
//        TabButton {
//            text: qsTr("Second")
//        }
//    }
}
