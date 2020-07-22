#pragma once

#include "KeyboardKeyEvent.h"

namespace FarLight
{
	class FARLIGHT_API KeyboardKeyReleasedEvent
		: public KeyboardKeyEvent
	{
	public:
		explicit KeyboardKeyReleasedEvent(const int keyCode)
			: KeyboardKeyEvent(keyCode, "KeyboardKeyReleased"
			, EventType::KeyboardKeyReleasedEventType) { }

		virtual const std::string ToString() const override;
	};
}