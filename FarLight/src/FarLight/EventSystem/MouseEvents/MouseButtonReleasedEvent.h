#pragma once

#include "MouseButtonEvent.h"

namespace FarLight
{
	class FARLIGHT_API MouseButtonReleasedEvent
		: public MouseButtonEvent
	{
	public:
		explicit MouseButtonReleasedEvent(int button)
			: MouseButtonEvent(button) { }

		static EventType GetStaticType() { return EventType::MouseButtonReleasedEventType; }

		std::string ToString() const override;

		virtual EventType MouseButtonReleasedEvent::GetType() const override { return GetStaticType(); }
		virtual std::string MouseButtonReleasedEvent::GetName() const override { return "MouseButtonReleased"; }
	};
}