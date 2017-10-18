import QtQuick 2.0

// Change from `BaseItem` -> `Item` and the issue is not reproducible any more
BaseItem {
    width: 400
    height: 240

    ListModel {
        id: model
        ListElement {
            text: 'something'
        }
    }

    ListView {
        anchors.centerIn: parent
        width: 100
        height: 200

        model: model
        delegate:
            Component {
            Item {
                width: parent.width
                height: parent.height
                Text {
                    text: model.text
                }
            }
        }
    }
}
