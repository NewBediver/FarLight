#pragma once

#include "FarLight/Abstraction/Singleton/Singleton.h"

#include <spdlog/spdlog.h>
#include <spdlog/fmt/ostr.h>

namespace FarLight
{
    class Logger final
        : public Singleton<Logger>
    {
    public:
        void Initialize() noexcept;

        constexpr const Ref<spdlog::logger>& GetCoreLogger() noexcept { return s_CoreLogger; }
        constexpr const Ref<spdlog::logger>& GetClientLogger() noexcept { return s_ClientLogger; }

    private:
        Ref<spdlog::logger> s_CoreLogger = nullptr;
        Ref<spdlog::logger> s_ClientLogger = nullptr;
    };
}
