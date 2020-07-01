#pragma once

#include "FarLight/EventSystem/Event.h"

namespace FarLight
{
	class FARLIGHT_API MouseScrolledEvent
		: public Event
	{
	public:
		explicit MouseScrolledEvent(double xOffset, double yOffset);

		static EventType GetStaticType();

		double GetXOffset() const;
		double GetYOffset() const;
		std::string ToString() const override;

		virtual EventType GetType() const override;
		virtual std::string GetName() const override;
		virtual int GetCategoryFlags() const override;

	private:
		double _xOffset, _yOffset;
	};
}