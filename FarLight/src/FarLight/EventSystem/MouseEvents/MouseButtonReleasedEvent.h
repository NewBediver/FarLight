#pragma once

#include "MouseButtonEvent.h"

#include <sstream>

namespace FarLight
{

	class MouseButtonReleasedEvent
		: public MouseButtonEvent
	{
	public:
		MouseButtonReleasedEvent(int);

		static EventType GetStaticType();

		std::string ToString() const override;

		virtual EventType GetType() const override;
		virtual std::string GetName() const override;
	};

}