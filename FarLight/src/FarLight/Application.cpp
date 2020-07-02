#include "flpch.h"
#include "Application.h"

#include "Core.h"
#include "FarLight/EventSystem/EventDispatcher.h"

namespace FarLight
{
	Application::Application()
		: _isRunning(true)
	{
		_window = std::unique_ptr<Window>(Window::Create());
		_window->SetEventCallback(std::bind(&Application::OnEvent, this, std::placeholders::_1));
	}

	void Application::Run()
	{
		while (_isRunning)
		{
			for (auto layer : _layerStack)
			{
				layer->OnUpdate();
			}
			_window->OnUpdate();
		}
	}

	void Application::OnEvent(Event& e)
	{
		EventDispatcher dispatcher(e);
		dispatcher.Dispatch<WindowClosedEvent>(std::bind(&Application::OnWindowClosed, this, std::placeholders::_1));

		if (e.GetType() != EventType::WindowClosedEventType) FL_CORE_TRACE("{0}", e);
		for (auto it = _layerStack.rbegin(); it != _layerStack.rend(); ++it)
		{
			(*it)->OnEvent(e);
			if (e.IsHandled()) break;
		}
	}

	inline void Application::PushLayer(Layer* layer) { _layerStack.PushLayer(layer); }
	inline void Application::PushOverlay(Layer* layer) { _layerStack.PushLayer(layer); }

	bool Application::OnWindowClosed(const WindowClosedEvent& e)
	{
		FL_CORE_INFO("{0}", e);
		_isRunning = false;
		return true;
	}
}