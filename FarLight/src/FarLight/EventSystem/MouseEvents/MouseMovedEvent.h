#pragma once

#include "FarLight/EventSystem/Event.h"

#include <sstream>

namespace FarLight
{

    class FARLIGHT_API MouseMovedEvent :
        public Event
    {
    public:
        MouseMovedEvent(double, double);
       
        static EventType GetStaticType();

        double GetX() const;
        double GetY() const;
        std::string ToString() const override;

        virtual EventType GetType() const override;
        virtual std::string GetName() const override;
        virtual int GetCategoryFlags() const override;

    private:
        double coordX, coordY;
    };

}