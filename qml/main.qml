import QtQuick 2.9
import QtQuick.Window 2.2
import QtQuick.Layouts 1.3
import QtQuick.Controls 2.2

import Tehran.Files 1.0

Window {
    visible: true
    width: 640
    height: 480
    title: qsTr("Hello World")

    property string nameOfFolder

    RowLayout{
        anchors.fill: parent
        spacing: 0
        ColumnLayout{
            id: leftSide
            Layout.maximumWidth: 200
            Layout.minimumWidth: 100
            Layout.fillHeight: true
            Rectangle{
                id: backGround
                Layout.fillHeight: true
                Layout.fillWidth: true
                color: "#AAAAAA"
            }
        }
        ColumnLayout{
            id: rightSideMain
            Layout.fillWidth: true
            Layout.fillHeight: true
            Rectangle{
                id: rct0
                color: "#77333355"
                Layout.fillHeight: true
                Layout.fillWidth: true
                ColumnLayout{
                    id: rightSide
                    Layout.fillHeight: true
                    Layout.fillWidth: true
                    spacing: 10
                    RowLayout{
                        id: topRow
                        height: 30
                        Layout.fillWidth: true
                        Button{
                            id: upFolder
                            text: qsTr("Up");
                            width: 40
                            onClicked:{
                                FileManager.upButtonClick();
                            }
                        }
                        Label{
                            id: currentDirectoryLabel
                            text: qsTr("/home/masoud/ZZ_Test");
                            Layout.fillWidth: true
                        }
                    }
                    FolderList{
                        id: listOfFolders
                        //Layout.fillHeight: true
                        height: 280
                        Layout.fillWidth: true
                        thisFolderName: nameOfFolder
                        onDoubleClicked: {
                            FileManager.doubleClick(fileName);
                        }
                        onSelected: {
                            FileManager.singleClick();
                        }
                    }
                    Connections{
                        target: FileManager
                        onCreateList:{
                            nameOfFolder=FileManager.getFileName();
                            listOfFolders.rowGen();
                        }
                        onClearList:{
                            listOfFolders.rmRows();
                        }
                    }
                }
            }
        }
    }
}
