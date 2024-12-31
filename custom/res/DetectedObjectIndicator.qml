
import QtQuick          2.3
import QtLocation       5.3
import QtQuick.Controls 1.2

import QGroundControl.ScreenTools   1.0
import QGroundControl.Controls      1.0
import QGroundControl.Vehicle       1.0

MapQuickItem {
    property var customMapObject
    coordinate: customMapObject.coordinate
    anchorPoint.x:  sourceItem.width / 2
    anchorPoint.y:  sourceItem.height / 2

    sourceItem: Rectangle {
        width:      _radius * 2
        height:     _radius * 2
        radius:     _radius
        color:      "blue"
        opacity:    0.6

        readonly property real _radius: ScreenTools.defaultFontPixelHeight * 0.7

        MouseArea {
            id: hoverArea
            anchors.fill: parent
            hoverEnabled: true

            onEntered: label.visible = true
            onExited: label.visible = false
        }
        Rectangle {
            id: label
            color: "white"
            border.color: "black"
            radius: 4
            visible: false
            width: labelText.width
            height: labelText.height
            anchors.left: parent.right
            anchors.verticalCenter: parent.verticalCenter
            Label {
                id: labelText
                text: customMapObject.name
                color: "black"
                font.pixelSize: ScreenTools.defaultFontPixelHeight
                padding: 3
            }
        }
    }
}