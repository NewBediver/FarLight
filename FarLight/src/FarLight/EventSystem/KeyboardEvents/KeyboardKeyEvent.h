#pragma once

#include "FarLight/EventSystem/Event.h"

namespace FarLight
{
	class KeyboardKeyEvent
		: public Event
	{
	public:
		int GetKeyCode() const { return m_KeyCode; }

		virtual ~KeyboardKeyEvent() = 0 { };

	protected:
		explicit KeyboardKeyEvent(int keyCode, const std::string& name, EventType type)
			: Event(name, type, KeyboardEventCategory | InputEventCategory), m_KeyCode(keyCode)
		{ }

	private:
		int m_KeyCode;
	};
}