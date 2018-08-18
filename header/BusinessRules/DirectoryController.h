#ifndef DIRECTORYCONTROLLER_H
#define DIRECTORYCONTROLLER_H

#include <header/BusinessEntities/DirectoryInfo.h>
#include <header/stable.h>

class DirectoryController
{
    private:
    std::shared_ptr<DirectoryInfo> m_directoryInfo;

    public:
    DirectoryController(std::shared_ptr<DirectoryInfo> directoryInfo);
    void doubleClick(std::string fileName);
    void singleClick();
    void rightClick();
    void upButtonClick();
};

#endif
