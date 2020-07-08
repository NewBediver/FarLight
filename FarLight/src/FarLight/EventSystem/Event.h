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