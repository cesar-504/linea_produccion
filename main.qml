import QtQuick 2.7
import QtQuick.Controls 2.0
import QtQuick.Layouts 1.3
import my 1.0
import "./views" as Vi
import "./views/LogView"
ApplicationWindow {
    id:app
    visible: true
    width: 1300
    height: 800
    title: qsTr("Linea de producción")
//
    property bool isLandscape: width > height
    property bool isSmallDevice: !isLandscape && width < 360
    property alias pl:_pl

    //modelo de la linea de produccion en c++
    // este se actualiza junto con el real
    ProductionLine{
        id:_pl
        spModel: SPLogModel{
            id:spmodel
        }
        sender: TestSender{}
        //Stations c++
        Station{
            idNum: 1
            type: Station.Entry
        }
        Station{
            idNum: 2
            type: Station.Band
        }
        Station{
            idNum: 3
            type: Station.Verification
        }
        Station{
            idNum: 4
            type: Station.Band
        }
        Station{
            idNum: 5
            type: Station.Exit
        }
        //las de abajo
        Station{
            idNum: 6
            type: Station.Band
        }
        Station{
            idNum: 3
            type: Station.Repair
        }
        Station{
            idNum: 4
            type: Station.Band
        }
        Station{
            idNum: 5
            type: Station.ExitError
        }
    }


    StackView {
        id: swipeView
        anchors.fill: parent
        //currentIndex: tabBar.currentIndex

        replaceEnter: Transition{
            PropertyAnimation{
                property: "opacity"
                from:0
                to:1
                duration: 300

            }
        }
        replaceExit: Transition {
            PropertyAnimation{
                property: "opacity"
                from:1
                to:0
                duration:300
            }

        }
        initialItem: Vi.StartPage{

        }




    }

}

