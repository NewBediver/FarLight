#pragma once

#include <string>

#include <boost/property_tree/ptree.hpp>

namespace FarLight
{
    class Configuration
    {
    public:
        explicit Configuration(const std::string& fileName) noexcept;
        virtual ~Configuration() noexcept;

        void Save() noexcept;
        void Load() noexcept;

        template<typename T>
        bool IsExists(const std::string& key) const noexcept
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
        bool IsExists(const std::string& key, const T& value) const noexcept
        {
            if (!IsExists<T>(key) || m_PropertyTree.get<T>(key) != value) return false;
            else return true;
        }

        template<typename T>
        T GetValue(const std::string& key) const noexcept
        {
            FL_ASSERT(IsExists<T>(key), "Current settings tree doesn't contain this option!");
            return m_PropertyTree.get<T>(key);
        }

        template<typename T>
        void SetValue(const std::string& key, const T& value) noexcept
        {
            m_PropertyTree.put<T>(key, value);
        }

    protected:
        boost::property_tree::ptree m_PropertyTree;
        std::string m_FileName;
    };
}
