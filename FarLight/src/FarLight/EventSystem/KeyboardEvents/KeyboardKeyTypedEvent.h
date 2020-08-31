#pragma once

#include "FarLight/EventSystem/KeyboardEvents/KeyboardKeyEvent.h"

namespace FarLight
{
    class KeyboardKeyTypedEvent final
        : public KeyboardKeyEvent
    {
    public:
        explicit KeyboardKeyTypedEvent(unsigned&& typedCode) noexcept
            : KeyboardKeyEvent("KeyboardKeyTyped", EventType::KeyboardKeyTypedEventType)
            , m_TypedCode(typedCode)
        { }

        constexpr unsigned GetTypedCode() const noexcept { return m_TypedCode; }

        virtual std::string ToString() const noexcept override;

    private:
        unsigned m_TypedCode;
    };
}
