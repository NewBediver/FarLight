#pragma once

#include <string>
#include <chrono>
#include <functional>

namespace FarLight
{
	class CPUTimer
	{
	public:
		explicit CPUTimer(const std::string& name, const std::function<void(const std::string&, float)>& callback);

		void Start(const std::string& name);
		void Start();
		void Stop();

		~CPUTimer();

	private:
		std::string m_Name;
		std::chrono::time_point<std::chrono::steady_clock> m_StartTimepoint;
		bool m_IsStopped;
		std::function<void(const std::string&, float)> m_Callback;
	};
}