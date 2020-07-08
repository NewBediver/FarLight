#pragma once

#include "FarLight/EventSystem/Event.h"

namespace FarLight
{
	class FARLIGHT_API WindowClosedEvent
		: public Event
	{
	public:
		static EventType GetStaticType() { return EventType::WindowClosedEventType; }

		virtual EventType WindowClosedEvent::GetType() const override { return GetStaticType(); }
		virtual std::string WindowClosedEvent::GetName() const override { return "WindowClosed"; }
		virtual int WindowClosedEvent::GetCategoryFlags() const override { return EventCategory::ApplicationEventCategory; }
	};
}