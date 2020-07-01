#include "flpch.h"

#include "MouseButtonPressedEvent.h"

namespace FarLight
{
	MouseButtonPressedEvent::MouseButtonPressedEvent(int button)
		: MouseButtonEvent(button) { }

	EventType MouseButtonPressedEvent::GetStaticType() { return EventType::MouseButtonPressedEventType; }

	std::string MouseButtonPressedEvent::ToString() const
	{
		std::stringstream ss;
		ss << "MouseButtonPressed: " << "(" << _button << ").";
		return ss.str();
	}

	inline EventType MouseButtonPressedEvent::GetType() const { return GetStaticType(); }
	inline std::string MouseButtonPressedEvent::GetName() const { return "MouseButtonPressed"; }
}