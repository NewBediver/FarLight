#pragma once

#include "MouseButtonEvent.h"

namespace FarLight
{
	class FARLIGHT_API MouseButtonPressedEvent
		: public MouseButtonEvent
	{
	public:
		explicit MouseButtonPressedEvent(const int button)
			: MouseButtonEvent(button, "MouseButtonPressed", EventType::MouseButtonPressedEventType) { }

		virtual const std::string ToString() const override;
	};
}