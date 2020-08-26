#pragma once

#include "KeyboardKeyEvent.h"

namespace FarLight
{
	class KeyboardKeyReleasedEvent final
		: public KeyboardKeyEvent
	{
	public:
		explicit KeyboardKeyReleasedEvent(int&& keyCode) noexcept
			: KeyboardKeyEvent(std::move(keyCode), "KeyboardKeyReleased", EventType::KeyboardKeyReleasedEventType)
		{ }

		virtual std::string ToString() const noexcept override;
	};
}