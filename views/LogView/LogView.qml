import QtQuick 2.0
import my 1.0

ListView {
    model : app.pl.spmodel
    delegate: IODelegate{

    }
}
