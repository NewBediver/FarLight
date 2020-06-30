#include "flpch.h"
#include "Application.h"

#include "Core.h"
#include "FarLight/EventSystem/EventDispatcher.h"

#include "FarLight/EventSystem/KeyboardEvents/KeyboardKeyReleasedEvent.h"

namespace FarLight
{
	Application::Application()
	{
		window = std::unique_ptr<Window>(Window::Create());
		window->SetEventCallback(std::bind(&Application::OnEvent, this, std::placeholders::_1));
	}

	void Application::Run() const
	{
		while (isRunning)
		{
			window->OnUpdate();
		}
	}

	void Application::OnEvent(Event& e)
	{
		EventDispatcher dispatcher(e);
		dispatcher.Dispatch<WindowClosedEvent>(std::bind(&Application::OnWindowClosed, this, std::placeholders::_1));

		if (e.GetType() != EventType::WindowClosedEventType) FL_CORE_TRACE("{0}", e);
	}

	bool Application::OnWindowClosed(const WindowClosedEvent& e)
	{
		FL_CORE_INFO("{0}", e);
		isRunning = false;
		return true;
	}
}