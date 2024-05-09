import QtQuick 2.15
import QtQuick.Window 2.15
import QtQuick.Controls 2.15
import QtQuick.Layouts 2.15


Window {
    property int mWidth: 200
    property int mHeight: 200

    width: mWidth
    height: mHeight
    minimumWidth: mWidth
    minimumHeight: mHeight
    maximumWidth: mWidth
    maximumHeight: mHeight
    visible: true
    title: "Hello World"

    ColumnLayout {
        anchors.fill: parent
        spacing: 2

        Label {
            text: "Wifi"
            Layout.alignment: Qt.AlignHCenter
        }

        ComboBox {
            id: comboBox
            model: client.wifiList
            Layout.alignment: Qt.AlignHCenter
        }

        Label {
            text: "Password"
            Layout.alignment: Qt.AlignHCenter
        }

        TextField {
            id: textField
            placeholderText: "Insert password"
            echoMode: TextInput.Password
            Layout.alignment: Qt.AlignHCenter
            Keys.onEnterPressed: client.buttonPressed(comboBox.currentText, textField.text)
        }

        Button {
            text: "Confirm"
            onClicked: client.buttonPressed(comboBox.currentText, textField.text)
            Layout.alignment: Qt.AlignHCenter
        }


        Rectangle {
            width: 100
            height: 50
            Layout.alignment: Qt.AlignHCenter

            function translateWifiStatus(statusInt) {
                console.log("Hello world!!");
                console.log(statusInt);
                var statusString;
                switch(statusInt) {
                case 0:
                    statusString = "grey"; //"Init";
                    break;
                case 1:
                    statusString = "green"; //"Success";
                    break;
                case 2:
                    statusString = "red"; //"Failed";
                    break;
                default:
                    statusString = "blue"; //"None";
                }

                return statusString;
            }

            color: translateWifiStatus(client.wifiStatusMap[comboBox.currentText])
        }
    }
}
