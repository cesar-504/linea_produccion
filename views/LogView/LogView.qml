import QtQuick 2.0
import my 1.0

ListView {
    ProductionLine{
        id:pl
        spModel: SPLogModel{
            id:spmodel
        }
        sender: TestSender{

        }
    }

    model : spmodel
    delegate: IODelegate{

    }
}
