#pragma once

#include <string>

#include "FarLight/Abstraction/EngineObject/EngineObject.h"

#include "FarLight/EntityComponentSystem/Interfaces/Component.h"
#include "FarLight/EntityComponentSystem/Interfaces/OnUIDrawable.h"

#include "FarLight/SerializationSystem/Serialization.h"

namespace FarLight
{
    class TagComponent final
        : public EngineObject
        , public Component
        , public OnUIDrawable
    {
        FL_REGISTER_SERIALIZABLE;

    public:
        explicit TagComponent(const std::string& tag = "Entity") noexcept
            : Component(ComponentType::Tag)
            , m_Tag(tag)
        { }

        void SetTag(const std::string& tag) noexcept { m_Tag = tag; }
        const std::string& GetTag() const noexcept { return m_Tag; }

        virtual void OnUserInterfaceDraw() noexcept override;

    private:
        //=Serialization part======================================
        template<class Archive>
        void save(Archive& ar, const unsigned int version) const
        {
            ar & FL_SERIALIZE_DERIVED(EngineObject)
               & FL_SERIALIZE_DERIVED(Component)
               & FL_SERIALIZE_DERIVED(OnUIDrawable)
               & FL_SERIALIZE_NAMED("Tag", m_Tag);
        }

        template<class Archive>
        void load(Archive& ar, const unsigned int version)
        {
            ar & FL_SERIALIZE_DERIVED(EngineObject)
               & FL_SERIALIZE_DERIVED(Component)
               & FL_SERIALIZE_DERIVED(OnUIDrawable)
               & FL_SERIALIZE_NAMED("Tag", m_Tag);
        }
        //=========================================================

        std::string m_Tag;
    };
}

FL_REGISTER_CLASS_VERSION(FarLight::TagComponent, 0);
