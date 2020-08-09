#pragma once

#include "FarLight/EventSystem/Event.h"

namespace FarLight
{
	class KeyboardKeyEvent
		: public Event
	{
	public:
		KeyboardKeyEvent(const KeyboardKeyEvent&) = delete;
		KeyboardKeyEvent(KeyboardKeyEvent&&) = delete;
		KeyboardKeyEvent& operator=(const KeyboardKeyEvent&) = delete;
		KeyboardKeyEvent& operator=(KeyboardKeyEvent&&) = delete;

		virtual ~KeyboardKeyEvent() noexcept = 0 { };

		constexpr
		int GetKeyCode() const noexcept { return m_KeyCode; }

	protected:
		explicit KeyboardKeyEvent(int keyCode, const std::string& name, EventType type) noexcept
			: Event(name, type, KeyboardEventCategory | InputEventCategory), m_KeyCode(keyCode)
		{ }

	private:
		int m_KeyCode;
	};
}