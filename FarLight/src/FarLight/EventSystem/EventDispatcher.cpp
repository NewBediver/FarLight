#include "flpch.h"

#include "EventDispatcher.h"

namespace FarLight
{
	EventDispatcher::EventDispatcher(const Event& evt)
		: evt(evt)
	{ }

	template<typename T>
	bool EventDispatcher::Dispatch(eventFunction<T> func) const
	{
		if (evt.GetType() == T::GetStaticType())
		{
			evt.isHandled = func(dynamic_cast<const T&>(evt));
			return true;
		}
		return false;
	}
}