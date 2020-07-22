#pragma once

#include "FarLight/Core.h"

namespace FarLight
{
	class FARLIGHT_API Timestep
	{
	public:
		explicit Timestep(const float time = 0.0f)
			: _time(time) { }

		explicit operator float() const { return _time; }

		const float GetSeconds() const { return _time; }
		const float GetMilliseconds() const { return _time * 1000.0f; }

	private:
		float _time;
	};
}