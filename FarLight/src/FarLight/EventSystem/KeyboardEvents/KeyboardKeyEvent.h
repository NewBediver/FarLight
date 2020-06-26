#pragma once

#include "FarLight/EventSystem/Event.h"

namespace FarLight
{

	class FARLIGHT_API KeyboardKeyEvent
		: public Event
	{
	public:
		int GetKeyCode() const;
		virtual int GetCategoryFlags() const override;

		virtual ~KeyboardKeyEvent();

	protected:
		KeyboardKeyEvent(int keyCode);

		int keyboardKeyCode;
	};

}

