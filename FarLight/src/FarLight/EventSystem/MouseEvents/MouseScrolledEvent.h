#pragma once

#include "FarLight/EventSystem/Event.h"

namespace FarLight
{
	class FARLIGHT_API MouseScrolledEvent
		: public Event
	{
	public:
		MouseScrolledEvent(double offsetX, double offsetY);

		static EventType GetStaticType();

		double GetOffsetX() const;
		double GetOffsetY() const;
		std::string ToString() const override;

		virtual EventType GetType() const override;
		virtual std::string GetName() const override;
		virtual int GetCategoryFlags() const override;

		virtual ~MouseScrolledEvent();

	private:
		double offsetX, offsetY;
	};
}