#include "flpch.h"

#include "MouseScrolledEvent.h"

namespace FarLight
{
	MouseScrolledEvent::MouseScrolledEvent(double offsetX, double offsetY)
		: xOffset(offsetX), yOffset(offsetY) { }

	EventType MouseScrolledEvent::GetStaticType() { return EventType::MouseScrolledEventType; }

	inline double MouseScrolledEvent::GetXOffset() const { return xOffset; }
	inline double MouseScrolledEvent::GetYOffset() const { return yOffset; }

	std::string MouseScrolledEvent::ToString() const
	{
		std::stringstream ss;
		ss.precision(3);
		ss << std::fixed << "MouseScrolled: (" << xOffset << ", " << yOffset << ").";
		return ss.str();
	}

	inline EventType MouseScrolledEvent::GetType() const { return GetStaticType(); }
	inline std::string MouseScrolledEvent::GetName() const { return "MouseScrolled"; }
	inline int MouseScrolledEvent::GetCategoryFlags() const { return (MouseEventCategory | InputEventCategory); }
}