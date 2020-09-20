#pragma once

#include <string>
#include <unordered_map>

#include "FarLight/Abstraction/Singleton/Singleton.h"

#include "FarLight/Core/Core.h"

namespace FarLight
{
    /* Core directories
    * Root - Current project directory
    * Settings - Settings directory
    * */

    class FileSystem final
        : public Singleton<FileSystem>
    {
        friend class Singleton<FileSystem>;

    public:
        bool IsFileExists(const std::string& name) const noexcept;
        bool IsFilePathExists(const std::string& path) const noexcept;
        void CreateEmptyFile(const std::string& name, const std::string& path) noexcept;

        const std::string& GetFile(const std::string& name) const noexcept;
        void SetFile(const std::string& name, const std::string& path, bool createEmpty = false) noexcept;

        bool IsDirectoryExists(const std::string& name) const noexcept;
        bool IsDirectoryPathExists(const std::string& path) const noexcept;
        void CreateEmptyDirectory(const std::string& name, const std::string& path) noexcept;

        const std::string& GetDirectory(const std::string& name) const noexcept;
        void SetDirectory(const std::string& name, const std::string& path, bool createEmpty = false) noexcept;

    private:
        explicit FileSystem() noexcept;

        mutable std::unordered_map<std::string, std::string> m_DirectoriesMap;
        mutable std::unordered_map<std::string, std::string> m_FilesMap;
    };
}
