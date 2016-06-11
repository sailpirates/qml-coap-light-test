import QtQuick 2.4
import QtQuick.Window 2.2

Window {
    Rectangle {
        color: "black"
        anchors.fill: parent
    }

    visible: true

    width: 500
    height: 500



    Text {
        id: rootText
        objectName: "textObject"
        property string light: "0"
        text: qsTr("Hello, light: ")+light
        anchors.centerIn: parent
    }

    Image {
        anchors.fill: parent
        id: imageOff
        fillMode: Image.PreserveAspectFit
        source: "coap_off.png"
    }

    Image {
        anchors.fill: parent
        id: imageOn
        fillMode: Image.PreserveAspectFit
        source: "coap_on.png"
        visible: (parseInt(rootText.light[7]) % 2)
    }

    MouseArea {
        anchors.fill: parent
        onClicked: {
            Qt.quit();
        }
    }


}
