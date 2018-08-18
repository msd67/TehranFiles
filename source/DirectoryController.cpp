#include <header/BusinessRules/DirectoryController.h>
#include <QtDebug>

void DirectoryController::updateFilesDirectories()
{
    namespace fs = std::experimental::filesystem;
    std::vector<std::string> setDir;
    for(auto& p: fs::directory_iterator(m_directoryInfo->getPath())){
        setDir.push_back(p.path().filename());
    }
    m_directoryInfo->setFilesDirectories(setDir);
}

DirectoryController::DirectoryController(std::shared_ptr<DirectoryInfo> directoryInfo)
{
    m_directoryInfo = directoryInfo;
}

void DirectoryController::doubleClick(std::string fileName)
{
    m_directoryInfo->setParent(fileName);
    std::string comPath = m_directoryInfo->getPath() + "/" + fileName;
    m_directoryInfo->setPath(comPath);
    qDebug()<<comPath.c_str();
    qDebug()<<fileName.c_str();
    updateFilesDirectories();
}

void DirectoryController::singleClick()
{

}

void DirectoryController::rightClick()
{

}

void DirectoryController::upButtonClick()
{
    std::string upDirectory = m_directoryInfo->getPath();
    std::string parentDir = m_directoryInfo->getParent();
    int pathLength = static_cast<int>(upDirectory.length());
    int parentLength = static_cast<int>(parentDir.length());
    int offset = pathLength - parentLength - 1;
    upDirectory.erase(offset, parentLength + 1);
    pathLength = static_cast<int>(upDirectory.length());
    int temp = 0;
    m_directoryInfo->setPath(upDirectory);
    std::string newParent = "";
    for(int i=0; i<pathLength; i++){
        temp = i;
        if(upDirectory[pathLength - i - 1]=='/') break;
        if(i==0)
            newParent = upDirectory[pathLength - i - 1];
        else
            newParent = upDirectory[pathLength - i - 1] + newParent;
    }
    m_directoryInfo->setParent(newParent);
    updateFilesDirectories();

}
