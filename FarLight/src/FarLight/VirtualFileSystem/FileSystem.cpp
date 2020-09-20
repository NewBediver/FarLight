// This is an open source non-commercial project. Dear PVS-Studio, please check it.
// PVS-Studio Static Code Analyzer for C, C++ and C#: http://www.viva64.com

#include "flpch.h"

#include "FarLight/VirtualFileSystem/FileSystem.h"

#include <boost/filesystem.hpp>
#include <boost/uuid/random_generator.hpp>

namespace FarLight
{
    FileSystem::FileSystem() noexcept
    {
        m_DirectoriesMap["Root"] = boost::filesystem::current_path().string();

        m_DirectoriesMap["Settings"] = m_DirectoriesMap["Root"] + "\\Settings";
        SetDirectory("Settings", m_DirectoriesMap["Root"] + "\\Settings");
    }

    bool FileSystem::IsFileExists(const std::string& name) const noexcept
    {
        if (m_FilesMap.find(name) == m_FilesMap.end()) return false;
        else if (!boost::filesystem::exists(m_FilesMap[name]) || !boost::filesystem::is_regular_file(m_FilesMap[name]))
        {
            m_FilesMap.erase(name);
            return false;
        }
        return true;
    }

    bool FileSystem::IsFilePathExists(const std::string& path) const noexcept
    {
        if (!boost::filesystem::exists(path) || !boost::filesystem::is_regular_file(path)) return false;
        else return true;
    }

    void FileSystem::CreateEmptyFile(const std::string& name, const std::string& path) noexcept
    {
        std::ofstream ofs(path);
        m_FilesMap[name] = path;
    }

    const std::string& FileSystem::GetFile(const std::string& name) const noexcept
    {
        FL_CORE_ASSERT(IsFileExists(name), "Current file doest exists!");
        return m_FilesMap.at(name);
    }

    void FileSystem::SetFile(const std::string& name, const std::string& path, bool createEmpty) noexcept
    {
        if (createEmpty || !IsFilePathExists(path))
            CreateEmptyFile(name, path);
        else
            m_FilesMap[name] = path;
    }

    bool FileSystem::IsDirectoryExists(const std::string& name) const noexcept
    {
        if (m_DirectoriesMap.find(name) == m_DirectoriesMap.end()) return false;
        else if (!boost::filesystem::exists(m_DirectoriesMap[name]) || !boost::filesystem::is_directory(m_DirectoriesMap[name]))
        {
            m_DirectoriesMap.erase(name);
            return false;
        }
        return true;
    }

    bool FileSystem::IsDirectoryPathExists(const std::string& path) const noexcept
    {
        if (!boost::filesystem::exists(path) || !boost::filesystem::is_directory(path)) return false;
        else return true;
    }

    void FileSystem::CreateEmptyDirectory(const std::string& name, const std::string& path) noexcept
    {
        if (boost::filesystem::exists(path) && boost::filesystem::is_directory(path))
            boost::filesystem::remove_all(path);
        boost::filesystem::create_directory(path);
        m_DirectoriesMap[name] = path;
    }

    const std::string& FileSystem::GetDirectory(const std::string& name) const noexcept
    {
        FL_CORE_ASSERT(IsDirectoryExists(name), "Current directory doest exists!");
        return m_DirectoriesMap.at(name);
    }

    void FileSystem::SetDirectory(const std::string& name, const std::string& path, bool createEmpty) noexcept
    {
        if (createEmpty || !IsDirectoryPathExists(path))
            CreateEmptyDirectory(name, path);
        else
            m_DirectoriesMap[name] = path;
    }
}
