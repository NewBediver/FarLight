#pragma once

#include "FarLight/EventSystem/Event.h"

namespace FarLight
{
	class FARLIGHT_API KeyboardKeyEvent
		: public Event
	{
	public:
		int GetKeyCode() const { return _keyCode; }
		virtual int GetCategoryFlags() const override { return (KeyboardEventCategory | InputEventCategory); }

		virtual ~KeyboardKeyEvent() = default;

	protected:
		explicit KeyboardKeyEvent(int keyCode)
			: _keyCode(keyCode) { }

	private:
		int _keyCode;
	};
}