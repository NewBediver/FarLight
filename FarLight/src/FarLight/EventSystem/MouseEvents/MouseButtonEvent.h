#pragma once

#include "FarLight/EventSystem/Event.h"

namespace FarLight
{
	class FARLIGHT_API MouseButtonEvent
		: public Event
	{
	public:
		int GetButton() const { return _button; }
		virtual int GetCategoryFlags() const override { return (InputEventCategory | MouseEventCategory | MouseButtonEventCategory); }

		virtual ~MouseButtonEvent() = default;

	protected:
		explicit MouseButtonEvent(int button)
			: _button(button) { }

	private:
		int _button;
	};
}