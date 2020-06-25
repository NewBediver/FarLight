#include "Application.h"

#include "FarLight/Logger.h"
#include "FarLight/EventSystem/MouseEvents/MouseMovedEvent.h"

namespace FarLight
{

	void Application::Run()
	{
		MouseMovedEvent e(1.0, 1.1);
		if (e.IsInCategory(InputEventCategory))
		{
			FL_TRACE(e);
		}
		if (e.IsInCategory(MouseEventCategory))
		{
			FL_TRACE(e);
		}
		if (e.IsInCategory(MouseButtonEventCategory))
		{
			FL_TRACE(e);
		}
		if (e.IsInCategory(ApplicationEventCategory))
		{
			FL_TRACE(e);
		}

		while (true);
	}

}

