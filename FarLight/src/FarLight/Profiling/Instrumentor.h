#pragma once

#include <string>
#include <fstream>
#include <chrono>

#include "FarLight/Profiling/InstrumentationTimer.h"

#include "FarLight/Core/Core.h"
#include "FarLight/Core/Defines.h"

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
    {
    public:
        static Instrumentor& GetInstance() noexcept
        {
            static Instrumentor s_Instance;
            return s_Instance;
        }

        Instrumentor(const Instrumentor&) = delete;
        Instrumentor(Instrumentor&&) = delete;
        Instrumentor& operator=(const Instrumentor&) = delete;
        Instrumentor& operator=(Instrumentor&&) = delete;

        ~Instrumentor() noexcept;

        void BeginSession(std::string&& name, std::string&& filepath = "results.json") noexcept;
        void EndSession() noexcept;

    private:
        explicit Instrumentor() noexcept;

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

        friend class InstrumentationTimer;
    };
}
