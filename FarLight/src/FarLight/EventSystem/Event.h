#pragma once

#include <iostream>

#include "FarLight/Core/Core.h"

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
		Event(const std::string& name, const EventType type, const int category)
			: _name(name), _type(type), _category(category), _isHandled(false) { }

		virtual const EventType GetType() const { return _type; };
		virtual const std::string& GetName() const { return _name; }
		virtual const int GetCategoryFlags() const { return _category; };

		virtual const std::string ToString() const { return GetName(); }

		const bool IsHandled() const { return _isHandled; }
		void SetHandled(const bool isHandled) { _isHandled = isHandled; }

		const bool IsInCategory(const EventCategory& eventCategory) const { return (GetCategoryFlags() & eventCategory); }

		virtual ~Event() = 0 { };

	private:
		std::string _name;
		EventType _type;
		int _category;
		bool _isHandled;
	};

	inline std::ostream& operator<<(std::ostream& os, const Event& event) { return os << event.ToString(); }
}