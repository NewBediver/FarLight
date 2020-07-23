// This is an open source non-commercial project. Dear PVS-Studio, please check it.
// PVS-Studio Static Code Analyzer for C, C++ and C#: http://www.viva64.com

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