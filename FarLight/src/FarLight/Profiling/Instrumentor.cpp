// This is an open source non-commercial project. Dear PVS-Studio, please check it.
// PVS-Studio Static Code Analyzer for C, C++ and C#: http://www.viva64.com

#include "flpch.h"

#include "FarLight/Profiling/Instrumentor.h"

namespace FarLight
{
    Instrumentor::~Instrumentor() noexcept
    {
        EndSession();
    }

    void Instrumentor::BeginSession(std::string&& name, std::string&& filepath) noexcept
    {
        std::lock_guard lock(m_Mutex);
        if (m_CurrentSession) {
            if (Logger::GetInstancePtr() != nullptr) FL_CORE_ERROR("Instrumentor::BeginSession('{0}') when session '{1}' already open.", name, m_CurrentSession->Name);
            InternalEndSession();
        }
        m_OutputStream.open(std::move(filepath));
        if (m_OutputStream.is_open()) {
            m_CurrentSession = CreateScope<InstrumentationSession>(std::move(name));
            WriteHeader();
        }
        else {
            if (Logger::GetInstancePtr() != nullptr) FL_CORE_ERROR("Instrumentor {0} could not open results file!", name);
        }
    }

    void Instrumentor::EndSession() noexcept
    {
        std::lock_guard lock(m_Mutex);
        InternalEndSession();
    }

    void Instrumentor::WriteProfile(const ProfileResult& result) noexcept
    {
        std::string name = result.Name;
        std::replace(name.begin(), name.end(), '"', '\'');

        std::stringstream json;
        json << std::setprecision(3) << std::fixed;
        json << ",{";
        json << "\"cat\":\"function\",";
        json << "\"dur\":" << (result.Duration.count()) << ',';
        json << "\"name\":\"" << name << "\",";
        json << "\"ph\":\"X\",";
        json << "\"pid\":0,";
        json << "\"tid\":" << result.ThreadId << ",";
        json << "\"ts\":" << result.Start.count();
        json << "}";

        std::lock_guard lock(m_Mutex);
        if (m_CurrentSession) {
            m_OutputStream << json.str();
            m_OutputStream.flush();
        }
    }

    void Instrumentor::WriteHeader() noexcept
    {
        m_OutputStream << "{\"otherData\": {},\"traceEvents\":[{}";
        m_OutputStream.flush();
    }

    void Instrumentor::WriteFooter() noexcept
    {
        m_OutputStream << "]}";
        m_OutputStream.flush();
    }

    void Instrumentor::InternalEndSession() noexcept
    {
        if (m_CurrentSession) {
            WriteFooter();
            m_OutputStream.close();
            m_CurrentSession.reset(nullptr);
        }
    }
}
