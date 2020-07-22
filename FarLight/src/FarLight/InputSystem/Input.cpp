#include "flpch.h"

#include "Input.h"
#include "Platform/Windows/InputSystem/WindowsInput.h"

namespace FarLight
{
	Scope<Input> Input::_instance = Scope<WindowsInput>(new WindowsInput());
}