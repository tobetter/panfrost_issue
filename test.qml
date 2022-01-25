import QtQuick 2.0


Item {
    width: 1920
    height: 1080
    focus: true
    Image {
        id: img
        source: "NumbersGrid.png"
        onScaleChanged: console.log(scale)
    }
    Keys.onLeftPressed: {
        if (img.scale > 1)
            img.scale -= 1;
    }
    Keys.onRightPressed: {
        img.scale += 1;
    }
    Text {
        font.pointSize: 40
        font.bold: true
        anchors.centerIn: parent
        text: "Scale : " + img.scale
    }

}
