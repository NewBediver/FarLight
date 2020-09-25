#pragma once

#include <chrono>

#include "FarLight/Abstraction/Singleton/Singleton.h"

namespace FarLight
{
    class Timer final
        : public Singleton<Timer>
    {
        friend class Singleton<Timer>;
        friend class Application;

    public:
        float GetDelta() const noexcept { return m_DeltaTime.count(); }

    private:
        explicit Timer() noexcept
            : m_DeltaTime(0.0f)
            , m_PreviousTime(std::chrono::steady_clock::now())
        { }

        void Update()
        {
            auto current = std::chrono::steady_clock::now();
            m_DeltaTime = current - m_PreviousTime;
            m_PreviousTime = current;
        }

        std::chrono::duration<float> m_DeltaTime;
        std::chrono::steady_clock::time_point m_PreviousTime;
    };
}
