#pragma once

#include "flpch.h"

#include "FarLight/Core.h"
#include "EventEnums.h"

namespace FarLight
{
	/*
	Simple blocking events.
	Later some kind of Event Buffer will be created.
	*/

	// TODO: Event buffer

	class FARLIGHT_API Event
	{
		friend class EventDispatcher;

	public:
		virtual EventType GetType() const = 0;
		virtual std::string GetName() const = 0;
		virtual int GetCategoryFlags() const = 0;

		virtual std::string ToString() const;

		bool IsInCategory(const EventCategory& eventCategory) const;

		virtual ~Event() = default;

	protected:
		bool isHandled = false;
	};

	extern std::ostream& operator<<(std::ostream& os, const Event& event);
}