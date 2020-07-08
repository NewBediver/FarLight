#include "flpch.h"

#include "Logger.h"

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