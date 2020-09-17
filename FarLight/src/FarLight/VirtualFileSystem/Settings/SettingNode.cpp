#include "flpch.h"

#include "FarLight/VirtualFileSystem/Settings/SettingNode.h"

#include "FarLight/Core/Core.h"

namespace FarLight
{
    bool SettingNode::HasKey(const std::string& key) const noexcept
    {
        return m_SettingMap.find(key) != m_SettingMap.end();
    }

    const std::string& SettingNode::GetValue(const std::string& key) const noexcept
    {
        FL_ASSERT(HasKey(key), "This setting does't exist in current section!");
        return m_SettingMap.at(key);
    }

    void SettingNode::SetValue(const std::string& key, const std::string& value) noexcept
    {
        m_SettingMap[key] = value + ";\n";
    }
}
