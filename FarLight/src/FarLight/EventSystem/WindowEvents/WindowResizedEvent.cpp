#include "flpch.h"

#include "WindowResizedEvent.h"

namespace FarLight
{
	const std::string WindowResizedEvent::ToString() const
	{
		std::stringstream ss;
		ss << GetName() << ": " << "(" << _width << ", " << _height << ").";
		return ss.str();
	}
}