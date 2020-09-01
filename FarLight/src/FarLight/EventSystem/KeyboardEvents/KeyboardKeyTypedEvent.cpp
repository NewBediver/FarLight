// This is an open source non-commercial project. Dear PVS-Studio, please check it.
// PVS-Studio Static Code Analyzer for C, C++ and C#: http://www.viva64.com

#include "flpch.h"

#include "FarLight/EventSystem/KeyboardEvents/KeyboardKeyTypedEvent.h"

namespace FarLight
{
    std::string KeyboardKeyTypedEvent::ToString() const noexcept
    {
        std::stringstream ss;
        ss << GetName() << ": " << "(" << GetTypedCode() << ").";
        return ss.str();
    }
}
