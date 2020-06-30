#include "flpch.h"
#include "Window.h"

#include "FarLight/Platform/Windows/WindowsWindow.h"

namespace FarLight
{
	Window* Window::Create(const WindowProps& props)
	{
		return new WindowsWindow(props);
	}
}