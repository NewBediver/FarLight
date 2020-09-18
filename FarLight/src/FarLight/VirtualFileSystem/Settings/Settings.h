#pragma once

#include <string>

#include <boost/property_tree/ptree.hpp>

namespace FarLight
{
    class Settings final
    {
    public:
        explicit Settings(const std::string& pathToFile) noexcept;
        ~Settings() noexcept;

        void Save() noexcept;
        void Load() noexcept;

        template<typename T>
        bool HasOption(const std::string& key) const noexcept
        {
            bool isContain = true;
            try
            {
                m_PropertyTree.get<T>(key);
            }
            catch (...)
            {
                isContain = false;
            }
            return isContain;
        }

        template<typename T>
        T GetValue(const std::string& key) const noexcept
        {
            FL_ASSERT(HasOption<T>(key), "Current settings tree doesn't contain this option!");
            return m_PropertyTree.get<T>(key);
        }

        template<typename T>
        void SetValue(const std::string& key, const T& value) noexcept
        {
            m_PropertyTree.put<T>(key, value);
        }

    private:
        std::string m_PathToFile;
        boost::property_tree::ptree m_PropertyTree;
    };
}
