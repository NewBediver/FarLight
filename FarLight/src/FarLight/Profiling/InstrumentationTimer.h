#pragma once

#include <string>
#include <chrono>
#include <functional>

namespace FarLight
{
	class InstrumentationTimer final
	{
	public:
		explicit InstrumentationTimer(const std::string& name);

		~InstrumentationTimer();

	private:
		std::string m_Name;
		std::chrono::time_point<std::chrono::steady_clock> m_StartTimepoint;
	};
}