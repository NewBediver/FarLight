#pragma once

#include "FarLight/EventSystem/Event.h"

namespace FarLight
{
    class WindowClosedEvent final
        : public Event
    {
    public:
        explicit WindowClosedEvent() noexcept
            : Event("WindowClosed", EventType::WindowClosedEventType, ApplicationEventCategory)
        { }
    };
}
