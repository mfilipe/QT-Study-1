import QtQuick 2.0
import Ubuntu.Components 0.1

MainView {
    id: qtstudyui
    width: units.gu(49)
    height: units.gu(45)

    Label {
        id: title
        text: "QT Pastebin"
        ItemStyle.class: "title"
        anchors {
            top: parent.top
            left: parent.left
            topMargin: units.gu(1)
            leftMargin: units.gu(2)
        }
    }

    TextArea {
        id: content
        width: units.gu(45)
        height: units.gu(30)
        anchors {
            top: title.bottom
            topMargin: units.gu(1)
            left: parent.left
            leftMargin: units.gu(2)
        }
    }

    Row {
        spacing: units.gu(1)

        anchors {
            top: content.bottom
            topMargin: units.gu(1)
            left: parent.left
            leftMargin: units.gu(2)
        }

        Button {
            text: "Paste!"
            onClicked: {
                qpastebin.postToAPI(content.text);
            }
        }

        Button {
            objectName: "buttonClose"
            text: "Close"
            onClicked: {
                qapp.quit();
            }
        }
    }
}
