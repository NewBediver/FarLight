#pragma once

#include "FarLight/SerializationSystem/Serialization.h"

namespace FarLight
{
    enum class ComponentType
    {
        Unknown = 0,
        Tag = 1,
        Transform = 2,
        Render = 3,
        Camera = 4,
        Script = 5
    };

    class Component
    {
        FL_REGISTER_SERIALIZABLE;

    public:
        virtual ~Component() noexcept = default;

        explicit Component(ComponentType type) noexcept
            : m_Type(type)
        { }

        ComponentType GetType() const noexcept { return m_Type; }

    private:
        //=Serialization part======================================
        template<class Archive>
        void save(Archive& ar, const unsigned int version) const
        {
            ar & FL_SERIALIZE_NAMED("Type", m_Type);;
        }

        template<class Archive>
        void load(Archive& ar, const unsigned int version)
        {
            ar & FL_SERIALIZE_NAMED("Type", m_Type);
        }
        //=========================================================

        ComponentType m_Type;
    };
}

FL_REGISTER_CLASS_VERSION(FarLight::Component, 0);
