// This is an open source non-commercial project. Dear PVS-Studio, please check it.
// PVS-Studio Static Code Analyzer for C, C++ and C#: http://www.viva64.com

#include "flpch.h"

#include "KeyboardKeyReleasedEvent.h"

namespace FarLight
{
	const std::string KeyboardKeyReleasedEvent::ToString() const
	{
		std::stringstream ss;
		ss << GetName() << ": " << "(" << GetKeyCode() << ").";
		return ss.str();
	}
}