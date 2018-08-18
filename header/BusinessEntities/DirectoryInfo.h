#ifndef DIRECTORYINFO_H
#define DIRECTORYINFO_H

#include <header/stable.h>

class DirectoryInfo
{
    private:
    std::string m_path = "/home";
    std::vector<std::string> m_FilesDirectories;
    int m_size;
    int m_numOfFilesDirectories;

    public:
    void setPath(const std::string path);
    void setFilesDirectories(const std::vector<std::string> filesDirectories);
    void setSize(const int size);
    void setNumOfFilesDirrectories(const int numOfDirectories);

    std::string getPath() const;
    std::vector<std::string> getFilesDirectories() const;
    int getSize() const;
    int getNumOfFilesDirectories() const;
};

#endif
