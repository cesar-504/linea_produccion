import QtQuick 2.0
import QtQuick.Controls 2.0
import QtQuick.Layouts 1.3
Item {
    property int station : 0
    id: item1
    Rectangle{
        color: "#575656"
    anchors.fill: parent
 }
    Station {
        anchors.bottom: parent.bottom
        anchors.bottomMargin: parent.height/3
        anchors.right: parent.right
        anchors.rightMargin:  parent.width/12
        anchors.left: parent.left
        anchors.leftMargin:  parent.width/12
        anchors.top: parent.top
        anchors.topMargin: parent.height/19
        }

}
