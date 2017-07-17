import QtQuick 2.0
import QtQuick.Layouts 1.3
import QtQuick.Controls 2.2
import QtQuick.Controls.Material 2.1
Item {
    property int value
    Rectangle{
        id: background
        color: "#060511"
        anchors.fill: parent
    }
    RowLayout{
        x: 0
        y: 0
        spacing: 5
        anchors.fill: parent
        ColumnLayout {
            id: columnLayout
            width: 100
            height: 100
            Text{
                color: "#efefef"
                wrapMode: Label.Wrap
                horizontalAlignment: Text.AlignHCenter
                text:"Sistema"
                font.pointSize: 25
                Layout.fillWidth: true
            }
            Button{
                text: "Prender/Apagar"
                Layout.fillWidth: true

            }
        }
    }
}
