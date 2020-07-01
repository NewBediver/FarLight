#include "flpch.h"

#include "WindowProps.h"

namespace FarLight
{
	WindowProps::WindowProps(const std::string& title, uint width, uint height)
		: _title(title), _width(width), _height(height) { }
}