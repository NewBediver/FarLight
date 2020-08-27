// This is an open source non-commercial project. Dear PVS-Studio, please check it.
// PVS-Studio Static Code Analyzer for C, C++ and C#: http://www.viva64.com

#include "flpch.h"

#include "Camera2DComponent.h"

#include <imgui.h>

#include <glm/gtc/type_ptr.hpp>

namespace FarLight
{
	Camera2DComponent::Camera2DComponent(unsigned width, unsigned height, bool isPrimary, bool isFixedAspectRatio) noexcept
		: Camera(width, height)
		, IsPrimary(isPrimary)
		, IsFixedAspectRatio(isFixedAspectRatio)
	{ }

	Camera2DComponent::Camera2DComponent(unsigned width, unsigned height, float zoom, bool isPrimary, bool isFixedAspectRatio) noexcept
		: Camera(width, height, zoom)
		, IsPrimary(isPrimary)
		, IsFixedAspectRatio(isFixedAspectRatio)
	{ }

	void Camera2DComponent::SetAspectRatio(unsigned width, unsigned height) noexcept
	{
		Camera.SetAspectRatio(width, height);
	}

	void Camera2DComponent::OnUserInterfaceDraw() noexcept
	{
		ImGui::Checkbox("Is primary", &IsPrimary);
		ImGui::Checkbox("Is fixed aspect ratio", &IsFixedAspectRatio);
		int width = Camera.GetWidth();
		int height = Camera.GetHeight();
		float zoom = Camera.GetZoomLevel();
		ImGui::DragInt("Width", &width, 1.0f, 0, 1920);
		ImGui::DragInt("Height", &height, 1.0f, 0.0, 1080);
		ImGui::DragFloat("Zoom level", &zoom, 0.01f, 0.0f, std::numeric_limits<float>::max(), "%.2f", ImGuiSliderFlags_None);
		Camera.SetWidth(width);
		Camera.SetHeight(height);
		Camera.SetZoomLevel(zoom);
	}
}
