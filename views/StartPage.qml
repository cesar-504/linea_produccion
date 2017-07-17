import QtQuick 2.0
import QtQuick.Controls 2.0
import QtQuick.Layouts 1.3
Item {
    id: item1
    Rectangle{
        color: "#575656"
    anchors.fill: parent

    Station {
        id: station
        anchors.centerIn: parent

    }
    ButtonsOnOff{
        anchors.top: station.bottom
        width:500
        height:100
        x:station.x
    }
    }
}
