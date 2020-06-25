#include "Event.h"

namespace FarLight
{

	inline std::string Event::ToString() const { return GetName(); }
	inline bool Event::IsInCategory(const EventCategory& category) const { return (GetCategoryFlags() & category); }

}