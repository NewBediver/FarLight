// This is an open source non-commercial project. Dear PVS-Studio, please check it.
// PVS-Studio Static Code Analyzer for C, C++ and C#: http://www.viva64.com

#include "flpch.h"

#include "KeyboardKeyPressedEvent.h"

namespace FarLight
{
	std::string KeyboardKeyPressedEvent::ToString() const
	{
		std::stringstream ss;
		ss << std::boolalpha << GetName() << ": " << "(" << GetKeyCode() << "). " << "Is repeated: " << IsRepeated() << ".";
		return ss.str();
	}
}