#include "flpch.h"

#include "Input.h"
#include "Platform/Windows/InputSystem/WindowsInput.h"

namespace FarLight
{
	std::shared_ptr<Input> Input::_instance = std::make_shared<WindowsInput>();
}