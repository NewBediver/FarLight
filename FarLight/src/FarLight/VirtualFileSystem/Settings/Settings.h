#pragma once

#include <string>
#include <map>

#include "FarLight/VirtualFileSystem/Settings/SettingNode.h"

namespace FarLight
{
    class Settings
    {
    public:
        explicit Settings(const std::string& pathToFile) noexcept
            : m_PathToFile(pathToFile)
        { }

        const std::string& GetPath() const noexcept { return m_PathToFile; }

        void SaveFile() noexcept;
        void ReadFile() noexcept;



    private:
        std::string m_PathToFile;

        std::map<std::string, SettingNode> m_Sections;
    };
}
