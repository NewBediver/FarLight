#pragma once

#include "MouseButtonEvent.h"

namespace FarLight
{
	class FARLIGHT_API MouseButtonPressedEvent
		: public MouseButtonEvent
	{
	public:
		explicit MouseButtonPressedEvent(int button)
			: MouseButtonEvent(button) { }

		static EventType GetStaticType() { return EventType::MouseButtonPressedEventType; }

		std::string ToString() const override;

		virtual EventType MouseButtonPressedEvent::GetType() const override { return GetStaticType(); }
		virtual std::string MouseButtonPressedEvent::GetName() const override { return "MouseButtonPressed"; }
	};
}