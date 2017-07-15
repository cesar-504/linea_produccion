import QtQuick 2.0
import QtQuick.Layouts 1.3

RowLayout {
    id:root
    width: 250
    height: 60
    implicitHeight: 60
    implicitWidth: 250
    Image {
        id: icon
        sourceSize.height: 60
        sourceSize.width: 60
        Layout.fillHeight: true
        Layout.fillWidth: false
        fillMode: Image.PreserveAspectFit
        source: "../../images/icon-arrow.png"
    }

    Text {
        id: actiontext
        text: qsTr("Producto 1")
        verticalAlignment: Text.AlignVCenter
        horizontalAlignment: Text.AlignHCenter
        font.bold: true
        Layout.fillHeight: true
        Layout.fillWidth: true
        font.pixelSize: 12
    }

    Text {
        id: time
        text: qsTr("12:00")
        verticalAlignment: Text.AlignVCenter
        horizontalAlignment: Text.AlignHCenter
        Layout.fillHeight: true
        Layout.fillWidth: true
        font.pixelSize: 12
    }

}
