#include <header/BusinessEntities/DirectoryInfo.h>

void DirectoryInfo::setPath(const std::string path)
{
    m_path = path;
}

void DirectoryInfo::setFilesDirectories(const std::vector<std::string> filesDirectories)
{
    m_FilesDirectories.clear();
    m_FilesDirectories = filesDirectories;
}

void DirectoryInfo::setSize(const int size)
{
    m_size = size;
}

void DirectoryInfo::setNumOfFilesDirrectories(const int numOfDirectories)
{
    m_numOfFilesDirectories = numOfDirectories;
}

std::string DirectoryInfo::getPath() const
{
    return m_path;
}

std::vector<std::string> DirectoryInfo::getFilesDirectories() const
{
    return m_FilesDirectories;
}

int DirectoryInfo::getSize() const
{
    return m_size;
}

int DirectoryInfo::getNumOfFilesDirectories() const
{
    return m_numOfFilesDirectories;
}
