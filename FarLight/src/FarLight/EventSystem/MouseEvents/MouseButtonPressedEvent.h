#pragma once

#include "MouseButtonEvent.h"

namespace FarLight
{
	class MouseButtonPressedEvent final
		: public MouseButtonEvent
	{
	public:
		MouseButtonPressedEvent(const MouseButtonPressedEvent&) = delete;
		MouseButtonPressedEvent(MouseButtonPressedEvent&&) = delete;
		MouseButtonPressedEvent& operator=(const MouseButtonPressedEvent&) = delete;
		MouseButtonPressedEvent& operator=(MouseButtonPressedEvent&&) = delete;

		explicit MouseButtonPressedEvent(int&& button) noexcept
			: MouseButtonEvent(std::move(button), "MouseButtonPressed", EventType::MouseButtonPressedEventType)
		{ }

		virtual std::string ToString() const noexcept override;
	};
}