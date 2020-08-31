#pragma once

#include "FarLight/EventSystem/KeyboardEvents/KeyboardKeyEvent.h"

#include "FarLight/InputSystem/KeyboardKeyCodes.h"

namespace FarLight
{
    class KeyboardKeyReleasedEvent final
        : public KeyboardKeyEvent
    {
    public:
        explicit KeyboardKeyReleasedEvent(KeyboardKeyCode&& keyCode) noexcept
            : KeyboardKeyEvent("KeyboardKeyReleased", EventType::KeyboardKeyReleasedEventType)
            , m_KeyCode(std::move(keyCode))
        { }

        constexpr KeyboardKeyCode GetKeyCode() const noexcept { return m_KeyCode; }

        virtual std::string ToString() const noexcept override;

    private:
        KeyboardKeyCode m_KeyCode;
    };
}
