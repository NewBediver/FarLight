#pragma once

#include <string>

#include "FarLight/SerializationSystem/Serialization.h"

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
        FL_REGISTER_SERIALIZABLE;

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
        template<class Archive>
        void save(Archive& ar, const unsigned int version) const
        {
            ar & FL_SERIALIZE_NAMED("UUID", m_Ide)
               & FL_SERIALIZE_NAMED("Type", m_Typ);
        }

        template<class Archive>
        void load(Archive& ar, const unsigned int version)
        {
            ar & FL_SERIALIZE_NAMED("UUID", m_Id)
               & FL_SERIALIZE_NAMED("Type", m_Type);
        }

        boost::uuids::uuid m_Id;
        ResourceType m_Type;
    };
}

FL_REGISTER_CLASS_VERSION(FarLight::Resource, 0);
