#pragma once

#include <string>
#include <fstream>
#include <chrono>

#include "FarLight/Core/Core.h"
#include "InstrumentationTimer.h"

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
		static Instrumentor& GetInstance() noexcept;

		Instrumentor(const Instrumentor&) = delete;
		Instrumentor(Instrumentor&&) = delete;
		Instrumentor& operator=(const Instrumentor&) = delete;
		Instrumentor& operator=(Instrumentor&&) = delete;

		~Instrumentor() noexcept;

		void BeginSession(const std::string& name, const std::string& filepath = "results.json") noexcept;
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

			explicit InstrumentationSession(const std::string& name) noexcept
				: Name(name)
			{ }
		};
		
		Scope<InstrumentationSession> m_CurrentSession;
		std::ofstream m_OutputStream;
		std::mutex m_Mutex;

		friend class InstrumentationTimer;
	};
}

#if FL_PROFILE
	#define FL_PROFILE_BEGIN_SESSION(name, filepath) ::FarLight::Instrumentor::GetInstance().BeginSession(name, filepath)
	#define FL_PROFILE_END_SESSION() ::FarLight::Instrumentor::GetInstance().EndSession()
	#define FL_PROFILE_SCOPE(name) ::FarLight::InstrumentationTimer timer##__LINE__(name);
	#define FL_PROFILE_FUNCTION() FL_PROFILE_SCOPE(FL_FUNC_SIG)
#else
	#define FL_PROFILE_BEGIN_SESSION(name, filepath)
	#define FL_PROFILE_END_SESSION()
	#define FL_PROFILE_SCOPE(name)
	#define FL_PROFILE_FUNCTION()
#endif 