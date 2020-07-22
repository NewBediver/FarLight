#pragma once

#include "FarLight/EventSystem/Event.h"

namespace FarLight
{
	class FARLIGHT_API WindowResizedEvent
		: public Event
	{
	public:
		explicit WindowResizedEvent(const unsigned int width, const unsigned int height)
			: Event("WindowResized", EventType::WindowResizedEventType, ApplicationEventCategory)
			, _width(width)
			, _height(height) { }

		const unsigned int WindowResizedEvent::GetWidth() const { return _width; }
		const unsigned int WindowResizedEvent::GetHeight() const { return _height; }

		virtual const std::string ToString() const override;

	private:
		unsigned int _width, _height;
	};
}