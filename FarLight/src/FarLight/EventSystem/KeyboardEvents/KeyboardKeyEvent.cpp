#include "flpch.h"

#include "KeyboardKeyEvent.h"

namespace FarLight
{
	KeyboardKeyEvent::KeyboardKeyEvent(int keyCode)
		: _keyCode(keyCode) { }

	inline int KeyboardKeyEvent::GetKeyCode() const { return _keyCode; }
	inline int KeyboardKeyEvent::GetCategoryFlags() const { return (KeyboardEventCategory | InputEventCategory); }
}