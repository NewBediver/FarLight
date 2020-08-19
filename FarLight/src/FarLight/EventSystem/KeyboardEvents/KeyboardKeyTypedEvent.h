#pragma once

#include "KeyboardKeyEvent.h"

namespace FarLight
{
	class KeyboardKeyTypedEvent final
		: public KeyboardKeyEvent
	{
	public:
		KeyboardKeyTypedEvent(const KeyboardKeyTypedEvent&) = delete;
		KeyboardKeyTypedEvent(KeyboardKeyTypedEvent&&) = delete;
		KeyboardKeyTypedEvent& operator=(const KeyboardKeyTypedEvent&) = delete;
		KeyboardKeyTypedEvent& operator=(KeyboardKeyTypedEvent&&) = delete;

		explicit KeyboardKeyTypedEvent(int&& keyCode) noexcept
			: KeyboardKeyEvent(std::move(keyCode), "KeyboardKeyTyped", EventType::KeyboardKeyTypedEventType)
		{ }

		virtual std::string ToString() const noexcept override;
	};
}