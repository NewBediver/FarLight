#pragma once

#include "FarLight/EventSystem/MouseEvents/MouseButtonEvent.h"

namespace FarLight
{
    class MouseButtonPressedEvent final
        : public MouseButtonEvent
    {
    public:
        explicit MouseButtonPressedEvent(MouseButtonCode&& button) noexcept
            : MouseButtonEvent(std::move(button), "MouseButtonPressed", EventType::MouseButtonPressedEventType)
        { }

        virtual std::string ToString() const noexcept override;
    };
}
