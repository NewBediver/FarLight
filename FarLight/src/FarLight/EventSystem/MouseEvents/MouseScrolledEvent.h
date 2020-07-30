#pragma once

#include "FarLight/EventSystem/Event.h"

namespace FarLight
{
	class MouseScrolledEvent
		: public Event
	{
	public:
		explicit MouseScrolledEvent(double xOffset, double yOffset)
			: Event("MouseScrolled", EventType::MouseScrolledEventType, MouseEventCategory | InputEventCategory)
			, m_XOffset(xOffset)
			, m_YOffset(yOffset)
		{ }

		double MouseScrolledEvent::GetXOffset() const { return m_XOffset; }
		double MouseScrolledEvent::GetYOffset() const { return m_YOffset; }

		virtual std::string ToString() const override;

	private:
		double m_XOffset, m_YOffset;
	};
}