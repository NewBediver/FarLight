#include "flpch.h"

#include "KeyboardKeyPressedEvent.h"

namespace FarLight
{
	std::string KeyboardKeyPressedEvent::ToString() const
	{
		std::stringstream ss;
		ss << std::boolalpha <<  "KeyboardKeyPressedEvent: " << "(" << GetKeyCode() << "). " << "Is repeated: " << _isRepeated << ".";
		return ss.str();
	}
}