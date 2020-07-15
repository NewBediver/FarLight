#pragma once

#include "FarLight/EventSystem/Event.h"

namespace FarLight
{
	class FARLIGHT_API WindowResizedEvent
		: public Event
	{
	public:
		explicit WindowResizedEvent(unsigned int width, unsigned int height)
			: _width(width), _height(height) { }

		unsigned int WindowResizedEvent::GetWidth() const { return _width; }
		unsigned int WindowResizedEvent::GetHeight() const { return _height; }

		static EventType GetStaticType() { return EventType::WindowResizedEventType; }

		virtual EventType WindowResizedEvent::GetType() const override { return GetStaticType(); }
		virtual std::string WindowResizedEvent::GetName() const override { return "WindowResized"; }
		virtual int WindowResizedEvent::GetCategoryFlags() const override { return EventCategory::ApplicationEventCategory; }

		virtual std::string ToString() const override;

	private:
		unsigned int _width, _height;
	};
}