// This is an open source non-commercial project. Dear PVS-Studio, please check it.
// PVS-Studio Static Code Analyzer for C, C++ and C#: http://www.viva64.com

#include "flpch.h"

#include "FarLight/EntityComponentSystem/Components/Render/RenderComponent.h"

#include <imgui.h>

#include <glm/gtc/type_ptr.hpp>

namespace FarLight
{
    RenderComponent::RenderComponent(const glm::vec4& color) noexcept
        : m_Color(color)
    { }

    void RenderComponent::OnUserInterfaceDraw() noexcept
    {
        ImGui::ColorEdit4("Color", glm::value_ptr(m_Color));
    }
}
