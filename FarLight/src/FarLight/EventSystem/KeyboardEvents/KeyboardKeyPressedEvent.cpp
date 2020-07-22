#include "flpch.h"

#include "KeyboardKeyPressedEvent.h"

namespace FarLight
{
	const std::string KeyboardKeyPressedEvent::ToString() const
	{
		std::stringstream ss;
		ss << std::boolalpha << GetName() << ": " << "(" << GetKeyCode() << "). " << "Is repeated: " << IsRepeated() << ".";
		return ss.str();
	}
}