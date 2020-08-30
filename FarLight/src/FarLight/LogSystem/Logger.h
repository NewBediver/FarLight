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

        static constexpr const Ref<spdlog::logger>& GetCoreLogger() noexcept { return s_CoreLogger; }
        static constexpr const Ref<spdlog::logger>& GetClientLogger() noexcept { return s_ClientLogger; }

    private:
        static Ref<spdlog::logger> s_CoreLogger;
        static Ref<spdlog::logger> s_ClientLogger;
    };
}
