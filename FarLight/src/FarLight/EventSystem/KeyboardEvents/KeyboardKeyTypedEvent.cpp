#include "flpch.h"

#include "KeyboardKeyTypedEvent.h"

namespace FarLight
{
    std::string KeyboardKeyTypedEvent::ToString() const
    {
        std::stringstream ss;
        ss << "KeyboardKeyTypedEvent: " << "(" << GetKeyCode() << ").";
        return ss.str();
    }
}