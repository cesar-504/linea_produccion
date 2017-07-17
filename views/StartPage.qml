import QtQuick 2.0
import QtQuick.Controls 2.0
import QtQuick.Layouts 1.3
import './LogView'
Page {
    id: item1
    padding: 20
    background: Rectangle{
        color: "#eee"
    }
    ColumnLayout{
        anchors.fill: parent

        RowLayout{
            height: 500
            width:  1200
            LogView{
                width: 300
                height: 480
            }
            Item {
                height: 500
                width:  700
                Station {
                    height: 500
                    width:  700
                }
            }
            CountView{
                height: 500
                width:  300
            }

        }
        RowLayout{
            Layout.fillWidth: true
            Layout.fillHeight: true


        }


    }
}
