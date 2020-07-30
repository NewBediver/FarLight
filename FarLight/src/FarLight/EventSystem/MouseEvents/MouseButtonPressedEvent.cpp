// This is an open source non-commercial project. Dear PVS-Studio, please check it.
// PVS-Studio Static Code Analyzer for C, C++ and C#: http://www.viva64.com

#include "flpch.h"

#include "MouseButtonPressedEvent.h"

namespace FarLight
{
	std::string MouseButtonPressedEvent::ToString() const
	{
		std::stringstream ss;
		ss << GetName() << ": " << "(" << GetButton() << ").";
		return ss.str();
	}
}