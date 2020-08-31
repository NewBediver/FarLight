#pragma once

#include "FarLight/EventSystem/Event.h"

namespace FarLight
{
    class KeyboardKeyEvent
        : public Event
    {
    public:
        virtual ~KeyboardKeyEvent() noexcept = 0 { };

    protected:
        explicit KeyboardKeyEvent(std::string&& name, EventType&& type) noexcept
            : Event(std::move(name), std::move(type), KeyboardEventCategory | InputEventCategory)
        { }
    };
}
