#pragma once

#include "FarLight/EntityComponentSystem/Interfaces/IUIDrawable.h"

#include <glm/glm.hpp>

namespace FarLight
{
	class TransformComponent final
		: public IUIDrawable
	{
	public:
		glm::vec3 Position;
		glm::vec2 Size;
		float Rotation;

		explicit TransformComponent(const glm::vec3& position = glm::vec3(0.0f), const glm::vec2& size = glm::vec2(1.0f), float rotation = 0.0f) noexcept;

		glm::mat4 GetTransformationMatrix() const noexcept;

		virtual void OnUserInterfaceEditableDraw() noexcept override;
		virtual void OnUserInterfaceConstantDraw() const noexcept override;
	};
}