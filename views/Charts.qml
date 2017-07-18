import QtQuick 2.0
import QtCharts 2.0
import QtQuick.Controls 2.1
import QtQuick.Layouts 1.3
Item {
    Repeater{
        model: app.pl.countModel

    Rectangle{
        id: background
        color: "#060511"
        anchors.fill: parent
     ChartView {
         id: chart
         title:"Productos"
         height: 400
         anchors.verticalCenter: parent.verticalCenter
         anchors.horizontalCenter: parent.horizontalCenter
         width: 500
         legend.alignment: Qt.AlignBottom
        antialiasing: true

        PieSeries {
            id: applepie

            PieSlice { label: "Reparados"; value: totalRepairPr-totalErrorPr; onHovered: { exploded =true; }exploded: false}
            PieSlice { label: "Erroneos"; value: totalErrorPr;onHovered:{ exploded =true} exploded: false }
            PieSlice { label: "Sin errores"; value: totalOkPr-totalRepairPr-totalErrorPr;onHovered: {exploded =true} exploded: false}
            }

     }
}
     Component.onCompleted: {

     }
    }
}
