#pragma once

#include "FarLight/RenderSystem/Camera/RenderCamera.h"

#include "FarLight/EntityComponentSystem/Interfaces/IUIDrawable.h"

#include <glm/glm.hpp>

namespace FarLight
{
	class Camera2DComponent final
		: public IUIDrawable
	{
	public:
		RenderCamera Camera;
		bool IsPrimary;

		explicit Camera2DComponent(const glm::mat4& projection = glm::mat4(1.0f), bool isPrimary = false) noexcept;

		virtual void OnUserInterfaceDraw() noexcept override;
	};
}