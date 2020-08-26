#pragma once

#include "KeyboardKeyEvent.h"

namespace FarLight
{
	class KeyboardKeyPressedEvent final
		: public KeyboardKeyEvent
	{
	public:
		explicit KeyboardKeyPressedEvent(int&& keyCode, bool&& isRepeated) noexcept
			: KeyboardKeyEvent(std::move(keyCode), "KeyboardKeyPressed", EventType::KeyboardKeyPressedEventType)
			, m_IsRepeated(std::move(isRepeated))
		{ }

		constexpr
		bool IsRepeated() const noexcept { return m_IsRepeated; }

		virtual std::string ToString() const noexcept override;

	private:
		bool m_IsRepeated;
	};
}