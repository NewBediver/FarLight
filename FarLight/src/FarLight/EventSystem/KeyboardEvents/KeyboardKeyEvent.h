#pragma once

#include "FarLight/EventSystem/Event.h"

namespace FarLight
{
	class KeyboardKeyEvent
		: public Event
	{
	public:
		virtual ~KeyboardKeyEvent() noexcept = 0 { };

		constexpr
		int GetKeyCode() const noexcept { return m_KeyCode; }

	protected:
		explicit KeyboardKeyEvent(int&& keyCode, std::string&& name, EventType&& type) noexcept
			: Event(std::move(name), std::move(type), KeyboardEventCategory | InputEventCategory)
			, m_KeyCode(std::move(keyCode))
		{ }

	private:
		int m_KeyCode;
	};
}