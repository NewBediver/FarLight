#pragma once

#include <spdlog/spdlog.h>
#include <spdlog/fmt/ostr.h>

namespace FarLight
{
	class Logger final
	{
	public:
		Logger() = delete;
		Logger(const Logger&) = delete;
		Logger(Logger&&) = delete;
		Logger& operator=(const Logger&) = delete;
		Logger& operator=(Logger&&) = delete;

		static void Init() noexcept;

		static constexpr
		const Ref<spdlog::logger>& GetCoreLogger() noexcept { return s_CoreLogger; }
		static constexpr
		const Ref<spdlog::logger>& GetClientLogger() noexcept { return s_ClientLogger; }
		
	private:
		static Ref<spdlog::logger> s_CoreLogger;
		static Ref<spdlog::logger> s_ClientLogger;
	};
}

#if FL_LOG
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
#else
	// Core log macros
	#define FL_CORE_TRACE(...)
	#define FL_CORE_INFO(...)
	#define FL_CORE_WARN(...)
	#define FL_CORE_ERROR(...)
	#define FL_CORE_CRITICAL(...)
	// Client log macros
	#define FL_TRACE(...)
	#define FL_INFO(...)
	#define FL_WARN(...)
	#define FL_ERROR(...)
	#define FL_CRITICAL(...)
#endif