#include <header/BusinessRules/DirectoryController.h>
#include <QtDebug>

DirectoryController::DirectoryController(std::shared_ptr<DirectoryInfo> directoryInfo)
{
    m_directoryInfo = directoryInfo;
}

void DirectoryController::doubleClick(std::string fileName)
{
    m_directoryInfo->setPath(fileName);
    qDebug()<<"--------";
    qDebug()<<fileName.c_str();
    qDebug()<<"^^^^^^^^";
    namespace fs = std::experimental::filesystem;
    std::vector<std::string> setDir;
    for(auto& p: fs::directory_iterator(m_directoryInfo->getPath())){
        setDir.push_back(p.path());
    }
    m_directoryInfo->setFilesDirectories(setDir);
}

void DirectoryController::singleClick()
{

}

void DirectoryController::rightClick()
{

}

void DirectoryController::upButtonClick()
{

}
