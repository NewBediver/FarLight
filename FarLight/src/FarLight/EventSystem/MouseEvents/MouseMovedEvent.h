#pragma once

#include "FarLight/EventSystem/Event.h"

namespace FarLight
{
    class FARLIGHT_API MouseMovedEvent :
        public Event
    {
    public:
        explicit MouseMovedEvent(const double xPos, const double yPos)
            : Event("MouseMoved", EventType::MouseMovedEventType, MouseEventCategory | InputEventCategory)
            , _xPos(xPos)
            , _yPos(yPos) { }

        const double MouseMovedEvent::GetX() const { return _xPos; }
        const double MouseMovedEvent::GetY() const { return _yPos; }

        virtual const std::string ToString() const override;

    private:
        double _xPos, _yPos;
    };
}