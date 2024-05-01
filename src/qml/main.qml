import QtQuick 2.15
import QtQuick.Window 2.15
import QtQuick.Controls 2.15
import QtQuick.Layouts 2.15


Window {
    width: 640
    height: 480
    visible: true
    title: qsTr("Hello World")

    ColumnLayout {
        spacing: 2

        Label {
            text: "Wifi"
        }

        ComboBox {
            id: comboBox
            model: client.wifiList
        }

        Label {
            text: "Password"
        }

        TextField {
            id: textField
            placeholderText: "Insert password"
        }

        Button {
            text: "Confirm"
            onClicked: client.buttonPressed(comboBox.currentText, textField.text)
        }
    }
}
