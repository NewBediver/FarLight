#pragma once

#include <string>
#include <chrono>

namespace FarLight
{
    class InstrumentationTimer final
    {
    public:
        explicit InstrumentationTimer(std::string&& name) noexcept
            : m_Name(std::move(name))
            , m_StartTimepoint(std::chrono::steady_clock::now())
        { }

        ~InstrumentationTimer() noexcept;

    private:
        std::string m_Name;
        std::chrono::time_point<std::chrono::steady_clock> m_StartTimepoint;
    };
}
