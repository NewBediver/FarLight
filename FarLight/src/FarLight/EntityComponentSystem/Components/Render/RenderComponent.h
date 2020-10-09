#pragma once

#include "FarLight/Abstraction/EngineObject/EngineObject.h"

#include "FarLight/EntityComponentSystem/Interfaces/OnUIDrawable.h"

#include <glm/glm.hpp>

namespace FarLight
{
    class RenderComponent final
        : public EngineObject
        , public OnUIDrawable
    {
    public:
        explicit RenderComponent(EngineID id, glm::vec4 color = glm::vec4(1.0f)) noexcept
            : EngineObject(std::move(id))
            , m_Color(std::move(color))
        { }

        explicit RenderComponent(glm::vec4 color = glm::vec4(1.0f)) noexcept
            : m_Color(std::move(color))
        { }

        void SetColor(const glm::vec4& color) noexcept { m_Color = color; }
        const glm::vec4& GetColor() const noexcept { return m_Color; }

        virtual void OnUserInterfaceDraw() noexcept override;

    private:
        glm::vec4 m_Color;
    };
}
