#pragma once

#include <iostream>

#include "FarLight/Core.h"

namespace FarLight
{
	enum class EventType
	{
		None = 0,
		WindowClosedEventType, WindowResizedEventType, WindowFocusedEventType, WindowLostFocusEventType, WindowMovedEventType,
		KeyboardKeyPressedEventType, KeyboardKeyReleasedEventType, KeyboardKeyTypedEventType,
		MouseButtonPressedEventType, MouseButtonReleasedEventType, MouseMovedEventType, MouseScrolledEventType
	};

	enum EventCategory
	{
		None = 0,
		ApplicationEventCategory = BIT(0),
		InputEventCategory = BIT(1),
		KeyboardEventCategory = BIT(2),
		MouseEventCategory = BIT(3),
		MouseButtonEventCategory = BIT(4)
	};

	/*
	Simple blocking events.
	Later some kind of Event Buffer will be created.
	*/

	// TODO: Event buffer

	class FARLIGHT_API Event
	{
	public:
		virtual EventType GetType() const = 0;
		virtual std::string GetName() const = 0;
		virtual int GetCategoryFlags() const = 0;

		virtual std::string ToString() const { return GetName(); }

		bool IsHandled() const { return _isHandled; }
		void SetHandled(bool isHandled) { _isHandled = isHandled; }

		bool IsInCategory(const EventCategory& eventCategory) const { return (GetCategoryFlags() & eventCategory); }

		virtual ~Event() = default;

	private:
		bool _isHandled = false;
	};

	inline std::ostream& operator<<(std::ostream& os, const Event& event) { return os << event.ToString(); }
}