#include <header/Framework/CurrentDirectory.h>
#include <QtDebug>

CurrentDirectory::CurrentDirectory(const std::shared_ptr<DirectoryInfo> directoryInfo, std::unique_ptr<DirectoryController> directoryController)
{
    m_directoryInfo = directoryInfo;
    m_directoryController = std::move(directoryController);
}

QString CurrentDirectory::getFileName() const
{
    return m_dirName;
}

void CurrentDirectory::doubleClick(QString fileName)
{
    std::string nameOfFile = fileName.toLocal8Bit().constData();
    m_directoryController->doubleClick(nameOfFile);
    qDebug()<<nameOfFile.c_str();
    showFolders();
}

void CurrentDirectory::singleClick()
{

}

void CurrentDirectory::upButtonClick()
{
    m_directoryController->upButtonClick();
    doubleClick("/");
}

void CurrentDirectory::showFolders()
{
    std::vector<std::string> dirName = m_directoryInfo->getFilesDirectories();
    emit clearList();
    for(auto& p: dirName){
        m_dirName = p.c_str();
        emit createList();
        qDebug()<<p.c_str();
    }
}
