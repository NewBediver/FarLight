#include "flpch.h"

#include "MouseScrolledEvent.h"

namespace FarLight
{
	MouseScrolledEvent::MouseScrolledEvent(double offsetX, double offsetY)
		: offsetX(offsetX), offsetY(offsetY) { }

	EventType MouseScrolledEvent::GetStaticType() { return EventType::MouseScrolledEventType; }

	inline double MouseScrolledEvent::GetOffsetX() const { return offsetX; }
	inline double MouseScrolledEvent::GetOffsetY() const { return offsetY; }

	std::string MouseScrolledEvent::ToString() const
	{
		std::stringstream ss;
		ss.precision(3);
		ss << std::fixed << "MouseScrolled: (" << offsetX << ", " << offsetY << ").";
		return ss.str();
	}

	inline EventType MouseScrolledEvent::GetType() const { return GetStaticType(); }
	inline std::string MouseScrolledEvent::GetName() const { return "MouseScrolled"; }
	inline int MouseScrolledEvent::GetCategoryFlags() const { return (MouseEventCategory | InputEventCategory); }

	MouseScrolledEvent::~MouseScrolledEvent() { }
}