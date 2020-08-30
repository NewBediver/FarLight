#pragma once

#include "FarLight/EventSystem/Event.h"

namespace FarLight
{
    class MouseButtonEvent
        : public Event
    {
    public:
        virtual ~MouseButtonEvent() noexcept = 0 { };

        constexpr int GetButton() const noexcept { return m_Button; }

    protected:
        explicit MouseButtonEvent(int&& button, std::string&& name, EventType&& type) noexcept
            : Event(std::move(name), std::move(type), InputEventCategory | MouseEventCategory | MouseButtonEventCategory)
            , m_Button(std::move(button))
        { }

    private:
        int m_Button;
    };
}
