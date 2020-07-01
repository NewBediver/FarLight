#include "flpch.h"
#include "WindowResizedEvent.h"

namespace FarLight
{
	using uint = unsigned int;

	WindowResizedEvent::WindowResizedEvent(uint width, uint height)
		: _width(width), _height(height) { }

	EventType WindowResizedEvent::GetStaticType() { return EventType::WindowResizedEventType; }

	inline uint WindowResizedEvent::GetWidth() const { return _width; }
	inline uint WindowResizedEvent::GetHeight() const { return _height; }

	inline EventType WindowResizedEvent::GetType() const { return GetStaticType(); }
	inline std::string WindowResizedEvent::GetName() const { return "WindowResized"; }
	inline int WindowResizedEvent::GetCategoryFlags() const { return EventCategory::ApplicationEventCategory; }
	
	std::string WindowResizedEvent::ToString() const
	{
		std::stringstream ss;
		ss << "WindowResized: (" << _width << ", " << _height << ").";
		return ss.str();
	}
}
