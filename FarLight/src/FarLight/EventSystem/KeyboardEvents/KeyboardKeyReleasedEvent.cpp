#include "flpch.h"

#include "KeyboardKeyReleasedEvent.h"

namespace FarLight
{
	const std::string KeyboardKeyReleasedEvent::ToString() const
	{
		std::stringstream ss;
		ss << GetName() << ": " << "(" << GetKeyCode() << ").";
		return ss.str();
	}
}