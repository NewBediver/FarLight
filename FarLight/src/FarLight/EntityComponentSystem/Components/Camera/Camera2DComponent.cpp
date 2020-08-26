// This is an open source non-commercial project. Dear PVS-Studio, please check it.
// PVS-Studio Static Code Analyzer for C, C++ and C#: http://www.viva64.com

#include "flpch.h"

#include "Camera2DComponent.h"

#include <imgui.h>

#include <glm/gtc/type_ptr.hpp>

namespace FarLight
{
	Camera2DComponent::Camera2DComponent(const glm::mat4& projection, bool isPrimary) noexcept
		: Camera(projection)
		, IsPrimary(isPrimary)
	{ }

	void Camera2DComponent::OnUserInterfaceDraw() noexcept
	{
		ImGui::Checkbox("Is Primary", &IsPrimary);
	}
}
