#pragma once

#include "KeyboardKeyEvent.h"

namespace FarLight
{
	class KeyboardKeyPressedEvent final
		: public KeyboardKeyEvent
	{
	public:
		explicit KeyboardKeyPressedEvent(int keyCode, bool isRepeated)
			: KeyboardKeyEvent(keyCode, "KeyboardKeyPressed", EventType::KeyboardKeyPressedEventType)
			, m_IsRepeated(isRepeated)
		{ }

		bool IsRepeated() const { return m_IsRepeated; }

		virtual std::string ToString() const override;

	private:
		bool m_IsRepeated;
	};
}