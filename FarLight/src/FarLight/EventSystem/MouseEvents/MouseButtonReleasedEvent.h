#pragma once

#include "MouseButtonEvent.h"

namespace FarLight
{
	class FARLIGHT_API MouseButtonReleasedEvent
		: public MouseButtonEvent
	{
	public:
		explicit MouseButtonReleasedEvent(int button);

		static EventType GetStaticType();

		std::string ToString() const override;

		virtual EventType GetType() const override;
		virtual std::string GetName() const override;
	};
}