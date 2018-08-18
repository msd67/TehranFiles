import QtQuick 2.9
import QtQuick.Layouts 1.3
import QtQuick.Controls 2.2
import QtQuick.Dialogs 1.1

Item{
    id: root

    property string thisFolderName

    signal selected
    signal doubleClicked(string fileName)

    ListModel{
        id: listModeling
    }

    function rowGen(){
        listModeling.append({nameFolder: thisFolderName});
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
		}
        highlightFollowsCurrentItem: false

        delegate: DirectView{
            id: viewFormat
            folderName: nameFolder
            onSelected:{
                root.selected();
                directotyList.currentIndex = index;
            }
            onDoubleClicked:{
                root.doubleClicked(fileName);
            }
        }

        ScrollIndicator.horizontal: ScrollIndicator { }
		ScrollIndicator.vertical: ScrollIndicator{ }
    }
}
