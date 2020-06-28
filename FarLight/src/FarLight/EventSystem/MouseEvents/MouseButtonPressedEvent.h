#pragma once

#include "MouseButtonEvent.h"

namespace FarLight
{
	class FARLIGHT_API MouseButtonPressedEvent
		: public MouseButtonEvent
	{
	public:
		MouseButtonPressedEvent(int button);

		static EventType GetStaticType();

		std::string ToString() const override;

		virtual EventType GetType() const override;
		virtual std::string GetName() const override;

		virtual ~MouseButtonPressedEvent();
	};
}