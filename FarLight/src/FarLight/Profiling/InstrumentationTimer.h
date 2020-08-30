#pragma once

#include <string>
#include <chrono>

namespace FarLight
{
    class InstrumentationTimer final
    {
    public:
        explicit InstrumentationTimer(std::string&& name) noexcept;

        ~InstrumentationTimer() noexcept;

    private:
        std::string m_Name;
        std::chrono::time_point<std::chrono::steady_clock> m_StartTimepoint;
    };
}
