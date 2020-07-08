#pragma once

#include "KeyboardKeyEvent.h"

namespace FarLight
{
	class FARLIGHT_API KeyboardKeyTypedEvent
		: public KeyboardKeyEvent
	{
	public:
		KeyboardKeyTypedEvent(int keyCode)
			: KeyboardKeyEvent(keyCode) { }

		static EventType GetStaticType() { return EventType::KeyboardKeyTypedEventType; }

		virtual std::string ToString() const override;
		virtual EventType GetType() const override { return GetStaticType(); }
		virtual std::string GetName() const override { return "KeyboardKeyTyped"; }
	};
}