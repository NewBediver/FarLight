#pragma once

#include "FarLight/EntityComponentSystem/Interfaces/IComponent.h"

#include <glm/glm.hpp>

namespace FarLight
{
    class RenderComponent final
        : public IComponent
    {
    public:
        explicit RenderComponent(const glm::vec4& color = glm::vec4(1.0f)) noexcept
            : m_Color(color)
        { }

        void SetColor(const glm::vec4& color) noexcept { m_Color = color; }
        const glm::vec4& GetColor() const noexcept { return m_Color; }

        virtual void OnUserInterfaceDraw() noexcept override;

    private:
        glm::vec4 m_Color;
    };
}
