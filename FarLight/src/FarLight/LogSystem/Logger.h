#pragma once

#include "FarLight/Core/Core.h"

#include <spdlog/spdlog.h>
#include <spdlog/fmt/ostr.h>

namespace FarLight
{
	class  Logger
	{
	public:
		static void Init();

		static const std::shared_ptr<spdlog::logger>& GetCoreLogger() { return s_CoreLogger; }
		static const std::shared_ptr<spdlog::logger>& GetClientLogger() { return s_ClientLogger; }
		
	private:
		static std::shared_ptr<spdlog::logger> s_CoreLogger;
		static std::shared_ptr<spdlog::logger> s_ClientLogger;
	};
}

// Core log macros
#define FL_CORE_TRACE(...)    ::FarLight::Logger::GetCoreLogger()->trace(__VA_ARGS__);
#define FL_CORE_INFO(...)     ::FarLight::Logger::GetCoreLogger()->info(__VA_ARGS__);
#define FL_CORE_WARN(...)     ::FarLight::Logger::GetCoreLogger()->warn(__VA_ARGS__);
#define FL_CORE_ERROR(...)    ::FarLight::Logger::GetCoreLogger()->error(__VA_ARGS__);
#define FL_CORE_CRITICAL(...) ::FarLight::Logger::GetCoreLogger()->critical(__VA_ARGS__);

// Client log macros
#define FL_TRACE(...)    ::FarLight::Logger::GetClientLogger()->trace(__VA_ARGS__);
#define FL_INFO(...)     ::FarLight::Logger::GetClientLogger()->info(__VA_ARGS__);
#define FL_WARN(...)     ::FarLight::Logger::GetClientLogger()->warn(__VA_ARGS__);
#define FL_ERROR(...)    ::FarLight::Logger::GetClientLogger()->error(__VA_ARGS__);
#define FL_CRITICAL(...) ::FarLight::Logger::GetClientLogger()->critical(__VA_ARGS__);