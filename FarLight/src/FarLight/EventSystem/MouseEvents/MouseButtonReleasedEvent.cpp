#include "flpch.h"

#include "MouseButtonReleasedEvent.h"

namespace FarLight
{
	std::string MouseButtonReleasedEvent::ToString() const
	{
		std::stringstream ss;
		ss << "MouseButtonReleased: " << "(" << GetButton() << ").";
		return ss.str();
	}
}