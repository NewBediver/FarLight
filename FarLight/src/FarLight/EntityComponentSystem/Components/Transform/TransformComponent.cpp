// This is an open source non-commercial project. Dear PVS-Studio, please check it.
// PVS-Studio Static Code Analyzer for C, C++ and C#: http://www.viva64.com

#include "flpch.h"

#include "TransformComponent.h"

#include <imgui.h>

#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtc/type_ptr.hpp>

namespace FarLight
{
	TransformComponent::TransformComponent(const glm::vec3& position, const glm::vec2& size, float rotation) noexcept
		: Position(position)
		, Size(size)
		, Rotation(rotation)
	{ }

	glm::mat4 TransformComponent::GetTransformationMatrix() const noexcept
	{
		return glm::translate(glm::mat4(1.0f), Position)
			* glm::rotate(glm::mat4(1.0f), Rotation, glm::vec3(0.0f, 0.0f, 1.0f))
			* glm::scale(glm::mat4(1.0f), glm::vec3(Size, 1.0f));
	}

	void TransformComponent::OnUserInterfaceEditableDraw() noexcept
	{
		ImGui::DragFloat3("Position", glm::value_ptr(Position), 0.001f, 0.0f);
		ImGui::DragFloat2("Size", glm::value_ptr(Size), 0.001f, 0.0f, std::numeric_limits<float>::max(), "%.3f", ImGuiSliderFlags_None);
		float degree = glm::degrees(Rotation);
		ImGui::DragFloat("Rotation", &degree, 0.1f, std::numeric_limits<float>::lowest(), std::numeric_limits<float>::max(), "%.1f", ImGuiSliderFlags_None);
		Rotation = glm::radians(degree);
	}

	void TransformComponent::OnUserInterfaceConstantDraw() const noexcept
	{
		ImGui::Text("Position: %.3f %.3f %.3f", Position.x, Position.y, Position.z);
		ImGui::Text("Size: %.3f %.3f", Size.x, Size.y);
		ImGui::Text("Rotation: %.1f", glm::degrees(Rotation));
	}
}
