#pragma once

#include <string>
#include <chrono>
#include <functional>

namespace FarLight
{
	class InstrumentationTimer final
	{
	public:
		InstrumentationTimer(const InstrumentationTimer&) = delete;
		InstrumentationTimer(InstrumentationTimer&&) = delete;
		InstrumentationTimer& operator=(const InstrumentationTimer&) = delete;
		InstrumentationTimer& operator=(InstrumentationTimer&&) = delete;

		explicit InstrumentationTimer(const std::string& name) noexcept;

		~InstrumentationTimer() noexcept;

	private:
		std::string m_Name;
		std::chrono::time_point<std::chrono::steady_clock> m_StartTimepoint;
	};
}