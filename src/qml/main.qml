import QtQuick 2.15
import QtQuick.Window 2.15
import QtQuick.Controls 1.2

Window {
    width: 640
    height: 480
    visible: true
    title: qsTr("Hello World")

    ComboBox {
        model: client.wifiList
    }
}
