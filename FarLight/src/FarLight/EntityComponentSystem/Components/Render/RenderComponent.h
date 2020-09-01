#pragma once

#include "FarLight/EntityComponentSystem/Interfaces/IComponent.h"

#include <glm/glm.hpp>

namespace FarLight
{
    class RenderComponent final
        : public IComponent
    {
    public:
        glm::vec4 Color;

        explicit RenderComponent(const glm::vec4& color = glm::vec4(1.0f)) noexcept;

        virtual void OnUserInterfaceDraw() noexcept override;
    };
}
