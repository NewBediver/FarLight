#pragma once

#include "FarLight/EventSystem/Event.h"

#include <sstream>

namespace FarLight
{

	class FARLIGHT_API MouseScrolledEvent
		: public Event
	{
	public:
		MouseScrolledEvent(double, double);

		static EventType GetStaticType();

		double GetOffsetX() const;
		double GetOffsetY() const;
		std::string ToString() const override;

		virtual EventType GetType() const override;
		virtual std::string GetName() const override;
		virtual int GetCategoryFlags() const override;

	private:
		double offsetX, offsetY;
	};

}