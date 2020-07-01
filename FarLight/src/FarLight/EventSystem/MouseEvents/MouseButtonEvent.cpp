#include "flpch.h"

#include "MouseButtonEvent.h"

namespace FarLight
{
	MouseButtonEvent::MouseButtonEvent(int button)
		: _button(button) { }

	inline int MouseButtonEvent::GetButton() const { return _button; }
	inline int MouseButtonEvent::GetCategoryFlags() const { return (InputEventCategory | MouseEventCategory | MouseButtonEventCategory); }
}