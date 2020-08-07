#pragma once

#include "FarLight/EventSystem/Event.h"

namespace FarLight
{
	class KeyboardKeyEvent
		: public Event
	{
	public:
		virtual ~KeyboardKeyEvent() = 0 { };

		int GetKeyCode() const { return m_KeyCode; }

	protected:
		explicit KeyboardKeyEvent(int keyCode, const std::string& name, EventType type)
			: Event(name, type, KeyboardEventCategory | InputEventCategory), m_KeyCode(keyCode)
		{ }

	private:
		int m_KeyCode;
	};
}