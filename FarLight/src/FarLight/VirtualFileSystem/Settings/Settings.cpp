#include "flpch.h"

#include <sstream>

#include "Settings.h"

#include "FarLight/VirtualFileSystem/FileSystem.h"

namespace FarLight
{
    void Settings::SaveFile() noexcept
    {
        std::stringstream ss;
        for (const auto& elm : m_Sections)
        {
            ss << "[" << elm.first << "]" << std::endl;
            const auto& mp = elm.second.GetSettings();
            for (const auto& elm : mp) {
                ss << elm.first << " = " << elm.second << std::endl;
            }
            ss << std::endl;
        }
        FileSystem::GetInstance().WriteToFile(m_PathToFile, ss.str());
    }

    void Settings::ReadFile() noexcept
    {
        std::string fileContent = FileSystem::GetInstance().ReadFromFile(m_PathToFile);
        // TODO: Write parser
    }
}
