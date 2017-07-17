import QtQuick 2.0
import QtQuick.Controls 2.0
import QtQuick.Layouts 1.3
Item {
    id: item1
    Rectangle{
        color: "#575656"
    anchors.fill: parent

    Station {
        anchors.centerIn: parent

    }
    InfoView{
    }
    }
}
