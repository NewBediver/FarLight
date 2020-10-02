#pragma once

#include <string>

#include <boost/uuid/uuid.hpp>
#include <boost/uuid/random_generator.hpp>

namespace FarLight
{
    enum class ResourceType
    {
        Unknown = 0,
        Shader,
        Image
    };

    class Resource
    {
    public:
        explicit Resource(ResourceType type) noexcept
            : m_Type(type)
            , m_Id(boost::uuids::random_generator()())
        { }

        explicit Resource(const boost::uuids::uuid& id, ResourceType type) noexcept
            : m_Type(type)
            , m_Id(id)
        { }

        virtual ~Resource() = default;

        ResourceType GetType() const noexcept { return m_Type; }

        const boost::uuids::uuid& GetId() { return m_Id; }

    private:
        boost::uuids::uuid m_Id;
        ResourceType m_Type;
    };
}
