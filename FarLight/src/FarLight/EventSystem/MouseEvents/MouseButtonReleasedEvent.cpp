#include "flpch.h"

#include "MouseButtonReleasedEvent.h"

namespace FarLight
{
	const std::string MouseButtonReleasedEvent::ToString() const
	{
		std::stringstream ss;
		ss << GetName() << ": " << "(" << GetButton() << ").";
		return ss.str();
	}
}