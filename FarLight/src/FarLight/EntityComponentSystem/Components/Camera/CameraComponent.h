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

        explicit CameraComponent(unsigned width, unsigned height, bool isPrimary = false, bool isFixedAspectRatio = false) noexcept;
        explicit CameraComponent(unsigned width, unsigned height, float zoom, bool isPrimary = false, bool isFixedAspectRatio = false) noexcept;

        void SetAspectRatio(unsigned width, unsigned height) noexcept;

        virtual void OnUserInterfaceDraw() noexcept override;
    };
}
