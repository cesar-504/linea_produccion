import QtQuick 2.0
import QtQuick.Controls 2.0
import QtQuick.Layouts 1.3
Item {
    property int station : 0
    id: item1
    Rectangle{
        color: "#575656"
    anchors.fill: parent

    Station {
        id: station
        anchors.bottom: parent.bottom
        anchors.bottomMargin: parent.height/3.4
        anchors.right: parent.right
        anchors.rightMargin:  parent.width/12
        anchors.left: parent.left
        anchors.leftMargin:  parent.width/12
        anchors.top: parent.top
        anchors.topMargin: parent.height/19
    }
    InfoView{
        x: 34
        y: 291
        width: 573
        height: 174
        anchors.top: station.bottom
        anchors.topMargin: 9
        anchors.right: parent.right
        anchors.rightMargin:  parent.width/12
        anchors.left: parent.left
        anchors.leftMargin:  parent.width/12
    }
    }
}
