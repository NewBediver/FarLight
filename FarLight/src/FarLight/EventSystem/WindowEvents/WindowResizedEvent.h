#pragma once

#include "FarLight/EventSystem/Event.h"

namespace FarLight
{
    class WindowResizedEvent final
        : public Event
    {
    public:
        explicit WindowResizedEvent(unsigned&& width, unsigned&& height) noexcept
            : Event("WindowResized", EventType::WindowResizedEventType, ApplicationEventCategory)
            , m_Width(std::move(width))
            , m_Height(std::move(height))
        { }

        constexpr unsigned WindowResizedEvent::GetWidth() const noexcept { return m_Width; }
        constexpr unsigned WindowResizedEvent::GetHeight() const noexcept { return m_Height; }

        virtual std::string ToString() const noexcept override;

    private:
        unsigned m_Width, m_Height;
    };
}
