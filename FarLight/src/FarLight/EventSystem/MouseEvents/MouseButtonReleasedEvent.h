#pragma once

#include "MouseButtonEvent.h"

#include <sstream>

namespace FarLight
{

	class FARLIGHT_API MouseButtonReleasedEvent
		: public MouseButtonEvent
	{
	public:
		MouseButtonReleasedEvent(int button);

		static EventType GetStaticType();

		std::string ToString() const override;

		virtual EventType GetType() const override;
		virtual std::string GetName() const override;

		virtual ~MouseButtonReleasedEvent();
	};

}