#pragma once

#include "FarLight/EventSystem/Event.h"

namespace FarLight
{
	class FARLIGHT_API KeyboardKeyEvent
		: public Event
	{
	public:
		const int GetKeyCode() const { return _keyCode; }

		virtual ~KeyboardKeyEvent() = 0 { };

	protected:
		explicit KeyboardKeyEvent(const int keyCode, const std::string& name, const EventType type)
			: Event(name, type, KeyboardEventCategory | InputEventCategory), _keyCode(keyCode) { }

	private:
		int _keyCode;
	};
}