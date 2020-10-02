#pragma once

#include "FarLight/Abstraction/EngineObject/EngineObject.h"

#include "FarLight/EntityComponentSystem/Interfaces/OnUIDrawable.h"

#include "FarLight/BasicFunctionality/Camera/Camera.h"
#include "FarLight/BasicFunctionality/Camera/RenderOrthoCamera.h"

#include <glm/glm.hpp>

namespace FarLight
{
    class CameraComponent final
        : public EngineObject
        , public OnUIDrawable
    {
        friend class ComponentSerializerConfiguration;

    public:
        explicit CameraComponent(boost::uuids::uuid id, unsigned width = 1280, unsigned height = 720, bool isPrimary = false, bool isFixedAspectRatio = false) noexcept
            : EngineObject(std::move(id))
            , m_Camera(CreateScope<RenderOrthoCamera>(width, height))
            , m_IsPrimary(isPrimary)
            , m_IsFixedAspectRatio(isFixedAspectRatio)
        { }

        explicit CameraComponent(unsigned width = 1280, unsigned height = 720, bool isPrimary = false, bool isFixedAspectRatio = false) noexcept
            : m_Camera(CreateScope<RenderOrthoCamera>(width, height))
            , m_IsPrimary(isPrimary)
            , m_IsFixedAspectRatio(isFixedAspectRatio)
        { }

        void SetIsFixedAspectRatio(bool isFixedAspectRatio) { m_IsFixedAspectRatio = isFixedAspectRatio; }
        bool IsFixedAspectRatio() const noexcept { return m_IsFixedAspectRatio; }

        void SetIsPrimary(bool isPrimary) { m_IsPrimary = m_IsPrimary; }
        bool IsPrimary() const noexcept { return m_IsPrimary; }

        const Scope<Camera>& GetCamera() noexcept { return m_Camera; }

        virtual void OnUserInterfaceDraw() noexcept override;

    private:
        Scope<Camera> m_Camera;

        bool m_IsPrimary, m_IsFixedAspectRatio;
    };
}
