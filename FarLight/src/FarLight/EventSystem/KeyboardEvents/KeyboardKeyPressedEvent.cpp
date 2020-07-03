#include "flpch.h"

#include "KeyboardKeyPressedEvent.h"

namespace FarLight
{
	KeyboardKeyPressedEvent::KeyboardKeyPressedEvent(int keyCode, bool isRepeated)
		: KeyboardKeyEvent(keyCode), _isRepeated(isRepeated) { }

	EventType KeyboardKeyPressedEvent::GetStaticType() { return EventType::KeyboardKeyPressedEventType; }

	inline bool KeyboardKeyPressedEvent::IsRepeated() const { return _isRepeated; }

	std::string KeyboardKeyPressedEvent::ToString() const
	{
		std::stringstream ss;
		ss << std::boolalpha <<  "KeyboardKeyPressedEvent: " << "(" << GetKeyCode() << "). " << "Is repeated: " << _isRepeated << ".";
		return ss.str();
	}

	inline EventType KeyboardKeyPressedEvent::GetType() const { return GetStaticType(); }
	inline std::string KeyboardKeyPressedEvent::GetName() const { return "KeyboardKeyPressed"; }
}