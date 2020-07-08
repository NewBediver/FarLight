#pragma once

#include "FarLight/EventSystem/Event.h"

namespace FarLight
{
	class FARLIGHT_API MouseScrolledEvent
		: public Event
	{
	public:
		explicit MouseScrolledEvent(double xOffset, double yOffset)
			: _xOffset(xOffset), _yOffset(yOffset) { }

		static EventType GetStaticType() { return EventType::MouseScrolledEventType; }

		double MouseScrolledEvent::GetXOffset() const { return _xOffset; }
		double MouseScrolledEvent::GetYOffset() const { return _yOffset; }
		std::string ToString() const override;

		virtual EventType MouseScrolledEvent::GetType() const override { return GetStaticType(); }
		virtual std::string MouseScrolledEvent::GetName() const override { return "MouseScrolled"; }
		virtual int MouseScrolledEvent::GetCategoryFlags() const override { return (MouseEventCategory | InputEventCategory); }

	private:
		double _xOffset, _yOffset;
	};
}