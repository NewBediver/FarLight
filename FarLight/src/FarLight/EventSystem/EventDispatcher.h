#pragma once

#include <functional>

#include "FarLight/EventSystem/Event.h"

#include "KeyboardEvents/KeyboardKeyPressedEvent.h"
#include "KeyboardEvents/KeyboardKeyReleasedEvent.h"
#include "KeyboardEvents/KeyboardKeyTypedEvent.h"

#include "MouseEvents/MouseButtonPressedEvent.h"
#include "MouseEvents/MouseButtonReleasedEvent.h"
#include "MouseEvents/MouseMovedEvent.h"
#include "MouseEvents/MouseScrolledEvent.h"

#include "WindowEvents/WindowClosedEvent.h"
#include "WindowEvents/WindowResizedEvent.h"

namespace FarLight
{
	class EventDispatcher
	{
	public:
		explicit EventDispatcher(Event& evt)
			: m_Event(evt) { }

		template<typename T>
		bool Dispatch(const std::function<bool(const T&)>& func)
		{
			if (typeid(T) == typeid(m_Event))
			{
				m_Event.SetHandled(func(static_cast<const T&>(m_Event)));
				return true;
			}
			return false;
		}

	private:
		Event& m_Event;
	};
}