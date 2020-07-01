#include "flpch.h"

#include "Event.h"

namespace FarLight
{
	inline std::string Event::ToString() const { return GetName(); }
	inline bool Event::IsHandled() const { return _isHandled; }
	inline void Event::SetHandled(bool isHandled) { _isHandled = isHandled; }
	inline bool Event::IsInCategory(const EventCategory& category) const { return (GetCategoryFlags() & category); }
}