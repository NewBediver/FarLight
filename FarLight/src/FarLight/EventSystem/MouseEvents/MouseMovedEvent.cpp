#include "flpch.h"

#include "MouseMovedEvent.h"

namespace FarLight
{
	std::string MouseMovedEvent::ToString() const
	{
		std::stringstream ss;
		ss.precision(3);
		ss << std::fixed << "MouseMoved: (" << _xPos << ", " << _yPos << ").";
		return ss.str();
	}
}