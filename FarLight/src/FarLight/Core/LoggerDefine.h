#pragma once

#if FL_LOG
    // Core log macros
#   define FL_CORE_TRACE(...)    ::FarLight::Logger::GetInstance().GetCoreLogger()->log(spdlog::source_loc(__FILE__, __LINE__, FL_FUNC_SIG), spdlog::level::level_enum::trace, __VA_ARGS__)
#   define FL_CORE_DEBUG(...)    ::FarLight::Logger::GetInstance().GetCoreLogger()->log(spdlog::source_loc(__FILE__, __LINE__, FL_FUNC_SIG), spdlog::level::level_enum::debug, __VA_ARGS__)
#   define FL_CORE_INFO(...)     ::FarLight::Logger::GetInstance().GetCoreLogger()->log(spdlog::source_loc(__FILE__, __LINE__, FL_FUNC_SIG), spdlog::level::level_enum::info, __VA_ARGS__)
#   define FL_CORE_WARN(...)     ::FarLight::Logger::GetInstance().GetCoreLogger()->log(spdlog::source_loc(__FILE__, __LINE__, FL_FUNC_SIG), spdlog::level::level_enum::warn, __VA_ARGS__)
#   define FL_CORE_ERROR(...)    ::FarLight::Logger::GetInstance().GetCoreLogger()->log(spdlog::source_loc(__FILE__, __LINE__, FL_FUNC_SIG), spdlog::level::level_enum::err, __VA_ARGS__)
#   define FL_CORE_CRITICAL(...) ::FarLight::Logger::GetInstance().GetCoreLogger()->log(spdlog::source_loc(__FILE__, __LINE__, FL_FUNC_SIG), spdlog::level::level_enum::critical, __VA_ARGS__)
    // Client log macros
#   define FL_TRACE(...)         ::FarLight::Logger::GetInstance().GetClientLogger()->log(spdlog::source_loc(__FILE__, __LINE__, FL_FUNC_SIG), spdlog::level::level_enum::trace, __VA_ARGS__)
#   define FL_DEBUG(...)         ::FarLight::Logger::GetInstance().GetClientLogger()->log(spdlog::source_loc(__FILE__, __LINE__, FL_FUNC_SIG), spdlog::level::level_enum::debug, __VA_ARGS__)
#   define FL_INFO(...)          ::FarLight::Logger::GetInstance().GetClientLogger()->log(spdlog::source_loc(__FILE__, __LINE__, FL_FUNC_SIG), spdlog::level::level_enum::info, __VA_ARGS__)
#   define FL_WARN(...)          ::FarLight::Logger::GetInstance().GetClientLogger()->log(spdlog::source_loc(__FILE__, __LINE__, FL_FUNC_SIG), spdlog::level::level_enum::warn, __VA_ARGS__)
#   define FL_ERROR(...)         ::FarLight::Logger::GetInstance().GetClientLogger()->log(spdlog::source_loc(__FILE__, __LINE__, FL_FUNC_SIG), spdlog::level::level_enum::err, __VA_ARGS__)
#   define FL_CRITICAL(...)      ::FarLight::Logger::GetInstance().GetClientLogger()->log(spdlog::source_loc(__FILE__, __LINE__, FL_FUNC_SIG), spdlog::level::level_enum::critical, __VA_ARGS__)
#else
    // Core log macros
#   define FL_CORE_TRACE(...)
#   define FL_CORE_INFO(...)
#   define FL_CORE_WARN(...)
#   define FL_CORE_ERROR(...)
#   define FL_CORE_CRITICAL(...)
    // Client log macros
#   define FL_TRACE(...)
#   define FL_INFO(...)
#   define FL_WARN(...)
#   define FL_ERROR(...)
#   define FL_CRITICAL(...)
#endif
