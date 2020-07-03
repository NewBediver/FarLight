#include "flpch.h"
#include "KeyboardKeyTypedEvent.h"


namespace FarLight
{
    KeyboardKeyTypedEvent::KeyboardKeyTypedEvent(int keyCode)
        : KeyboardKeyEvent(keyCode) { }

    inline EventType KeyboardKeyTypedEvent::GetStaticType() { return EventType::KeyboardKeyTypedEventType; }

    std::string KeyboardKeyTypedEvent::ToString() const
    {
        std::stringstream ss;
        ss << "KeyboardKeyTypedEvent: " << "(" << GetKeyCode() << ").";
        return ss.str();
    }

    inline EventType KeyboardKeyTypedEvent::GetType() const { return GetStaticType(); }
    inline std::string KeyboardKeyTypedEvent::GetName() const { return "KeyboardKeyTyped"; }
}