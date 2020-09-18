#include "flpch.h"

#include <sstream>

#include "Settings.h"

#include <boost/property_tree/xml_parser.hpp>

namespace FarLight
{
    Settings::Settings(const std::string& pathToFile) noexcept
        : m_PathToFile(pathToFile)
    {
        Load();
    }

    Settings::~Settings() noexcept
    {
        Save();
    }

    void Settings::Save() noexcept
    {
        boost::property_tree::write_xml(m_PathToFile, m_PropertyTree);
    }

    void Settings::Load() noexcept
    {
        boost::property_tree::read_xml(m_PathToFile, m_PropertyTree);
    }
}
