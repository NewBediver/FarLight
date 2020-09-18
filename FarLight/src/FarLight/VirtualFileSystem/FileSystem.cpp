#include "flpch.h"
#include "FileSystem.h"

#include "FarLight/VirtualFileSystem/FileType.h"


#include "FarLight/ResourceSystem/Resources/ShaderLibrary.h"

#include <boost/filesystem.hpp>
#include <boost/uuid/random_generator.hpp>

namespace FarLight
{
    FileSystem::FileSystem() noexcept
    {
        m_DirectoriesMap["Root"] = boost::filesystem::current_path().string();

        m_DirectoriesMap["Settings"] = m_DirectoriesMap["Root"] + "\\Settings";
        if (!IsDirectoryExists("Settings")) CreateEmptyDirectory("Settings", m_DirectoriesMap["Root"] + "\\Settings");

        m_FilesMap["GlobalSettings"] = m_DirectoriesMap["Settings"] + "\\GlobalSettings.cfg";
        if (!IsFileExists("GlobalSettings")) CreateEmptyFile("GlobalSettings", m_DirectoriesMap["Settings"] + "\\GlobalSettings.cfg");
            
        Settings settings(m_FilesMap["GlobalSettings"]);
        ReconstructDirectory("Assets", "Directories.Assets", settings);
        ReconstructDirectory("Shaders", "Directories.Shaders", settings);
        ReconstructDirectory("Editor", "Directories.Editor", settings);
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

    void FileSystem::CreateEmptyDirectory(const std::string& name, const std::string& path) noexcept
    {
        boost::filesystem::create_directory(path);
        m_DirectoriesMap[name] = path;
    }

    const std::string& FileSystem::GetDirectory(const std::string& name) const noexcept
    {
        FL_CORE_ASSERT(IsDirectoryExists(name), "Current directory doest exists!");
        return m_DirectoriesMap.at(name);
    }

    void FileSystem::ReconstructDirectory(const std::string& name, const std::string& option, Settings& settings)
    {
        if (settings.HasOption<std::string>(option))
        {
            std::string path = settings.GetValue<std::string>(option);
            m_DirectoriesMap[name] = path;
            if (!IsDirectoryExists(name))
            {
                CreateEmptyDirectory(name, path);
            }
        }
        else
        {
            CreateEmptyDirectory(name, m_DirectoriesMap["Root"] + "\\" + name);
            settings.SetValue(option, m_DirectoriesMap[name]);
        }
    }
}


