#pragma once

#include "Event.h"

namespace FarLight
{
	class EventDispatcher
	{
		template<typename T>
		using eventFunction = std::function<bool(const T&)>;

	public:
		EventDispatcher(const Event& evt);

		template<typename T>
		bool Dispatch(eventFunction<T> func) const;

	private:
		const Event& evt;
	};
}