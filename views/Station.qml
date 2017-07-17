import QtQuick 2.0
import QtQuick.Controls 2.0
import QtQuick.Layouts 1.3


Rectangle {
    id: rect
    color: "#96969b"
    height: 500
    width:  700
    Image {
        id: phaseE
        x: 0
        y: 100
        width: 135
        height: 122
        fillMode: Image.PreserveAspectFit
        source: "../images/entrada1.1.png"
        OnPoint{}
    }

    Image {
        id: bgrande
        x: 141
        y: 144
        width: 398
        height: 100

        fillMode: Image.PreserveAspectFit
        source: "../images/banda1.1.png"
    }

    Image {
        id: phaseC
        x: 403
        y: 58
        width: 75
        height: 75
        source: "../images/check2.png"

        OnPoint{}
    }

    Image {
        id: phaseS
        x: 545
        y: 100
        width: 132
        height: 122
        fillMode: Image.PreserveAspectFit
        source: "../images/salida1.1.png"
        OnPoint{}
    }

    Image {
        id: bchica
        x: 141
        y: 240
        width: 398
        height: 56
        fillMode: Image.PreserveAspectFit
        source: "../images/banda1.1.png"
    }

    Image {
        id: phaseR
        x: 233
        y: 338
        width: 75
        height: 75
        fillMode: Image.PreserveAspectFit
        source: "../images/repair3.png"

        OnPoint{}
    }


    Repeater{
        model: app.pl.products
        Image {
            id: phaseP
            width: 40
            height: 40
            fillMode: Image.PreserveAspectFit
            source: "../images/product2.png"
        }
    }



    Item {
        id: points
        anchors.rightMargin: 0
        anchors.bottomMargin: 0
        anchors.leftMargin: 0
        anchors.topMargin: 0
        anchors.fill: parent

        Image {
            id: p1
            x: 8
            y: 134
            width: 40
            height: 40
            fillMode: Image.PreserveAspectFit
            source: "../images/product2.png"
            Component.onCompleted: visible=false;

        }

        Image {
            id: p9
            x: 8
            y: 291
            width: 40
            height: 40
            fillMode: Image.PreserveAspectFit
            source: "../images/product2.png"
            Component.onCompleted: visible=false;
        }

        Image {
            id: p8
            x: 141
            y: 291
            width: 40
            height: 40
            fillMode: Image.PreserveAspectFit
            source: "../images/product2.png"
            Component.onCompleted: visible=false;
        }

        Image {
            id: p7
            x: 248
            y: 291
            width: 40
            height: 40
            fillMode: Image.PreserveAspectFit
            source: "../images/product2.png"
            Component.onCompleted: visible=false;
        }

        Image {
            id: p6
            x: 418
            y: 291
            width: 40
            height: 40
            fillMode: Image.PreserveAspectFit
            source: "../images/product2.png"
            Component.onCompleted: visible=false;
        }

        Image {
            id: p5
            x: 625
            y: 134
            width: 40
            height: 40
            fillMode: Image.PreserveAspectFit
            source: "../images/product2.png"
            Component.onCompleted: visible=false;
        }

        Image {
            id: p4
            x: 494
            y: 134
            width: 40
            height: 40
            fillMode: Image.PreserveAspectFit
            source: "../images/product2.png"
            Component.onCompleted: visible=false;
        }

        Image {
            id: p3
            x: 418
            y: 134
            width: 40
            height: 40
            fillMode: Image.PreserveAspectFit
            source: "../images/product2.png"
            Component.onCompleted: visible=false;
        }

        Image {
            id: p2
            x: 248
            y: 134
            width: 40
            height: 40
            fillMode: Image.PreserveAspectFit
            source: "../images/product2.png"
            Component.onCompleted: visible=false;
        }
    }

    Component.onCompleted: {
        console.log("________________________________________")
        console.log(points.children[8].source)
    }

}


