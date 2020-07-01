#pragma once

#include "FarLight/EventSystem/Event.h"

namespace FarLight
{
	class FARLIGHT_API MouseButtonEvent
		: public Event
	{
	public:
		int GetButton() const;
		virtual int GetCategoryFlags() const override;

		virtual ~MouseButtonEvent() = default;

	protected:
		explicit MouseButtonEvent(int button);

		int _button;
	};
}