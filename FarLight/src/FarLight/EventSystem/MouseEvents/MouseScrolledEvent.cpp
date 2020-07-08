#include "flpch.h"

#include "MouseScrolledEvent.h"

namespace FarLight
{
	std::string MouseScrolledEvent::ToString() const
	{
		std::stringstream ss;
		ss.precision(3);
		ss << std::fixed << "MouseScrolled: (" << _xOffset << ", " << _yOffset << ").";
		return ss.str();
	}
}