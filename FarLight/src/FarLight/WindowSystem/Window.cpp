#include "flpch.h"

#include "Window.h"
#include "Platform/Windows/WindowSystem/WindowsWindow.h"

namespace FarLight
{
	std::shared_ptr<Window> Window::Create(const WindowProps& props)
	{
		return std::make_shared<WindowsWindow>(props);
	}
}