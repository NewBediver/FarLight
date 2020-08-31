// This is an open source non-commercial project. Dear PVS-Studio, please check it.
// PVS-Studio Static Code Analyzer for C, C++ and C#: http://www.viva64.com

#include "flpch.h"

#include "FarLight/EventSystem/KeyboardEvents/KeyboardKeyPressedEvent.h"

namespace FarLight
{
    std::string KeyboardKeyPressedEvent::ToString() const noexcept
    {
        std::stringstream ss;
        ss << std::boolalpha << GetName() << ": " << "(" << static_cast<int>(GetKeyCode()) << "). " << "Is repeated: " << IsRepeated() << ".";
        return ss.str();
    }
}
