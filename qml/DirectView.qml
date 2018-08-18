import QtQuick 2.9
import QtQuick.Layouts 1.3

RowLayout{
    id: root
    Layout.fillWidth: true
    height: 40
    spacing: 5

    property string folderName

    signal selected
    signal doubleClicked(string fileName)

    FolderShape{
        id: folder
        heightSize: parent.height
        onSelected:{
            root.selected();
        }
        onDoubleClicked:{
            root.doubleClicked(directInformation.text);
        }
    }
    Text{
        id: directInformation
        text: qsTr(folderName)
    }
}
