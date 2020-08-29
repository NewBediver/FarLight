// This is an open source non-commercial project. Dear PVS-Studio, please check it.
// PVS-Studio Static Code Analyzer for C, C++ and C#: http://www.viva64.com

#include "flpch.h"

#include "RenderComponent.h"

#include <imgui.h>

#include <glm/gtc/type_ptr.hpp>

namespace FarLight
{
	RenderComponent::RenderComponent(const glm::vec4& color) noexcept
		: Color(color)
	{ }

	void RenderComponent::OnUserInterfaceEditableDraw() noexcept
	{
		ImGui::ColorEdit4("Color", glm::value_ptr(Color));
	}

	void RenderComponent::OnUserInterfaceConstantDraw() const noexcept
	{
		ImGui::Text("Color: %d %d %d %d", static_cast<int>(Color.r * 255), static_cast<int>(Color.g * 255), static_cast<int>(Color.b * 255), static_cast<int>(Color.a * 255));
	}
}
