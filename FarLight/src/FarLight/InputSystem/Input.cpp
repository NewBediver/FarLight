// This is an open source non-commercial project. Dear PVS-Studio, please check it.
// PVS-Studio Static Code Analyzer for C, C++ and C#: http://www.viva64.com

#include "flpch.h"

#include "Input.h"
#include "Platform/Windows/InputSystem/WindowsInput.h"

namespace FarLight
{
	Scope<Input> Input::_instance = Scope<WindowsInput>(new WindowsInput());
}