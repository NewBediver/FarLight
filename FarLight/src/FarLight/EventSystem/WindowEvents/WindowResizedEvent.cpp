// This is an open source non-commercial project. Dear PVS-Studio, please check it.
// PVS-Studio Static Code Analyzer for C, C++ and C#: http://www.viva64.com

#include "flpch.h"

#include "WindowResizedEvent.h"

namespace FarLight
{
	const std::string WindowResizedEvent::ToString() const
	{
		std::stringstream ss;
		ss << GetName() << ": " << "(" << _width << ", " << _height << ").";
		return ss.str();
	}
}