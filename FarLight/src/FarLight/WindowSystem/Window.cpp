#include "flpch.h"

#include "Window.h"
#include "Platform/Windows/WindowSystem/WindowsWindow.h"

namespace FarLight
{
	Ref<Window> Window::Create(const WindowProps& props)
	{
		return Ref<WindowsWindow>(new WindowsWindow(props));
	}
}