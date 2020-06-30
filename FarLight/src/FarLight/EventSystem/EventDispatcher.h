#pragma once

#include "Event.h"

namespace FarLight
{
	class EventDispatcher
	{
		template<typename T>
		using eventFunction = std::function<bool(const T&)>;

	public:
		explicit EventDispatcher(Event& evt);

		template<typename T>
		bool Dispatch(const eventFunction<T>& func)
		{
			if (evt.GetType() == T::GetStaticType())
			{
				evt.isHandled = func(static_cast<T&>(evt));
				return true;
			}
			return false;
		}

	private:
		Event& evt;
	};
}