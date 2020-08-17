#pragma once

#include "FarLight/Core/Core.h"

namespace FarLight
{
	struct WindowProps final
	{
		std::string Title;
		unsigned Width;
		unsigned Height;

		explicit WindowProps(std::string&& title = "FarLight Engine", unsigned width = 1280, unsigned height = 720) noexcept
			: Title(std::move(title))
			, Width(width)
			, Height(height)
		{ }
	};
}