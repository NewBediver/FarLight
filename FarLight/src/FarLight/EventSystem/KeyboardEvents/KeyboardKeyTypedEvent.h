#pragma once

#include "KeyboardKeyEvent.h"

namespace FarLight
{
	class KeyboardKeyTypedEvent
		: public KeyboardKeyEvent
	{
	public:
		explicit KeyboardKeyTypedEvent(int keyCode)
			: KeyboardKeyEvent(keyCode, "KeyboardKeyTyped", EventType::KeyboardKeyTypedEventType)
		{ }

		virtual std::string ToString() const override;
	};
}