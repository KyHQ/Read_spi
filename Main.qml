import QtQuick 2.15
import QtQuick.Window 2.15
import QtQuick.Controls 2.15

Window {
    id: root
    width: 640
    height: 480
    visible: true
    title: qsTr("SEND AND RECEIVED DATA")
    Timer {
        id: timer
        interval: 10
        running: true
        repeat: true
        onTriggered: {
            dataManager.updateData()
        }
    }

    property bool error_spi: false

    Button {
        text: "Start trasmit data "
        width: 130
        height: 30
        anchors.topMargin: 100
        onClicked: {
            dataManager.runExecutable()
        }
    }

    Label{
        text: "Data Send"
        width: 300
        height: 200
        anchors.left: parent.left
        anchors.top: data_send.top
        anchors.leftMargin: 50
        anchors.topMargin: 10
    }

    Label{
        text: "Data Received"
        width: 300
        height: 200
        anchors.left: parent.left
        anchors.leftMargin: 50
        anchors.top: data_received.top
        anchors.topMargin: 10

    }

    Text {
        id: data_send
        text: dataManager.masterData
        width: 300
        height: 200
        anchors.top: parent.top
        anchors.horizontalCenter: parent.horizontalCenter
        anchors.topMargin: 50
        font.pixelSize: 24
    }

    Text {
        id: data_received
        text: dataManager.slaveData
        width: 300
        height: 200
        anchors.bottom: parent.bottom
        anchors.horizontalCenter: parent.horizontalCenter
        anchors.bottomMargin: 50
        font.pixelSize: 24
    }



}
