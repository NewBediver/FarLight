#include "flpch.h"

#include "MouseMovedEvent.h"

namespace FarLight
{
	MouseMovedEvent::MouseMovedEvent(double coordX, double coordY)
		: xPos(coordX), yPos(coordY) { }

	inline EventType MouseMovedEvent::GetStaticType() { return EventType::MouseMovedEventType; }

	inline double MouseMovedEvent::GetX() const { return xPos; }
	inline double MouseMovedEvent::GetY() const { return yPos; }
	
	std::string MouseMovedEvent::ToString() const
	{
		std::stringstream ss;
		ss.precision(3);
		ss << std::fixed << "MouseMoved: (" << xPos << ", " << yPos << ").";
		return ss.str();
	}

	inline EventType MouseMovedEvent::GetType() const { return GetStaticType(); }
	inline std::string MouseMovedEvent::GetName() const { return "MouseMoved"; }
	inline int MouseMovedEvent::GetCategoryFlags() const { return (MouseEventCategory | InputEventCategory); }
}