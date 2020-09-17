#pragma once

#include <string>
#include <fstream>
#include <chrono>
#include <mutex>
#include <sstream>

#include "FarLight/Profiling/InstrumentationTimer.h"

#include "FarLight/Abstraction/Singleton/Singleton.h"

#include "FarLight/Core/Core.h"

namespace FarLight
{
    struct ProfileResult final
    {
        std::string Name;
        std::chrono::duration<double, std::micro> Start;
        std::chrono::microseconds Duration;
        std::thread::id ThreadId;
    };

    class Instrumentor final
        : public Singleton<Instrumentor>
    {
        friend class Singleton<Instrumentor>;
        friend class InstrumentationTimer;

    public:
        ~Instrumentor() noexcept;

        void BeginSession(std::string&& name, std::string&& filepath = "results.json") noexcept;
        void EndSession() noexcept;

    private:
        explicit Instrumentor() noexcept
            : m_CurrentSession(nullptr)
        { }

        void WriteProfile(const ProfileResult& result) noexcept;

        void WriteHeader() noexcept;
        void WriteFooter() noexcept;

        void InternalEndSession() noexcept;

        struct InstrumentationSession final
        {
            std::string Name;

            explicit InstrumentationSession(std::string&& name) noexcept
                : Name(std::move(name))
            { }
        };

        Scope<InstrumentationSession> m_CurrentSession;
        std::ofstream m_OutputStream;
        std::mutex m_Mutex;
    };
}
