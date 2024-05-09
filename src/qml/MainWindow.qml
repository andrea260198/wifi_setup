import QtQuick 2.15
import QtQuick.Window 2.15
import QtQuick.Controls 2.15
import QtQuick.Layouts 2.15


Window {
    property int mWidth: 200
    property int mHeight: 250

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
    color: "#6495ED"

    MouseArea {
        anchors.fill: parent;
        property variant clickPos: "1,1"

        onPressed: {
            clickPos = Qt.point(mouseX,mouseY)
        }

        onPositionChanged: {
            var delta = Qt.point(mouseX-clickPos.x, mouseY-clickPos.y)
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
}
