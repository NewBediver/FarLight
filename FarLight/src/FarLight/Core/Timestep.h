#pragma once

namespace FarLight
{
	class Timestep final
	{
	public:
		explicit Timestep(float&& time = 0.0f) noexcept
			: m_Time(std::move(time))
		{ }

		constexpr
		operator float() const noexcept { return m_Time; }

		constexpr
		float GetSeconds() const noexcept { return m_Time; }
		constexpr
		float GetMilliseconds() const noexcept { return m_Time * 1000.0f; }

	private:
		float m_Time;
	};
}