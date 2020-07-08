#pragma once

#include "flpch.h"

namespace FarLight
{
	struct FARLIGHT_API WindowProps
	{
		std::string _title;
		unsigned int _width;
		unsigned int _height;

		explicit WindowProps(const std::string& title = "FarLight Engine", unsigned int width = 1280, unsigned int height = 720)
			: _title(title), _width(width), _height(height) { }
	};
}