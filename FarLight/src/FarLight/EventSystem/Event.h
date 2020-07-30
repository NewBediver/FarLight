#pragma once

#include <iostream>

#include <FarLight/Core/Core.h>

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

	class Event
	{
	public:
		explicit Event(const std::string& name, EventType type, int category)
			: m_Name(name)
			, m_Type(type)
			, m_Category(category)
			, m_IsHandled(false)
		{ }

		virtual EventType GetType() const { return m_Type; };
		virtual const std::string& GetName() const { return m_Name; }
		virtual int GetCategoryFlags() const { return m_Category; };

		virtual std::string ToString() const { return GetName(); }

		bool IsHandled() const { return m_IsHandled; }
		void SetHandled(bool isHandled) { m_IsHandled = isHandled; }

		bool IsInCategory(EventCategory eventCategory) const { return (GetCategoryFlags() & eventCategory); }

		virtual ~Event() = 0 { };

	private:
		std::string m_Name;
		EventType m_Type;
		int m_Category;
		bool m_IsHandled;
	};

	inline std::ostream& operator<<(std::ostream& os, const Event& event) { return os << event.ToString(); }
}