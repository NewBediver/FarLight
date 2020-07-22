#pragma once

#include "FarLight/EventSystem/Event.h"

namespace FarLight
{
	class FARLIGHT_API MouseScrolledEvent
		: public Event
	{
	public:
		explicit MouseScrolledEvent(const double xOffset, const double yOffset)
			: Event("MouseScrolled", EventType::MouseScrolledEventType, MouseEventCategory | InputEventCategory)
			, _xOffset(xOffset)
			, _yOffset(yOffset) { }

		const double MouseScrolledEvent::GetXOffset() const { return _xOffset; }
		const double MouseScrolledEvent::GetYOffset() const { return _yOffset; }

		virtual const std::string ToString() const override;

	private:
		double _xOffset, _yOffset;
	};
}