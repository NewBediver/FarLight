// This is an open source non-commercial project. Dear PVS-Studio, please check it.
// PVS-Studio Static Code Analyzer for C, C++ and C#: http://www.viva64.com

#include "flpch.h"

#include "Logger.h"

#include <spdlog/sinks/stdout_color_sinks.h>

namespace FarLight
{
	std::shared_ptr<spdlog::logger> Logger::s_CoreLogger = nullptr;
	std::shared_ptr<spdlog::logger> Logger::s_ClientLogger = nullptr;

	void Logger::Init()
	{
		spdlog::set_pattern("%^[%T] [%l] [%n] : %v%$");
		s_CoreLogger = spdlog::stdout_color_mt("FarLight");
		s_CoreLogger->set_level(spdlog::level::trace);

		s_ClientLogger = spdlog::stdout_color_mt("Application");
		s_ClientLogger->set_level(spdlog::level::trace);
	}
}