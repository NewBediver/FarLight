#pragma once

#include "KeyboardKeyEvent.h"

namespace FarLight
{
	class FARLIGHT_API KeyboardKeyReleasedEvent
		: public KeyboardKeyEvent
	{
	public:
		explicit KeyboardKeyReleasedEvent(int keyCode)
			: KeyboardKeyEvent(keyCode) { }

		static EventType GetStaticType() { return EventType::KeyboardKeyReleasedEventType; }

		virtual std::string ToString() const override;
		virtual EventType GetType() const override { return GetStaticType(); }
		virtual std::string GetName() const override { return "KeyboardKeyReleased"; }
	};
}