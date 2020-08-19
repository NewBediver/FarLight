#pragma once

#include "MouseButtonEvent.h"

namespace FarLight
{
	class MouseButtonReleasedEvent final
		: public MouseButtonEvent
	{
	public:
		MouseButtonReleasedEvent(const MouseButtonReleasedEvent&) = delete;
		MouseButtonReleasedEvent(MouseButtonReleasedEvent&&) = delete;
		MouseButtonReleasedEvent& operator=(const MouseButtonReleasedEvent&) = delete;
		MouseButtonReleasedEvent& operator=(MouseButtonReleasedEvent&&) = delete;

		explicit MouseButtonReleasedEvent(int&& button) noexcept
			: MouseButtonEvent(std::move(button), "MouseButtonReleased", EventType::MouseButtonReleasedEventType)
		{ }

		virtual std::string ToString() const noexcept override;
	};
}