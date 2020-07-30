#pragma once

#include "FarLight/EventSystem/Event.h"

namespace FarLight
{
	class MouseButtonEvent
		: public Event
	{
	public:
		int GetButton() const { return m_Button; }

		virtual ~MouseButtonEvent() = 0 { };

	protected:
		explicit MouseButtonEvent(int button, const std::string& name, EventType type)
			: Event(name, type, InputEventCategory | MouseEventCategory | MouseButtonEventCategory)
			, m_Button(button) 
		{ }

	private:
		int m_Button;
	};
}