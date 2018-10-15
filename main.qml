import QtQuick 2.11
import QtQuick.Window 2.11

Window {
    visible: true
    width: 640
    height: 480
    title: qsTr("Hello World")
    Rectangle {
        id: movie
        anchors.left: parent.left
        anchors.top: parent.top
        width: 100
        height: 100
        color: "red"
        MouseArea {
            anchors.fill: parent
        }
    }
    Rectangle {
        id: subtitle
        anchors.left: parent.left
        anchors.top: movie.bottom
        width: 100
        height: 100
        color: "blue"
    }
    Rectangle {
        id: script
        anchors.left: parent.left
        anchors.top: subtitle.bottom
        width: 100
        height: 100
        color: "green"
    }
    Rectangle {
        anchors.left: parent.left
        anchors.top: script.bottom
        width: parent.width
        height: 400

        Component {
            id: contactDelegate
            Item {
                width: 180; height: 40
                Column {
                    Text { text: '<b>Name:</b> ' + fullName }
                    Text { text: '<b>Number:</b> ' + number }
                }
            }
        }

        ListView {
            anchors.fill: parent
            orientation: ListView.Horizontal
            model: MovieClips {}
            delegate: contactDelegate
            highlight: Rectangle { color: "lightsteelblue"; radius: 5 }
            focus: true
        }
    }
}
