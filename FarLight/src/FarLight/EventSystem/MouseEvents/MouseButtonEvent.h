#pragma once

#include "FarLight/EventSystem/Event.h"

namespace FarLight
{
	class FARLIGHT_API MouseButtonEvent
		: public Event
	{
	public:
		const int GetButton() const { return _button; }

		virtual ~MouseButtonEvent() = 0 { };

	protected:
		explicit MouseButtonEvent(const int button, const std::string& name, const EventType type)
			: Event(name, type, InputEventCategory | MouseEventCategory | MouseButtonEventCategory)
			, _button(button) { }

	private:
		int _button;
	};
}