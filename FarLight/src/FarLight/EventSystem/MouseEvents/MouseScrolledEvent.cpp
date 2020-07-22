#include "flpch.h"

#include "MouseScrolledEvent.h"

namespace FarLight
{
	const std::string MouseScrolledEvent::ToString() const
	{
		std::stringstream ss;
		ss.precision(3);
		ss << std::fixed << GetName() << ": " << "(" << _xOffset << ", " << _yOffset << ").";
		return ss.str();
	}
}