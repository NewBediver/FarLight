#pragma once

#include "FarLight/EventSystem/Event.h"

namespace FarLight
{
	class WindowResizedEvent
		: public Event
	{
	public:
		explicit WindowResizedEvent(unsigned int width, unsigned int height)
			: Event("WindowResized", EventType::WindowResizedEventType, ApplicationEventCategory)
			, m_Width(width)
			, m_Height(height)
		{ }

		unsigned int WindowResizedEvent::GetWidth() const { return m_Width; }
		unsigned int WindowResizedEvent::GetHeight() const { return m_Height; }

		virtual std::string ToString() const override;

	private:
		unsigned int m_Width, m_Height;
	};
}