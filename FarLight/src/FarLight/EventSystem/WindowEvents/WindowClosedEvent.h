#pragma once

#include "FarLight/EventSystem/Event.h"

namespace FarLight
{
	class WindowClosedEvent
		: public Event
	{
	public:
		explicit WindowClosedEvent()
			: Event("WindowClosed", EventType::WindowClosedEventType, ApplicationEventCategory)
		{ }
	};
}