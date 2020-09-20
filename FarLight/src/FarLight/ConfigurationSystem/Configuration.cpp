// This is an open source non-commercial project. Dear PVS-Studio, please check it.
// PVS-Studio Static Code Analyzer for C, C++ and C#: http://www.viva64.com

#include "flpch.h"

#include "FarLight/ConfigurationSystem/Configuration.h"

#include "FarLight/VirtualFileSystem/FileSystem.h"

#include <boost/property_tree/xml_parser.hpp>

namespace FarLight
{
    Configuration::Configuration(const std::string& fileName) noexcept
        : m_FileName(fileName)
    {
        Load();
    }

    Configuration::~Configuration() noexcept
    {
        Save();
    }

    void Configuration::Save() noexcept
    {
        if (!FileSystem::GetInstance().IsFileExists(m_FileName))
            FileSystem::GetInstance().SetFile(m_FileName, FileSystem::GetInstance().GetDirectory("Settings") + '\\' + m_FileName + ".cfg");

        boost::property_tree::write_xml(FileSystem::GetInstance().GetFile(m_FileName), m_PropertyTree);
    }

    void Configuration::Load() noexcept
    {
        if (!FileSystem::GetInstance().IsFileExists(m_FileName))
            FileSystem::GetInstance().SetFile(m_FileName, FileSystem::GetInstance().GetDirectory("Settings") + '\\' + m_FileName + ".cfg");

        boost::property_tree::read_xml(FileSystem::GetInstance().GetFile(m_FileName), m_PropertyTree);
    }
}
