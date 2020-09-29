#pragma once

#include "FarLight/Abstraction/EngineObject/EngineObject.h"

#include "FarLight/EntityComponentSystem/Interfaces/Component.h"
#include "FarLight/EntityComponentSystem/Interfaces/OnUIDrawable.h"

#include "FarLight/BasicFunctionality/Camera/Camera.h"
#include "FarLight/BasicFunctionality/Camera/RenderOrthoCamera.h"

#include <glm/glm.hpp>

namespace FarLight
{
    class CameraComponent final
        : public EngineObject
        , public Component
        , public OnUIDrawable
    {
        FL_REGISTER_SERIALIZABLE;

    public:
        explicit CameraComponent(unsigned width = 1280, unsigned height = 720, bool isPrimary = false, bool isFixedAspectRatio = false) noexcept
            : Component(ComponentType::Camera)
            , m_Camera(CreateScope<RenderOrthoCamera>(width, height))
            , m_IsPrimary(isPrimary)
            , m_IsFixedAspectRatio(isFixedAspectRatio)
        { }

        void SetIsFixedAspectRatio(bool isFixedAspectRatio) { m_IsFixedAspectRatio = isFixedAspectRatio; }
        bool IsFixedAspectRatio() const noexcept { return m_IsFixedAspectRatio; }

        void SetIsPrimary(bool isPrimary) { m_IsPrimary = m_IsPrimary; }
        bool IsPrimary() const noexcept { return m_IsPrimary; }

        Scope<Camera>& GetCamera() noexcept { return m_Camera; }

        virtual void OnUserInterfaceDraw() noexcept override;

    private:
        //=Serialization part======================================
        template<class Archive>
        void save(Archive& ar, const unsigned int version) const
        {
            ar & FL_SERIALIZE_DERIVED(EngineObject)
               & FL_SERIALIZE_DERIVED(Component)
               & FL_SERIALIZE_DERIVED(OnUIDrawable)
               & FL_SERIALIZE_NAMED("IsPrimary", m_IsPrimary)
               & FL_SERIALIZE_NAMED("IsFixedAspectRatio", m_IsFixedAspectRatio);
        }

        template<class Archive>
        void load(Archive& ar, const unsigned int version)
        {
            ar & FL_SERIALIZE_DERIVED(EngineObject)
               & FL_SERIALIZE_DERIVED(Component)
               & FL_SERIALIZE_DERIVED(OnUIDrawable)
               & FL_SERIALIZE_NAMED("IsPrimary", m_IsPrimary)
               & FL_SERIALIZE_NAMED("IsFixedAspectRatio", m_IsFixedAspectRatio);
        }
        //=========================================================

        Scope<Camera> m_Camera;

        bool m_IsPrimary, m_IsFixedAspectRatio;
    };
}

FL_REGISTER_CLASS_VERSION(FarLight::CameraComponent, 0);
