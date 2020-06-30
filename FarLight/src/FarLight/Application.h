#pragma once

#include "flpch.h"

#include "EventSystem/Event.h"
#include "EventSystem/WindowEvents/WindowClosedEvent.h"
#include "WindowSystem/Window.h"

namespace FarLight
{
	class FARLIGHT_API Application
	{
	public:
		explicit Application();
		virtual ~Application() = default;

		void Run() const;
		void OnEvent(Event& e);

	private:
		bool OnWindowClosed(const WindowClosedEvent& e);

		std::unique_ptr<Window> window;
		bool isRunning = true;
	};

	// To be defined in CLIENT
	Application* CreateApplication();
}