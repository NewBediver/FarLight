// This is an open source non-commercial project. Dear PVS-Studio, please check it.
// PVS-Studio Static Code Analyzer for C, C++ and C#: http://www.viva64.com

#include "flpch.h"

#include "Instrumentor.h"

namespace FarLight
{
	Instrumentor& Instrumentor::GetInstance()
	{
		static Instrumentor s_Instance;
		return s_Instance;
	}

	Instrumentor::Instrumentor()
		: m_CurrentSession(nullptr)
	{ }

	Instrumentor::~Instrumentor()
	{
		EndSession();
	}

	void Instrumentor::BeginSession(const std::string& name, const std::string& filepath)
	{
		std::lock_guard lock(m_Mutex);
		if (m_CurrentSession) {
			if (Logger::GetCoreLogger()) FL_CORE_ERROR("Instrumentor::BeginSession('{0}') when session '{1}' already open.", name, m_CurrentSession->m_Name);
			InternalEndSession();
		}
		m_OutputStream.open(filepath);
		if (m_OutputStream.is_open()) {
			m_CurrentSession = CreateScope<InstrumentationSession>(name);
			WriteHeader();
		}
		else {
			if (Logger::GetCoreLogger()) FL_CORE_ERROR("Instrumentor could not open results file '{0}'.", filepath);
		}
	}

	void Instrumentor::EndSession()
	{
		std::lock_guard lock(m_Mutex);
		InternalEndSession();
	}

	void Instrumentor::WriteProfile(const ProfileResult& result)
	{
		std::stringstream json;

		std::string name = result.m_Name;
		std::replace(name.begin(), name.end(), '"', '\'');

		json << std::setprecision(3) << std::fixed;
		json << ",{";
		json << "\"cat\":\"function\",";
		json << "\"dur\":" << (result.m_Duration.count()) << ',';
		json << "\"name\":\"" << name << "\",";
		json << "\"ph\":\"X\",";
		json << "\"pid\":0,";
		json << "\"tid\":" << result.m_ThreadId << ",";
		json << "\"ts\":" << result.m_Start.count();
		json << "}";

		std::lock_guard lock(m_Mutex);
		if (m_CurrentSession) {
			m_OutputStream << json.str();
			m_OutputStream.flush();
		}
	}

	void Instrumentor::WriteHeader()
	{
		m_OutputStream << "{\"otherData\": {},\"traceEvents\":[{}";
		m_OutputStream.flush();
	}

	void Instrumentor::WriteFooter()
	{
		m_OutputStream << "]}";
		m_OutputStream.flush();
	}

	void Instrumentor::InternalEndSession() {
		if (m_CurrentSession) {
			WriteFooter();
			m_OutputStream.close();
			m_CurrentSession.reset(nullptr);
		}
	}
}