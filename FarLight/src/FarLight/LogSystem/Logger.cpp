// This is an open source non-commercial project. Dear PVS-Studio, please check it.
// PVS-Studio Static Code Analyzer for C, C++ and C#: http://www.viva64.com

#include "flpch.h"

#include "FarLight/LogSystem/Logger.h"

#include <spdlog/sinks/stdout_color_sinks.h>
#include <spdlog/sinks/basic_file_sink.h>
#include <spdlog/common.h>

namespace FarLight
{
    void Logger::Initialize() noexcept
    {
        std::vector<spdlog::sink_ptr> logSinks;
        logSinks.emplace_back(std::make_shared<spdlog::sinks::stdout_color_sink_mt>());
        logSinks.emplace_back(std::make_shared<spdlog::sinks::basic_file_sink_mt>("FarLight.log", true));

        logSinks[0]->set_pattern("[%n] [%d.%m.%Y %H:%M:%S.%e] [%s:%#] [%!]: %^[%l] %v%$");
        logSinks[1]->set_pattern("[%n] [%d.%m.%Y %H:%M:%S.%e] [%s:%#] [%!]: %^[%l] %v%$");

        s_CoreLogger = CreateRef<spdlog::logger>("FarLight", begin(logSinks), end(logSinks));
        spdlog::register_logger(s_CoreLogger);
        s_CoreLogger->set_level(spdlog::level::trace);
        s_CoreLogger->flush_on(spdlog::level::trace);

        s_ClientLogger = CreateRef<spdlog::logger>("Application", begin(logSinks), end(logSinks));
        spdlog::register_logger(s_ClientLogger);
        s_ClientLogger->set_level(spdlog::level::trace);
        s_ClientLogger->flush_on(spdlog::level::trace);
    }
}
