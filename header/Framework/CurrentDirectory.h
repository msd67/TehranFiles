#ifndef CURRENTDIRECTORY_H
#define CURRENTDIRECTORY_H

#include <header/stable.h>
#include <header/BusinessRules/DirectoryController.h>
#include <header/BusinessEntities/DirectoryInfo.h>

class CurrentDirectory: public QObject
{
    Q_OBJECT
    Q_PROPERTY(NOTIFY createList)
    Q_PROPERTY(NOTIFY clearList)

public:
    CurrentDirectory(const std::shared_ptr<DirectoryInfo> directoryInfo, std::unique_ptr<DirectoryController> directoryController);
    Q_INVOKABLE QString getFileName() const;
    Q_INVOKABLE QString getDirPath() const;
    Q_INVOKABLE void doubleClick(QString fileName);
    Q_INVOKABLE void singleClick();
    Q_INVOKABLE void upButtonClick();

signals:
    void createList();
    void clearList();

private:
    std::shared_ptr<DirectoryInfo> m_directoryInfo;
    std::unique_ptr<DirectoryController> m_directoryController;
    QString m_dirName = "start";

    void showFolders();

};

#endif
