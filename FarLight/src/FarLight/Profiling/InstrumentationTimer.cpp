// This is an open source non-commercial project. Dear PVS-Studio, please check it.
// PVS-Studio Static Code Analyzer for C, C++ and C#: http://www.viva64.com

#include "flpch.h"

#include "FarLight/Profiling/InstrumentationTimer.h"
#include "FarLight/Profiling/Instrumentor.h"

namespace FarLight
{
    InstrumentationTimer::~InstrumentationTimer() noexcept
    {
        auto endTimepoint = std::chrono::steady_clock::now();
        auto highResStart = std::chrono::duration<double, std::micro>(m_StartTimepoint.time_since_epoch());
        auto elapsedTime = std::chrono::time_point_cast<std::chrono::microseconds>(endTimepoint).time_since_epoch() - std::chrono::time_point_cast<std::chrono::microseconds>(m_StartTimepoint).time_since_epoch();

        Instrumentor::GetInstance().WriteProfile({ m_Name, highResStart, elapsedTime, std::this_thread::get_id() });
    }
}
