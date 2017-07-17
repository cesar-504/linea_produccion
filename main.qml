import QtQuick 2.7
import QtQuick.Controls 2.0
import QtQuick.Layouts 1.3
import QtQuick.Controls.Material 2.1
import my 1.0
import "./views" as Vi
import "./views/LogView"
ApplicationWindow {
    id:app
    visible: true
    width: 1350
    height: 800
    title: qsTr("Linea de producción")
    header: ToolBar {
        Material.foreground: "#0b146f"
        RowLayout{
            spacing: 20
            anchors.fill: parent

            ToolButton {
                contentItem: Image {
                    fillMode: Image.Pad
                    horizontalAlignment: Image.AlignHCenter
                    verticalAlignment: Image.AlignVCenter
                    source: stackView.depth > 1 ? "../images/back.png" : "../images/drawer.png"
                }
                onClicked: {
                    if (stackView.depth > 1) {
                        stackView.pop()
                        listView.currentIndex = -1
                    } else {
                        drawer.open()
                    }
                }
            }
            Label {
                id: titleLabel
                text: listView.currentItem ? listView.currentItem.text : "Linea de producción"
                font.pixelSize: 20
                elide: Label.ElideRight
                horizontalAlignment: Qt.AlignHCenter
                verticalAlignment: Qt.AlignVCenter
                Layout.fillWidth: true
            }
        }
        Drawer {
            id: drawer
            z:1
            leftPadding: 0
        interactive: stackView.depth === 1
            //  0.26 : 0.56
            width: Math.min(240,  Math.min(parent.width, parent.height) / 3 * 2 )
            height: parent.height

            ListView {
                id: listView
                focus:true
                currentIndex: -1
                anchors.fill: parent

            delegate: ItemDelegate {
                width: parent.width
                text: model.title
                highlighted: ListView.isCurrentItem
                onClicked: {
                    listView.currentIndex = index
                    stackView.push(model.source)
                    drawer.close()
                }
            }
            model: ListModel {
                ListElement { title: "Pantalla principal"; source:"qrc:/views/StartPage.qml"}
                ListElement { title: "Vista de información"; source: "qrc:/views/InfoView.qml"}

            }
            ScrollIndicator.vertical: ScrollIndicator {}
            }

        }
    }

    property alias pl:_pl

    //modelo de la linea de produccion en c++
    // este se actualiza junto con el real
    ProductionLine{
        id:_pl
        spModel: SPLogModel{
            id:spmodel
        }
        sender: TestSender{}
        //Stations c++
        Station{
            idNum: 1
            type: Station.Entry
        }
        Station{
            idNum: 2
            type: Station.Band
        }
        Station{
            idNum: 3
            type: Station.Verification
        }
        Station{
            idNum: 4
            type: Station.Band
        }
        Station{
            idNum: 5
            type: Station.Exit
        }
        //las de abajo
        Station{
            idNum: 6
            type: Station.Band
        }
        Station{
            idNum: 3
            type: Station.Repair
        }
        Station{
            idNum: 4
            type: Station.Band
        }
        Station{
            idNum: 5
            type: Station.ExitError
        }
    }


    StackView {
        id: stackView
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
        initialItem: Vi.StartPage{

        }




    }

}

