// This is an open source non-commercial project. Dear PVS-Studio, please check it.
// PVS-Studio Static Code Analyzer for C, C++ and C#: http://www.viva64.com

#include "flpch.h"

#include "FarLight/ResourceSystem/Resource.h"

#include <boost/uuid/random_generator.hpp>

namespace FarLight
{
    Resource::Resource() noexcept
        : m_Name("")
        , m_Type(ResourceType::Unknown)
        , m_FilePath("")
        , m_IsInitialized(false)
    {
        GenerateAndSetId();
    }

    Resource::Resource(const std::string& name, ResourceType type, const std::string& filePath) noexcept
        : m_Name(name)
        , m_Type(type)
        , m_FilePath(filePath)
        , m_IsInitialized(false)
    {
        GenerateAndSetId();
    }

    void Resource::GenerateAndSetId() noexcept
    {
        boost::uuids::random_generator gen;
        m_Id = gen();
    }
}
