#include "flpch.h"

#include "Application.h"

namespace FarLight
{
	Application::Application()
	{
		window = std::unique_ptr<Window>(Window::Create());
	}

	Application::~Application()
	{
	}

	void Application::Run()
	{
		while (isRunning)
		{
			window->OnUpdate();
		}
	}
}