import QtQuick 2.0
import QtQuick.Controls 2.1
import QtQuick.Layouts 1.3
Item {
    id:root
    width: 300
    Repeater{
        model: app.pl.countModel
    Frame{
        topPadding: 40
            anchors.fill: parent
            ColumnLayout {
                id: columnLayout
                anchors.fill: parent

                Item {
                    id: item2
                    width: 6
                    Layout.fillHeight: true
                    Layout.fillWidth: true
                }

                Text {
                    id: text4
                    text: totalOkPr
                    Layout.fillWidth: true
                    font.pointSize: 42
                    font.bold: true
                    horizontalAlignment: Text.AlignHCenter
                }

                Text {
                    id: text1
                    text: qsTr("Productos Producidos")
                    font.pointSize: 20
                    font.bold: true
                    verticalAlignment: Text.AlignVCenter
                    horizontalAlignment: Text.AlignHCenter
                    Layout.alignment: Qt.AlignHCenter | Qt.AlignVCenter
                    Layout.fillWidth: true
                }


                Item {
                    id: item1
                    width: 200
                    height: 200
                    Layout.fillHeight: true
                    Layout.fillWidth: true
                }
                RowLayout {
                    id: rowLayout11
                    width: 100
                    height: 100
                    Layout.fillWidth: true

                    Text {
                        id: text21
                        text: qsTr("Productos Reparados: ")
                        Layout.fillHeight: true
                        font.pointSize: 14
                        Layout.fillWidth: false
                    }

                    Text {
                        id: text51
                        text: totalRepairPr-totalErrorPr
                        horizontalAlignment: Text.AlignRight
                        Layout.fillHeight: true
                        font.pointSize: 14
                        Layout.fillWidth: true
                    }
                }


                RowLayout {
                    id: rowLayout
                    width: 100
                    height: 100
                    Layout.fillWidth: true

                    Text {
                        id: text2
                        text: qsTr("Productos Erroneos: ")
                        Layout.fillHeight: true
                        font.pointSize: 14
                        Layout.fillWidth: false
                    }

                    Text {
                        id: text5
                        text: totalErrorPr
                        horizontalAlignment: Text.AlignRight
                        Layout.fillHeight: true
                        font.pointSize: 14
                        Layout.fillWidth: true
                    }
                }

                RowLayout {
                    id: rowLayout1
                    width: 100
                    height: 100
                    Layout.fillWidth: true

                    Text {
                        id: text3
                        text: qsTr("Total: ")
                        horizontalAlignment: Text.AlignLeft
                        font.pointSize: 14
                        Layout.fillWidth: true
                    }

                    Text {
                        id: text6
                        text: totalPr
                        horizontalAlignment: Text.AlignRight
                        font.pointSize: 14
                        Layout.fillWidth: true
                    }
                }

            }








       }

    }



}
