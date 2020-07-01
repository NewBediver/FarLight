#pragma once

#include "FarLight/EventSystem/Event.h"

namespace FarLight
{
    class FARLIGHT_API MouseMovedEvent :
        public Event
    {
    public:
        explicit MouseMovedEvent(double xPos, double yPos);
       
        static EventType GetStaticType();

        double GetX() const;
        double GetY() const;
        std::string ToString() const override;

        virtual EventType GetType() const override;
        virtual std::string GetName() const override;
        virtual int GetCategoryFlags() const override;

    private:
        double _xPos, _yPos;
    };
}