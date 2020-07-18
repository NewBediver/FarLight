#pragma once

#include "FarLight/Core.h"

namespace FarLight
{
	class FARLIGHT_API Timestep
	{
	public:
		explicit Timestep(float time = 0.0f)
			: _time(time) { }

		operator float() const { return _time; }

		float GetSeconds() const { return _time; }
		float GetMilliseconds() const { return _time * 1000.0f; }
	private:
		float _time;
	};
}