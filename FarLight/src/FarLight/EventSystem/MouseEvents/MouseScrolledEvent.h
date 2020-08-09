#pragma once

#include "FarLight/EventSystem/Event.h"

namespace FarLight
{
	class MouseScrolledEvent final
		: public Event
	{
	public:
		MouseScrolledEvent(const MouseScrolledEvent&) = delete;
		MouseScrolledEvent(MouseScrolledEvent&&) = delete;
		MouseScrolledEvent& operator=(const MouseScrolledEvent&) = delete;
		MouseScrolledEvent& operator=(MouseScrolledEvent&&) = delete;

		explicit MouseScrolledEvent(double xOffset, double yOffset) noexcept
			: Event("MouseScrolled", EventType::MouseScrolledEventType, MouseEventCategory | InputEventCategory)
			, m_XOffset(xOffset)
			, m_YOffset(yOffset)
		{ }

		constexpr
		double MouseScrolledEvent::GetXOffset() const noexcept { return m_XOffset; }
		constexpr
		double MouseScrolledEvent::GetYOffset() const noexcept { return m_YOffset; }

		virtual std::string ToString() const noexcept override;

	private:
		double m_XOffset, m_YOffset;
	};
}