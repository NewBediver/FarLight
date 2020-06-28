#include "flpch.h"

#include "KeyboardKeyPressedEvent.h"

namespace FarLight
{
	KeyboardKeyPressedEvent::KeyboardKeyPressedEvent(int keyCode, int repeatCount)
		: KeyboardKeyEvent(keyCode), repeatCount(repeatCount) { }

	EventType KeyboardKeyPressedEvent::GetStaticType() { return EventType::KeyboardKeyPressedEventType; }

	inline int KeyboardKeyPressedEvent::GetRepeatCount() const { return repeatCount; }

	std::string KeyboardKeyPressedEvent::ToString() const
	{
		std::stringstream ss;
		ss << "KeyboardKeyPressedEvent: " << "(" << keyboardKeyCode << ") " << repeatCount << " times.";
		return ss.str();
	}

	inline EventType KeyboardKeyPressedEvent::GetType() const { return GetStaticType(); }
	inline std::string KeyboardKeyPressedEvent::GetName() const { return "KeyboardKeyPressed"; }

	KeyboardKeyPressedEvent::~KeyboardKeyPressedEvent() { }
}