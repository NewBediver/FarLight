#include "flpch.h"

#include "Event.h"

namespace FarLight
{
	inline std::string Event::ToString() const { return GetName(); }
	inline bool Event::IsInCategory(const EventCategory& category) const { return (GetCategoryFlags() & category); }

	inline std::ostream& operator<<(std::ostream& os, const Event& event) { return os << event.ToString(); }
}