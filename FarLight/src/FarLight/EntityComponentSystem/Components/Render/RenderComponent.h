#pragma once

#include "FarLight/EntityComponentSystem/Interfaces/IUIDrawable.h"

#include <glm/glm.hpp>

namespace FarLight
{
	class RenderComponent final
		: public IUIDrawable
	{
	public:
		glm::vec4 Color;

		explicit RenderComponent(const glm::vec4& color = glm::vec4(1.0f)) noexcept;

		virtual void OnUserInterfaceEditableDraw() noexcept override;
		virtual void OnUserInterfaceConstantDraw() const noexcept override;
	};
}