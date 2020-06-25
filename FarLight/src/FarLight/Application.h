#pragma once

#include "Core.h"
#include "EventSystem/Event.h"

namespace FarLight
{
	class FARLIGHT_API Application
	{
	public:
		void Run();
	};

	// To be defined in CLIENT
	Application* CreateApplication();
}
