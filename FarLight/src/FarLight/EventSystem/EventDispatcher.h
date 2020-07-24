#pragma once

#include "Event.h"

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
			: _event(evt) { }

		template<typename T, typename F>
		const bool Dispatch(const F& func)
		{
			try
			{
				T& evt = dynamic_cast<T&>(_event);
				_event.SetHandled(func(evt));
				return true;
			}
			catch (const std::bad_cast&)
			{
				return false;
			}
		}

	private:
		Event& _event;
	};
}