#include "MouseMovedEvent.h"

namespace FarLight
{

	MouseMovedEvent::MouseMovedEvent(double coordX, double coordY)
		: coordX(coordX), coordY(coordY) { }

	inline EventType MouseMovedEvent::GetStaticType() { return EventType::MouseMovedEventType; }

	inline double MouseMovedEvent::GetX() const { return coordX; }
	inline double MouseMovedEvent::GetY() const { return coordY; }
	
	std::string MouseMovedEvent::ToString() const
	{
		std::stringstream ss;
		ss << "MouseMovedEvent: (" << coordX << ", " << coordY << ")";
		return ss.str();
	}

	inline EventType MouseMovedEvent::GetType() const { return GetStaticType(); }
	inline std::string MouseMovedEvent::GetName() const { return "MouseMoved"; }
	inline int MouseMovedEvent::GetCategoryFlags() const { return (MouseEventCategory | InputEventCategory); }

	MouseMovedEvent::~MouseMovedEvent() { }

}