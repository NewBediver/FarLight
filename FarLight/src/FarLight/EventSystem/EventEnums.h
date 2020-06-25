#pragma once

#include "FarLight/Core.h"

namespace FarLight
{

	enum class EventType
	{
		None = 0,
		KeyPressedEventType, KeyReleasedEventType,
		MouseButtonPressedEventType, MouseButtonReleasedEventType, MouseMovedEventType, MouseScrolledEventType
	};

	enum EventCategory
	{
		None = 0,
		ApplicationEventCategory = BIT(0),
		InputEventCategory = BIT(1),
		KeyboardEventCategory = BIT(2),
		MouseEventCategory = BIT(3),
		MouseButtonEventCategory = BIT(4)
	};

}

