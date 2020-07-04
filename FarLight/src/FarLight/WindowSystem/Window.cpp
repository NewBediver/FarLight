#include "flpch.h"
#include "Window.h"

#include "FarLight/Platform/Windows/WindowsWindow.h"

namespace FarLight
{
	inline std::unique_ptr<Window> Window::Create(const WindowProps& props)
	{
		return std::make_unique<WindowsWindow>(props);
	}
}