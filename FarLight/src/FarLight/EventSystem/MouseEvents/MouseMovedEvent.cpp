// This is an open source non-commercial project. Dear PVS-Studio, please check it.
// PVS-Studio Static Code Analyzer for C, C++ and C#: http://www.viva64.com

#include "flpch.h"

#include "FarLight/EventSystem/MouseEvents/MouseMovedEvent.h"

namespace FarLight
{
    std::string MouseMovedEvent::ToString() const noexcept
    {
        std::stringstream ss;
        ss.precision(3);
        ss << std::fixed << GetName() << ": " << "(" << GetX() << ", " << GetY() << ").";
        return ss.str();
    }
}
