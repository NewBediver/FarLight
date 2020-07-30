#pragma once

#include "FarLight/Core/Core.h"

namespace FarLight
{
	struct WindowProps
	{
		std::string m_Title;
		unsigned int m_Width;
		unsigned int m_Height;

		explicit WindowProps(const std::string& title = "FarLight Engine", unsigned int width = 1280, unsigned int height = 720)
			: m_Title(title)
			, m_Width(width)
			, m_Height(height)
		{ }
	};
}