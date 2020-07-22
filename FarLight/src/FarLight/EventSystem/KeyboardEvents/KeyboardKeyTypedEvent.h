#pragma once

#include "KeyboardKeyEvent.h"

namespace FarLight
{
	class FARLIGHT_API KeyboardKeyTypedEvent
		: public KeyboardKeyEvent
	{
	public:
		KeyboardKeyTypedEvent(const int keyCode)
			: KeyboardKeyEvent(keyCode, "KeyboardKeyTyped", EventType::KeyboardKeyTypedEventType) { }

		virtual const std::string ToString() const override;
	};
}