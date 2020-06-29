#pragma once

#include "flpch.h"

#include "Core.h"
#include "EventSystem/Event.h"
#include "WindowSystem/Window.h"

namespace FarLight
{
	class FARLIGHT_API Application
	{
	public:
		Application();
		virtual ~Application();
		void Run();

	private:
		std::unique_ptr<Window> window;
		bool isRunning = true;
	};

	// To be defined in CLIENT
	Application* CreateApplication();
}