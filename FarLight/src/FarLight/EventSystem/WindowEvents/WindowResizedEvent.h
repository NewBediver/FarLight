#pragma once

#include "FarLight/EventSystem/Event.h"

namespace FarLight
{
	class FARLIGHT_API WindowResizedEvent
		: public Event
	{
		using uint = unsigned int;

	public:
		explicit WindowResizedEvent(uint width, uint height)
			: _width(width), _height(height) { }

		uint WindowResizedEvent::GetWidth() const { return _width; }
		uint WindowResizedEvent::GetHeight() const { return _height; }

		static EventType GetStaticType() { return EventType::WindowResizedEventType; }

		virtual EventType WindowResizedEvent::GetType() const override { return GetStaticType(); }
		virtual std::string WindowResizedEvent::GetName() const override { return "WindowResized"; }
		virtual int WindowResizedEvent::GetCategoryFlags() const override { return EventCategory::ApplicationEventCategory; }

		virtual std::string ToString() const override;

	private:
		uint _width, _height;
	};
}