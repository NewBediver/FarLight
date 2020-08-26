#pragma once

#include "KeyboardKeyEvent.h"

namespace FarLight
{
	class KeyboardKeyTypedEvent final
		: public KeyboardKeyEvent
	{
	public:
		explicit KeyboardKeyTypedEvent(int&& keyCode) noexcept
			: KeyboardKeyEvent(std::move(keyCode), "KeyboardKeyTyped", EventType::KeyboardKeyTypedEventType)
		{ }

		virtual std::string ToString() const noexcept override;
	};
}