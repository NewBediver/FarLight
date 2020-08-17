#pragma once

#include <functional>

#include "FarLight/EventSystem/Event.h"

#include "FarLight/Profiling/Instrumentor.h"

namespace FarLight
{
	class EventDispatcher final
	{
	public:
		EventDispatcher(const EventDispatcher&) = delete;
		EventDispatcher(EventDispatcher&&) = delete;
		EventDispatcher& operator=(const EventDispatcher&) = delete;
		EventDispatcher& operator=(EventDispatcher&&) = delete;

		explicit EventDispatcher(Event& evt) noexcept
			: m_Event(evt)
		{ }

		template<typename T>
		constexpr
		bool Dispatch(const std::function<bool(const T&)>& func) noexcept
		{
			FL_PROFILE_FUNCTION();

			if (typeid(T) == typeid(m_Event))
			{
				FL_CORE_INFO("Event [{0}] dispatched.", m_Event.ToString());
				m_Event.SetHandled(func(static_cast<const T&>(m_Event)));
				return true;
			}
			return false;
		}

	private:
		Event& m_Event;
	};
}