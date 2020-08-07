#pragma once

#include "FarLight/EventSystem/Event.h"

namespace FarLight
{
	class WindowResizedEvent final
		: public Event
	{
	public:
		explicit WindowResizedEvent(unsigned width, unsigned height)
			: Event("WindowResized", EventType::WindowResizedEventType, ApplicationEventCategory)
			, m_Width(width)
			, m_Height(height)
		{ }

		unsigned WindowResizedEvent::GetWidth() const { return m_Width; }
		unsigned WindowResizedEvent::GetHeight() const { return m_Height; }

		virtual std::string ToString() const override;

	private:
		unsigned m_Width, m_Height;
	};
}