#pragma once

#include <string>
#include <fstream>
#include <chrono>

#include "FarLight/Core/Core.h"

namespace FarLight
{
	struct ProfileResult
	{
		std::string m_Name;
		std::chrono::duration<double, std::micro> m_Start;
		std::chrono::microseconds m_Duration;
		std::thread::id m_ThreadId;
	};

	class Instrumentor
	{
	public:
		void BeginSession(const std::string& name, const std::string& filepath = "results.json");
		void EndSession();

		static const Scope<Instrumentor>& GetInstance();

	private:
		Instrumentor();
		Instrumentor(const Instrumentor&) = delete;
		Instrumentor(Instrumentor&&) = delete;
		Instrumentor& operator=(const Instrumentor&) = delete;
		Instrumentor& operator=(Instrumentor&&) = delete;

		void WriteProfile(const ProfileResult& result);

		void WriteHeader();
		void WriteFooter();

		void InternalEndSession();

		struct InstrumentationSession
		{
			std::string m_Name;

			InstrumentationSession(const std::string& name)
				: m_Name(name)
			{ }
		};
		
		Scope<InstrumentationSession> m_CurrentSession;
		std::ofstream m_OutputStream;
		std::mutex m_Mutex;

		static Scope<Instrumentor> s_Instance;

		friend class InstrumentationTimer;
	};
}

#if FL_PROFILE
	#define FL_PROFILE_BEGIN_SESSION(name, filepath) ::FarLight::Instrumentor::GetInstance()->BeginSession(name, filepath)
	#define FL_PROFILE_END_SESSION() ::FarLight::Instrumentor::GetInstance()->EndSession()
	#define FL_PROFILE_SCOPE(name) ::FarLight::InstrumentationTimer timer##__LINE__(name);
	#define FL_PROFILE_FUNCTION() FL_PROFILE_SCOPE(FL_FUNC_SIG)
#else
	#define FL_PROFILE_BEGIN_SESSION(name, filepath)
	#define FL_PROFILE_END_SESSION()
	#define FL_PROFILE_SCOPE(name)
	#define FL_PROFILE_FUNCTION()
#endif 