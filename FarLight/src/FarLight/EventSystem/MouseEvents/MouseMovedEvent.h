#pragma once

#include "FarLight/EventSystem/Event.h"

namespace FarLight
{
    class MouseMovedEvent final
        : public Event
    {
    public:
        explicit MouseMovedEvent(double xPosition, double yPosition)
            : Event("MouseMoved", EventType::MouseMovedEventType, MouseEventCategory | InputEventCategory)
            , m_XPosition(xPosition)
            , m_YPosition(yPosition)
        { }

        double MouseMovedEvent::GetX() const { return m_XPosition; }
        double MouseMovedEvent::GetY() const { return m_YPosition; }

        virtual std::string ToString() const override;

    private:
        double m_XPosition, m_YPosition;
    };
}