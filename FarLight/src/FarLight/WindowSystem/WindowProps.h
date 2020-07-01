#pragma once

#include "flpch.h"

namespace FarLight
{
	struct FARLIGHT_API WindowProps
	{
		using uint = unsigned int;

		std::string _title;
		uint _width;
		uint _height;

		explicit WindowProps(const std::string& title = "FarLight Engine", uint width = 1280, uint height = 720);
	};
}