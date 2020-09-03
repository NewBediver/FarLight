#pragma once

#include "FarLight/RenderSystem/Camera/Render2DCamera.h"

#include "FarLight/EntityComponentSystem/Interfaces/IComponent.h"

#include <glm/glm.hpp>

namespace FarLight
{
    class CameraComponent final
        : public IComponent
    {
    public:
        Render2DCamera Camera;
        bool IsPrimary;
        bool IsFixedAspectRatio;

        explicit CameraComponent(unsigned width = 1920, unsigned height = 1080, float zoom = 1.0f, bool isPrimary = false, bool isFixedAspectRatio = false) noexcept;

        void SetAspectRatio(unsigned width, unsigned height) noexcept;

        virtual void OnUserInterfaceDraw() noexcept override;

    private:
        glm::vec3 m_CameraUp;
        glm::vec3 m_CameraRight;
        glm::vec3 m_CameraFront;
    };
}
