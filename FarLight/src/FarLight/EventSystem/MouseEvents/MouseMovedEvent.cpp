#include "flpch.h"

#include "MouseMovedEvent.h"

namespace FarLight
{
	const std::string MouseMovedEvent::ToString() const
	{
		std::stringstream ss;
		ss.precision(3);
		ss << std::fixed << GetName() << ": " << "(" << _xPos << ", " << _yPos << ").";
		return ss.str();
	}
}