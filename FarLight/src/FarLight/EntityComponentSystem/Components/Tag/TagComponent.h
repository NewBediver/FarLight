#pragma once

#include <string>

#include "FarLight/EntityComponentSystem/Interfaces/IUIDrawable.h"

namespace FarLight
{
	class TagComponent final
		: public IUIDrawable
	{
	public:
		std::string Tag;

		explicit TagComponent(const std::string& tag = "Entity") noexcept;

		virtual void OnUserInterfaceEditableDraw() noexcept override;
		virtual void OnUserInterfaceConstantDraw() const noexcept override;
	};
}