import QtQuick 2.9
import QtQuick.Layouts 1.3

Image{
    id: root

    property real heightSize

    signal selected
    signal doubleClicked

    height: heightSize
    width: height
    source: "../image/folder2.png"
    fillMode: Image.PreserveAspectFit
    MouseArea{
        //Layout.fillHeight: true
        //Layout.fillWidth: true
        anchors.fill: parent
        onClicked:{
            root.selected();
        }
        onDoubleClicked:{
            root.doubleClicked();
        }
    }
}
