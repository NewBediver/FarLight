#pragma once

#include "FarLight/EventSystem/Event.h"

namespace FarLight
{
	class FARLIGHT_API WindowClosedEvent
		: public Event
	{
	public:
		WindowClosedEvent()
			: Event("WindowClosed", EventType::WindowClosedEventType, ApplicationEventCategory) { }
	};
}