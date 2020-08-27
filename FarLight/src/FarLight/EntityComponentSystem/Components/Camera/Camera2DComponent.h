#pragma once

#include "FarLight/RenderSystem/Camera/Render2DCamera.h"

#include "FarLight/EntityComponentSystem/Interfaces/IUIDrawable.h"

#include <glm/glm.hpp>

namespace FarLight
{
	class Camera2DComponent final
		: public IUIDrawable
	{
	public:
		Render2DCamera Camera;
		bool IsPrimary;
		bool IsFixedAspectRatio;

		explicit Camera2DComponent(unsigned width, unsigned height, bool isPrimary = false, bool isFixedAspectRatio = false) noexcept;
		explicit Camera2DComponent(unsigned width, unsigned height, float zoom, bool isPrimary = false, bool isFixedAspectRatio = false) noexcept;

		void SetAspectRatio(unsigned width, unsigned height) noexcept;

		virtual void OnUserInterfaceDraw() noexcept override;
	};
}