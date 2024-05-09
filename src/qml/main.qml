import QtQuick 2.15
import QtQuick.Window 2.15
import QtQuick.Controls 2.15
import QtQuick.Layouts 2.15


Window {
    property int mWidth: 200
    property int mHeight: 200

    id: mainWindow
    flags: Qt.FramelessWindowHint
    width: mWidth
    height: mHeight
    minimumWidth: mWidth
    minimumHeight: mHeight
    maximumWidth: mWidth
    maximumHeight: mHeight
    visible: true
    title: "Hello World"

    MouseArea {
        anchors.fill: parent;
        property variant clickPos: "1,1"

        onPressed: {
            clickPos = Qt.point(mouse.x,mouse.y)
        }

        onPositionChanged: {
            var delta = Qt.point(mouse.x-clickPos.x, mouse.y-clickPos.y)
            var new_x = mainWindow.x + delta.x
            var new_y = mainWindow.y + delta.y
            if (new_y <= 0)
                mainWindow.visibility = Window.Maximized
            else
            {
                if (mainWindow.visibility === Window.Maximized)
                    mainWindow.visibility = Window.Windowed
                mainWindow.x = new_x
                mainWindow.y = new_y
            }
        }
    }

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
