#pragma once

namespace FarLight
{
	class IUIDrawable
	{
	public:
		virtual ~IUIDrawable() noexcept = default;

		virtual void OnUserInterfaceDraw() noexcept = 0;
	};
}