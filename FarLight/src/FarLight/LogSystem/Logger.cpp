// This is an open source non-commercial project. Dear PVS-Studio, please check it.
// PVS-Studio Static Code Analyzer for C, C++ and C#: http://www.viva64.com

#include "flpch.h"

#include "Logger.h"

#include <spdlog/sinks/stdout_color_sinks.h>

namespace FarLight
{
	std::shared_ptr<spdlog::logger> Logger::_CoreLogger;
	std::shared_ptr<spdlog::logger> Logger::_ClientLogger;

	void Logger::Init()
	{
		spdlog::set_pattern("%^[%T] [%l] [%n] : %v%$");
		_CoreLogger = spdlog::stdout_color_mt("FarLight");
		_CoreLogger->set_level(spdlog::level::trace);

		_ClientLogger = spdlog::stdout_color_mt("Application");
		_ClientLogger->set_level(spdlog::level::trace);
	}
}