#pragma once

#include "FarLight/EventSystem/Event.h"

namespace FarLight
{
	class MouseButtonEvent
		: public Event
	{
	public:
		MouseButtonEvent(const MouseButtonEvent&) = delete;
		MouseButtonEvent(MouseButtonEvent&&) = delete;
		MouseButtonEvent& operator=(const MouseButtonEvent&) = delete;
		MouseButtonEvent& operator=(MouseButtonEvent&&) = delete;

		virtual ~MouseButtonEvent() noexcept = 0 { };

		constexpr
		int GetButton() const noexcept { return m_Button; }

	protected:
		explicit MouseButtonEvent(int button, const std::string& name, EventType type) noexcept
			: Event(name, type, InputEventCategory | MouseEventCategory | MouseButtonEventCategory)
			, m_Button(button) 
		{ }

	private:
		int m_Button;
	};
}