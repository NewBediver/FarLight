#pragma once

#include "FarLight/EventSystem/KeyboardEvents/KeyboardKeyEvent.h"

#include "FarLight/InputSystem/KeyboardKeyCodes.h"

namespace FarLight
{
    class KeyboardKeyPressedEvent final
        : public KeyboardKeyEvent
    {
    public:
        explicit KeyboardKeyPressedEvent(KeyboardKeyCode&& keyCode, bool&& isRepeated) noexcept
            : KeyboardKeyEvent("KeyboardKeyPressed", EventType::KeyboardKeyPressedEventType)
            , m_KeyCode(std::move(keyCode))
            , m_IsRepeated(std::move(isRepeated))
        { }

        constexpr bool IsRepeated() const noexcept { return m_IsRepeated; }
        constexpr KeyboardKeyCode GetKeyCode() const noexcept { return m_KeyCode; }

        virtual std::string ToString() const noexcept override;

    private:
        KeyboardKeyCode m_KeyCode;
        bool m_IsRepeated;
    };
}
