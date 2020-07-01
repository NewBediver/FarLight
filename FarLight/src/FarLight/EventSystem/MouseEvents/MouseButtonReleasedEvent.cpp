#include "flpch.h"

#include "MouseButtonReleasedEvent.h"

namespace FarLight
{
	MouseButtonReleasedEvent::MouseButtonReleasedEvent(int button)
		: MouseButtonEvent(button) { }

	EventType MouseButtonReleasedEvent::GetStaticType() { return EventType::MouseButtonReleasedEventType; }

	std::string MouseButtonReleasedEvent::ToString() const
	{
		std::stringstream ss;
		ss << "MouseButtonReleased: " << "(" << _button << ").";
		return ss.str();
	}

	inline EventType MouseButtonReleasedEvent::GetType() const { return GetStaticType(); }
	inline std::string MouseButtonReleasedEvent::GetName() const { return "MouseButtonReleased"; }
}