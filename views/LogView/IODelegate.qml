import QtQuick 2.0
import QtQuick.Layouts 1.3
import QtQuick.Controls 2.2


ColumnLayout{
    id:root
    implicitHeight: 60
    implicitWidth: 300
    RowLayout {
        Layout.fillHeight: true
        Image {
            id: icon
            Layout.alignment: Qt.AlignHCenter | Qt.AlignVCenter
            sourceSize.height: 32
            sourceSize.width: 32
            Layout.fillHeight: true
            Layout.fillWidth: false
            fillMode: Image.PreserveAspectFit
            source: (action == 1) ? "../../images/arrow_down.png" : "../../images/arrow_up.png"
        }

        Text {
            id: actiontext
            text: (action == 1) ? "Entrada a #" + to : "Salida de #" + from

            verticalAlignment: Text.AlignVCenter
            horizontalAlignment: Text.AlignHCenter
            font.bold: true
            Layout.fillHeight: true
            Layout.fillWidth: true
            font.pixelSize: 12
        }



        Text {
            id: time
            text: timeLog
            verticalAlignment: Text.AlignVCenter
            horizontalAlignment: Text.AlignHCenter
            Layout.fillHeight: true
            Layout.fillWidth: true
            font.pixelSize: 12
        }

    }

    Rectangle {
        anchors.left: parent.left
        anchors.right: parent.right
        width: parent.width
        height: 1
        color: "#bdb0b0"
        opacity: 0.3
    }


}



