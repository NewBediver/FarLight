#pragma once

namespace FarLight
{
	class Timestep final
	{
	public:
		Timestep(const Timestep&) = delete;
		Timestep(Timestep&&) = delete;
		Timestep& operator=(const Timestep&) = delete;
		Timestep& operator=(Timestep&&) = delete;

		explicit Timestep(float&& time = 0.0f) noexcept
			: m_Time(time)
		{ }

		constexpr
		explicit operator float() const noexcept { return m_Time; }

		constexpr
		float GetSeconds() const noexcept { return m_Time; }
		constexpr
		float GetMilliseconds() const noexcept { return m_Time * 1000.0f; }

	private:
		float m_Time;
	};
}