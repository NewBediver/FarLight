// This is an open source non-commercial project. Dear PVS-Studio, please check it.
// PVS-Studio Static Code Analyzer for C, C++ and C#: http://www.viva64.com

#include "flpch.h"

#include "Input.h"
#include "Platform/Windows/InputSystem/WindowsInput.h"

#ifdef FL_PLATFORM_WINDOWS
	#include "Platform/Windows/InputSystem/WindowsInput.h"
#endif

namespace FarLight {

	Scope<Input> Input::s_Instance = Input::Create();

	Scope<Input> Input::Create()
	{
	#ifdef FL_PLATFORM_WINDOWS
		return CreateScope<WindowsInput>();
	#else
		FL_CORE_ASSERT(false, "Unknown platform!");
		return nullptr;
	#endif
	}
}