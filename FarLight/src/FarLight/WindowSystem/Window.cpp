// This is an open source non-commercial project. Dear PVS-Studio, please check it.
// PVS-Studio Static Code Analyzer for C, C++ and C#: http://www.viva64.com

#include "flpch.h"

#include "Window.h"
#include "Platform/Windows/WindowSystem/WindowsWindow.h"

#ifdef FL_PLATFORM_WINDOWS
	#include "Platform/Windows/WindowSystem/WindowsWindow.h"
#endif

namespace FarLight
{

	Ref<Window> Window::Create(const WindowProps& props)
	{
	#ifdef FL_PLATFORM_WINDOWS
		return CreateRef<WindowsWindow>(props);
	#else
		FL_CORE_ASSERT(false, "Unknown platform!");
		return nullptr;
	#endif
	}
}