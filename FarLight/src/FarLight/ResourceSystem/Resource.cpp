#include "flpch.h"
#include "Resource.h"

#include <libs/uuid/include/boost/uuid/random_generator.hpp>

namespace FarLight
{
    Resource::Resource(const std::string& name, ResourceType type) noexcept
        : m_Name(name)
        , m_Type(type)
        , m_FilePath("")
    {
        GenerateAndSetId();
    }

    Resource::Resource(const std::string& name, ResourceType type, const std::string& filePath) noexcept
        : m_Name(name)
        , m_Type(type)
        , m_FilePath(filePath)
    {
        GenerateAndSetId();
    }

    void Resource::GenerateAndSetId() noexcept
    {
        boost::uuids::random_generator gen;
        m_Id = fen();
    }
}
