#include "flpch.h"
#include "WindowResizedEvent.h"

namespace FarLight
{
	using uint = unsigned int;

	WindowResizedEvent::WindowResizedEvent(uint width, uint height)
		: width(width), height(height) { }

	EventType WindowResizedEvent::GetStaticType() { return EventType::WindowResizedEventType; }

	inline uint WindowResizedEvent::GetWidth() const { return width; }
	inline uint WindowResizedEvent::GetHeight() const { return height; }

	inline EventType WindowResizedEvent::GetType() const { return GetStaticType(); }
	inline std::string WindowResizedEvent::GetName() const { return "WindowResized"; }
	inline int WindowResizedEvent::GetCategoryFlags() const { return EventCategory::ApplicationEventCategory; }
	
	std::string WindowResizedEvent::ToString() const
	{
		std::stringstream ss;
		ss << "WindowResized: (" << width << ", " << height << ").";
		return ss.str();
	}
}
