#include "MouseButtonEvent.h"

namespace FarLight
{
	MouseButtonEvent::MouseButtonEvent(int button)
		: button(button) { }

	inline int MouseButtonEvent::GetButton() const { return button; }
	inline int MouseButtonEvent::GetCategoryFlags() const { return (InputEventCategory | MouseEventCategory | MouseButtonEventCategory); }

	MouseButtonEvent::~MouseButtonEvent() { }

}