// This is an open source non-commercial project. Dear PVS-Studio, please check it.
// PVS-Studio Static Code Analyzer for C, C++ and C#: http://www.viva64.com

#include "flpch.h"

#include "CPUTimer.h"

namespace FarLight
{
	CPUTimer::CPUTimer(const std::string& name, const std::function<void(const std::string&, float)>& callback)
		: m_Name(name)
		, m_Callback(callback)
		, m_IsStopped(true)
		, m_StartTimepoint(std::chrono::high_resolution_clock::now())
	{
		Start();
	}

	CPUTimer::~CPUTimer()
	{
		if (!m_IsStopped) Stop();
	}

	void CPUTimer::Stop()
	{
		auto endTimepoint = std::chrono::high_resolution_clock::now();

		long long start = std::chrono::time_point_cast<std::chrono::microseconds>(m_StartTimepoint).time_since_epoch().count();
		long long end = std::chrono::time_point_cast<std::chrono::microseconds>(endTimepoint).time_since_epoch().count();

		float duration = (end - start) * 0.001f;

		m_IsStopped = true;

		m_Callback(m_Name, duration);
	}

	void CPUTimer::Start(const std::string& name)
	{
		m_Name = name;
		Start();
	}

	void CPUTimer::Start()
	{
		m_IsStopped = false;

		m_StartTimepoint = std::chrono::high_resolution_clock::now();
	}
}