#pragma once

#include "FarLight/EventSystem/MouseEvents/MouseButtonEvent.h"

namespace FarLight
{
    class MouseButtonReleasedEvent final
        : public MouseButtonEvent
    {
    public:
        explicit MouseButtonReleasedEvent(int&& button) noexcept
            : MouseButtonEvent(std::move(button), "MouseButtonReleased", EventType::MouseButtonReleasedEventType)
        { }

        virtual std::string ToString() const noexcept override;
    };
}
