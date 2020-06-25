#include "Logger.h"

namespace FarLight
{
	std::shared_ptr<spdlog::logger> Logger::s_CoreLogger;
	std::shared_ptr<spdlog::logger> Logger::s_ClientLogger;

	inline std::shared_ptr<spdlog::logger>& Logger::GetCoreLogger() { return s_CoreLogger; }
	inline std::shared_ptr<spdlog::logger>& Logger::GetClientLogger() { return s_ClientLogger; }

	void Logger::Init()
	{
		spdlog::set_pattern("%^[%T] [%l] [%n] : %v%$");

		s_CoreLogger = spdlog::stdout_color_mt("FarLight");
		s_CoreLogger->set_level(spdlog::level::trace);

		s_ClientLogger = spdlog::stdout_color_mt("Application");
		s_ClientLogger->set_level(spdlog::level::trace);
	}

}
