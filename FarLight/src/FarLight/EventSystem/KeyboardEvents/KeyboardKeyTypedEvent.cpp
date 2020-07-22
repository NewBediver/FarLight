#include "flpch.h"

#include "KeyboardKeyTypedEvent.h"

namespace FarLight
{
    const std::string KeyboardKeyTypedEvent::ToString() const
    {
        std::stringstream ss;
        ss << GetName() << ": " << "(" << GetKeyCode() << ").";
        return ss.str();
    }
}