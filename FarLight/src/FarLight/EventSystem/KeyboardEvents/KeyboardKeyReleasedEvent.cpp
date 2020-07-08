#include "flpch.h"

#include "KeyboardKeyReleasedEvent.h"

namespace FarLight
{
	std::string KeyboardKeyReleasedEvent::ToString() const
	{
		std::stringstream ss;
		ss << "KeyboardKeyReleasedEvent: " << "(" << GetKeyCode() << ").";
		return ss.str();
	}
}