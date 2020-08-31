// This is an open source non-commercial project. Dear PVS-Studio, please check it.
// PVS-Studio Static Code Analyzer for C, C++ and C#: http://www.viva64.com

#include "flpch.h"

#include "FarLight/EventSystem/KeyboardEvents/KeyboardKeyReleasedEvent.h"

namespace FarLight
{
    std::string KeyboardKeyReleasedEvent::ToString() const noexcept
    {
        std::stringstream ss;
        ss << GetName() << ": " << "(" << static_cast<int>(GetKeyCode()) << ").";
        return ss.str();
    }
}
