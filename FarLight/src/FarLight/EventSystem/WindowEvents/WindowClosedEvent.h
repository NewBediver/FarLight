#pragma once

#include "FarLight/EventSystem/Event.h"

namespace FarLight
{
	class WindowClosedEvent final
		: public Event
	{
	public:
		WindowClosedEvent(const WindowClosedEvent&) = delete;
		WindowClosedEvent(WindowClosedEvent&&) = delete;
		WindowClosedEvent& operator=(const WindowClosedEvent&) = delete;
		WindowClosedEvent& operator=(WindowClosedEvent&&) = delete;

		explicit WindowClosedEvent() noexcept
			: Event("WindowClosed", EventType::WindowClosedEventType, ApplicationEventCategory)
		{ }
	};
}