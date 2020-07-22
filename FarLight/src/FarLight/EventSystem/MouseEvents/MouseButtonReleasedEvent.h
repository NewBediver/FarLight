#pragma once

#include "MouseButtonEvent.h"

namespace FarLight
{
	class FARLIGHT_API MouseButtonReleasedEvent
		: public MouseButtonEvent
	{
	public:
		explicit MouseButtonReleasedEvent(const int button)
			: MouseButtonEvent(button, "MouseButtonReleased", EventType::MouseButtonReleasedEventType) { }

		virtual const std::string ToString() const override;
	};
}