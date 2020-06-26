#include "KeyboardKeyEvent.h"

namespace FarLight
{
	KeyboardKeyEvent::KeyboardKeyEvent(int keyCode) : keyboardKeyCode(keyCode) { }

	inline int KeyboardKeyEvent::GetKeyCode() const { return keyboardKeyCode; }
	inline int KeyboardKeyEvent::GetCategoryFlags() const { return (KeyboardEventCategory | InputEventCategory); }
	KeyboardKeyEvent::~KeyboardKeyEvent() { }
	
}


