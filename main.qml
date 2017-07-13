import QtQuick 2.7
import QtQuick.Controls 2.0
import QtQuick.Layouts 1.3
import my 1.0
ApplicationWindow {
    visible: true
    width: 640
    height: 480
    title: qsTr("Hello World")

    SwipeView {
        id: swipeView
        anchors.fill: parent
        currentIndex: tabBar.currentIndex

        Page1 {
        }

        Page {
            Text {
                   text: list.model.count
                }
            ListView{
                id : list
                anchors.fill: parent
                model: SPLogModel{

                }
                delegate: Text {
                    text: "## " + from +" >> " +to +" "+ timeLog
                }
            }
        }
    }

    footer: TabBar {
        id: tabBar
        currentIndex: swipeView.currentIndex
        TabButton {
            text: qsTr("First")
        }
        TabButton {
            text: qsTr("Second")
        }
    }
}
