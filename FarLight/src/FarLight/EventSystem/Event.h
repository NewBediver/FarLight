#pragma once

#include "FarLight/Core.h"
#include "EventEnums.h"

#include <string>
#include <ostream>

namespace FarLight
{

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

		virtual std::string ToString() const;

		bool IsInCategory(const EventCategory&) const;

	protected:
		bool isHandled = false;
	};

	inline std::ostream& operator<<(std::ostream& os, const Event& event)
	{
		return os << event.ToString();
	}

}