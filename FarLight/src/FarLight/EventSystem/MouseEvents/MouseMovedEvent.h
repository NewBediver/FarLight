#pragma once

#include "FarLight/EventSystem/Event.h"

namespace FarLight
{
    class MouseMovedEvent final
        : public Event
    {
    public:
        explicit MouseMovedEvent(double&& xPosition, double&& yPosition) noexcept
            : Event("MouseMoved", EventType::MouseMovedEventType, MouseEventCategory | InputEventCategory)
            , m_XPosition(std::move(xPosition))
            , m_YPosition(std::move(yPosition))
        { }

        constexpr double MouseMovedEvent::GetX() const noexcept { return m_XPosition; }
        constexpr double MouseMovedEvent::GetY() const noexcept { return m_YPosition; }

        virtual std::string ToString() const noexcept override;

    private:
        double m_XPosition, m_YPosition;
    };
}
