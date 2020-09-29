#pragma once

#include "FarLight/Abstraction/EngineObject/EngineObject.h"

#include "FarLight/EntityComponentSystem/Interfaces/Component.h"
#include "FarLight/EntityComponentSystem/Interfaces/OnUIDrawable.h"

#include <glm/glm.hpp>

#include <boost/uuid/uuid.hpp>

namespace FarLight
{
    class RenderComponent final
        : public EngineObject
        , public Component
        , public OnUIDrawable
    {
        FL_REGISTER_SERIALIZABLE;

    public:
        explicit RenderComponent(const glm::vec4& color = glm::vec4(1.0f)) noexcept
            : Component(ComponentType::Render)
            , m_Color(color)
        { }

        void SetColor(const glm::vec4& color) noexcept { m_Color = color; }
        const glm::vec4& GetColor() const noexcept { return m_Color; }

        virtual void OnUserInterfaceDraw() noexcept override;

    private:
        //=Serialization part======================================
        template<class Archive>
        void save(Archive& ar, const unsigned int version) const
        {
            ar & FL_SERIALIZE_DERIVED(EngineObject)
               & FL_SERIALIZE_DERIVED(Component)
               & FL_SERIALIZE_DERIVED(OnUIDrawable)
               & FL_SERIALIZE_NAMED("R", m_Color.r)
               & FL_SERIALIZE_NAMED("G", m_Color.g)
               & FL_SERIALIZE_NAMED("B", m_Color.b)
               & FL_SERIALIZE_NAMED("A", m_Color.a);
        }

        template<class Archive>
        void load(Archive& ar, const unsigned int version)
        {
            ar & FL_SERIALIZE_DERIVED(EngineObject)
               & FL_SERIALIZE_DERIVED(Component)
               & FL_SERIALIZE_DERIVED(OnUIDrawable)
               & FL_SERIALIZE_NAMED("R", m_Color.r)
               & FL_SERIALIZE_NAMED("G", m_Color.g)
               & FL_SERIALIZE_NAMED("B", m_Color.b)
               & FL_SERIALIZE_NAMED("A", m_Color.a);
        }
        //=========================================================

        glm::vec4 m_Color;
    };
}

FL_REGISTER_CLASS_VERSION(FarLight::RenderComponent, 0);
