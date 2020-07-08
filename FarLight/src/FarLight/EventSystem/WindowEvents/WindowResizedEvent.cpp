#include "flpch.h"
#include "WindowResizedEvent.h"

namespace FarLight
{
	std::string WindowResizedEvent::ToString() const
	{
		std::stringstream ss;
		ss << "WindowResized: (" << _width << ", " << _height << ").";
		return ss.str();
	}
}