#pragma once

#include "KeyboardKeyEvent.h"

namespace FarLight
{
	class KeyboardKeyReleasedEvent final
		: public KeyboardKeyEvent
	{
	public:
		KeyboardKeyReleasedEvent(const KeyboardKeyReleasedEvent&) = delete;
		KeyboardKeyReleasedEvent(KeyboardKeyReleasedEvent&&) = delete;
		KeyboardKeyReleasedEvent& operator=(const KeyboardKeyReleasedEvent&) = delete;
		KeyboardKeyReleasedEvent& operator=(KeyboardKeyReleasedEvent&&) = delete;

		explicit KeyboardKeyReleasedEvent(int&& keyCode) noexcept
			: KeyboardKeyEvent(std::move(keyCode), "KeyboardKeyReleased", EventType::KeyboardKeyReleasedEventType)
		{ }

		virtual std::string ToString() const noexcept override;
	};
}