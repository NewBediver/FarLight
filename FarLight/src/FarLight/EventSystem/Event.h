#pragma once

#include <iostream>

#include "FarLight/Core/Core.h"
#include "FarLight/LogSystem/Logger.h"

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
		Event(const Event&) = delete;
		Event(Event&&) = delete;
		Event& operator=(const Event&) = delete;
		Event& operator=(Event&&) = delete;

		virtual ~Event() noexcept = 0
		{
			FL_CORE_INFO("Event [{0}] destroyed.", this->ToString());
		};

		virtual EventType GetType() const noexcept { return m_Type; };
		virtual const std::string& GetName() const noexcept { return m_Name; }
		virtual int GetCategoryFlags() const noexcept { return m_Category; };

		virtual std::string ToString() const noexcept { return GetName(); }

		constexpr
		bool IsHandled() const noexcept { return m_IsHandled; }
		constexpr
		void SetHandled(bool isHandled) noexcept { m_IsHandled = isHandled; }

		bool IsInCategory(EventCategory eventCategory) const noexcept { return (GetCategoryFlags() & eventCategory); }

	protected:
		explicit Event(const std::string& name, EventType type, int category) noexcept
			: m_Name(name)
			, m_Type(type)
			, m_Category(category)
			, m_IsHandled(false)
		{
			FL_CORE_INFO("Event [{0}] created.", this->ToString());
		}

	private:
		std::string m_Name;
		EventType m_Type;
		int m_Category;
		bool m_IsHandled;
	};

	inline std::ostream& operator<<(std::ostream& os, const Event& event) { return os << event.ToString(); }
}