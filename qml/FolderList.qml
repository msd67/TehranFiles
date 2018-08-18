import QtQuick 2.9
import QtQuick.Layouts 1.3
import QtQuick.Controls 2.2
import QtQuick.Dialogs 1.1

Item{
    id: root
    Layout.fillHeight: true
    Layout.fillWidth: true

    property string thisFolderName
    property bool highlightVisible

    signal selected
    signal doubleClicked(string fileName)

    ListModel{
        id: listModeling
    }

    function rowGen(){
        highlightVisible = false;
        listModeling.append({nameFolder: thisFolderName});
        //console.log("===> ", thisFolderName);
    }
    function rmRows(){
        listModeling.clear();
    }

    ListView{
        id: directotyList
		clip: true
		cacheBuffer: 100
		contentWidth: root.width
		anchors.fill: parent
		flickableDirection: Flickable.VerticalFlick
		headerPositioning: ListView.OverlayHeader
		model: listModeling
        spacing: 5

        highlight: Rectangle {
			width: directotyList.width
			height: 42
			z: 2
			color: "#443333EE"
            y: directotyList.currentItem.y
            visible: highlightVisible
		}
        highlightFollowsCurrentItem: false

        delegate: DirectView{
            id: viewFormat
            folderName: nameFolder
            onSelected:{
                root.selected();
                directotyList.currentIndex = index;
                highlightVisible = true;
            }
            onDoubleClicked:{
                root.doubleClicked(fileName);
            }
        }

        ScrollIndicator.horizontal: ScrollIndicator { }
		ScrollIndicator.vertical: ScrollIndicator{ }
    }
}
