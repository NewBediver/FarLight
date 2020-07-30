#pragma once

#include "MouseButtonEvent.h"

namespace FarLight
{
	class MouseButtonReleasedEvent
		: public MouseButtonEvent
	{
	public:
		explicit MouseButtonReleasedEvent(int button)
			: MouseButtonEvent(button, "MouseButtonReleased", EventType::MouseButtonReleasedEventType)
		{ }

		virtual std::string ToString() const override;
	};
}