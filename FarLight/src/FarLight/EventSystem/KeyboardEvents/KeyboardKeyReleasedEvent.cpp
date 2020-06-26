#include "KeyboardKeyReleasedEvent.h"

namespace FarLight
{
	KeyboardKeyReleasedEvent::KeyboardKeyReleasedEvent(int keyCode)
		: KeyboardKeyEvent(keyCode) { }

	EventType KeyboardKeyReleasedEvent::GetStaticType() { return EventType::KeyboardKeyPressedEventType; }

	std::string KeyboardKeyReleasedEvent::ToString() const
	{
		std::stringstream ss;
		ss << "KeyboardKeyReleasedEvent: " << "(" << keyboardKeyCode << ") " << repeatCount << " times.";
		return ss.str();
	}

	inline EventType KeyboardKeyReleasedEvent::GetType() const { return GetStaticType(); }
	inline std::string KeyboardKeyReleasedEvent::GetName() const { return "KeyboardKeyReleased"; }

	KeyboardKeyReleasedEvent::~KeyboardKeyReleasedEvent() { }
}
