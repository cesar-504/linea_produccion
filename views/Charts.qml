import QtQuick 2.0
import QtCharts 2.0
import QtQuick.Controls 2.1
import QtQuick.Layouts 1.3
Item {

    Rectangle{
        id: background
        color: "#060511"
        anchors.fill: parent
     ChartView {
         title:"Productos"
         height: 300
         anchors.verticalCenter: parent.verticalCenter
         anchors.horizontalCenter: parent.horizontalCenter
         width: 400
        antialiasing: true

        LineSeries {
            name: "aprobados/rechazados"
            Repeater {
                model:app.pl.countModel
                XYPoint { x: 5; y: 7 }

            }
        }
     }
     function granttpoints()
     {

     }
    }
}
