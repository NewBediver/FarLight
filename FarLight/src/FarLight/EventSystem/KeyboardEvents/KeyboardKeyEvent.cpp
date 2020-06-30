#include "flpch.h"

#include "KeyboardKeyEvent.h"

namespace FarLight
{
	KeyboardKeyEvent::KeyboardKeyEvent(int keyCode) :keyCode(keyCode) { }

	inline int KeyboardKeyEvent::GetKeyCode() const { return keyCode; }
	inline int KeyboardKeyEvent::GetCategoryFlags() const { return (KeyboardEventCategory | InputEventCategory); }
}