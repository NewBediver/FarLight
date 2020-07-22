#include "flpch.h"

#include "MouseButtonPressedEvent.h"

namespace FarLight
{
	const std::string MouseButtonPressedEvent::ToString() const
	{
		std::stringstream ss;
		ss << GetName() << ": " << "(" << GetButton() << ").";
		return ss.str();
	}
}