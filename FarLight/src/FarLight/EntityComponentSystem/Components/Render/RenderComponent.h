#pragma once

#include "FarLight/EntityComponentSystem/Interfaces/IComponent.h"

#include <glm/glm.hpp>

#include <boost/uuid/uuid.hpp>

namespace FarLight
{
    class RenderComponent final
        : public IComponent
    {
    public:
        explicit RenderComponent(const glm::vec4& color = glm::vec4(1.0f)) noexcept
            : m_Color(color)
            , m_ShaderIndex(-1)
        { }

        void SetColor(const glm::vec4& color) noexcept { m_Color = color; }
        const glm::vec4& GetColor() const noexcept { return m_Color; }

        boost::uuids::uuid GetId() noexcept;

        virtual void OnUserInterfaceDraw() noexcept override;

    private:
        glm::vec4 m_Color;
        int m_ShaderIndex;
    };
}
