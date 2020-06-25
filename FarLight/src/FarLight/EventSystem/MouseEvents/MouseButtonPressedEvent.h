#pragma once

#include "MouseButtonEvent.h"

#include <sstream>

namespace FarLight
{

	class MouseButtonPressedEvent
		: public MouseButtonEvent
	{
	public:
		MouseButtonPressedEvent(int);

		static EventType GetStaticType();

		std::string ToString() const override;

		virtual EventType GetType() const override;
		virtual std::string GetName() const override;
	};

}



