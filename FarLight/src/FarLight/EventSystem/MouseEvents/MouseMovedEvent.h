#pragma once

#include "FarLight/EventSystem/Event.h"

namespace FarLight
{
    class FARLIGHT_API MouseMovedEvent :
        public Event
    {
    public:
        explicit MouseMovedEvent(double xPos, double yPos)
            : _xPos(xPos), _yPos(yPos) { }
       
        static EventType GetStaticType() { return EventType::MouseMovedEventType; }

        double MouseMovedEvent::GetX() const { return _xPos; }
        double MouseMovedEvent::GetY() const { return _yPos; }
        std::string ToString() const override;

        virtual EventType MouseMovedEvent::GetType() const override { return GetStaticType(); }
        virtual std::string MouseMovedEvent::GetName() const override { return "MouseMoved"; }
        virtual int MouseMovedEvent::GetCategoryFlags() const override { return (MouseEventCategory | InputEventCategory); }

    private:
        double _xPos, _yPos;
    };
}