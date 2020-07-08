#include "flpch.h"

#include "MouseButtonPressedEvent.h"

namespace FarLight
{
	std::string MouseButtonPressedEvent::ToString() const
	{
		std::stringstream ss;
		ss << "MouseButtonPressed: " << "(" << GetButton() << ").";
		return ss.str();
	}
}