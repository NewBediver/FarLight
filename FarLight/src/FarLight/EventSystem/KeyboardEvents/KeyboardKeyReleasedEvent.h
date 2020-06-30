#pragma once

#include "KeyboardKeyEvent.h"

namespace FarLight
{
	class FARLIGHT_API KeyboardKeyReleasedEvent
		: public KeyboardKeyEvent
	{
	public:
		explicit KeyboardKeyReleasedEvent(int keyCode);

		static EventType GetStaticType();

		virtual std::string ToString() const override;
		virtual EventType GetType() const override;
		virtual std::string GetName() const override;
	};
}