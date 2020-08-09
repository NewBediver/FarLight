// This is an open source non-commercial project. Dear PVS-Studio, please check it.
// PVS-Studio Static Code Analyzer for C, C++ and C#: http://www.viva64.com

#include "flpch.h"

#include "Input.h"
#include "Platform/Windows/InputSystem/WindowsInput.h"

#ifdef FL_PLATFORM_WINDOWS
	#include "Platform/Windows/InputSystem/WindowsInput.h"
#endif

namespace FarLight
{
	const Scope<Input>& Input::GetInstance() noexcept
	{
		#ifdef FL_PLATFORM_WINDOWS
			static Scope<Input> s_Instance = CreateScope<WindowsInput>();
			return s_Instance;
		#else
			FL_CORE_ASSERT(false, "Unknown platform!");
			static Scope<Input> s_Instance = nullptr;
			return s_Instance;
		#endif
	}
}