#pragma once

namespace FarLight
{
	class IUIDrawable
	{
	public:
		virtual ~IUIDrawable() noexcept = default;

		virtual void OnUserInterfaceEditableDraw() noexcept = 0;
		virtual void OnUserInterfaceConstantDraw() const noexcept = 0;
	};
}