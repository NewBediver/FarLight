#include "flpch.h"
#include "WindowClosedEvent.h"

namespace FarLight
{
    EventType WindowClosedEvent::GetStaticType() { return EventType::WindowClosedEventType; }

    inline EventType WindowClosedEvent::GetType() const { return GetStaticType(); }
    inline std::string WindowClosedEvent::GetName() const { return "WindowClosed"; }
    inline int WindowClosedEvent::GetCategoryFlags() const { return EventCategory::ApplicationEventCategory; }
}