#pragma once

#include "FarLight/EventSystem/Event.h"

namespace FarLight
{
	class FARLIGHT_API WindowClosedEvent
		: public Event
	{
	public:
		static EventType GetStaticType();

		virtual EventType GetType() const override;
		virtual std::string GetName() const override;
		virtual int GetCategoryFlags() const override;
	};
}