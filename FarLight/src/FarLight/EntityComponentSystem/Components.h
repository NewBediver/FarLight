#pragma once

#include <string>

#include <glm/glm.hpp>

namespace FarLight
{
	struct TransformComponent
	{
		glm::vec3 Position;
		glm::vec2 Size;
		float Rotation;

		explicit TransformComponent(const glm::vec3& position = glm::vec3(0.0f), const glm::vec2& size = glm::vec2(1.0f), float rotation = 0.0f) noexcept
			: Position(position)
			, Size(size)
			, Rotation(rotation)
		{ }
	};

	struct TagComponent
	{
		std::string Tag;
		
		explicit TagComponent(const std::string& tag = "Entity") noexcept
			: Tag(tag)
		{ }
	};

	struct RendererComponent
	{
		glm::vec4 Color;

		explicit RendererComponent(const glm::vec4& color = glm::vec4(1.0f)) noexcept
			: Color(color)
		{ }
	};
}