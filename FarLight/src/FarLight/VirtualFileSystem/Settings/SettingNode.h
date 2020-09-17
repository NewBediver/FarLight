#pragma once

#include <string>
#include <map>

namespace FarLight
{
    class SettingNode
    {
    public:
        explicit SettingNode(const std::string& name) noexcept
            : m_Name(name)
        { }

        bool HasKey(const std::string& key) const noexcept;
        const std::string& GetValue(const std::string& key) const noexcept;
        void SetValue(const std::string& key, const std::string& value) noexcept;

        const std::string& GetName() const noexcept { return m_Name; }
        const std::map<std::string, std::string>& GetSettings() const noexcept { return m_SettingMap; }

    private:
        std::string m_Name;
        std::map<std::string, std::string> m_SettingMap;
    };
}
