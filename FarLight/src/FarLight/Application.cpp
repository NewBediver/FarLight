#include "flpch.h"
#include "Application.h"

#include "Core.h"
#include "FarLight/EventSystem/EventDispatcher.h"

namespace FarLight
{
	Application* Application::_instance = nullptr;

	inline Application& Application::GetInstance()
	{
		if (_instance == nullptr) _instance = new Application();
		return *_instance;
	}

	inline Window& Application::GetWindow() { return *_window; }

	Application::Application()
		: _isRunning(true)
	{
		_window = std::unique_ptr<Window>(Window::Create());
		_window->SetEventCallback(FL_BIND_EVENT_FUNC(Application::OnEvent));
	}

	void Application::Run()
	{
		while (_isRunning)
		{
			for (auto layer : _layerStack) layer->OnUpdate();
			_window->OnUpdate();
		}
	}

	void Application::OnEvent(Event& e)
	{
		EventDispatcher dispatcher(e);
		dispatcher.Dispatch<WindowClosedEvent>(FL_BIND_EVENT_FUNC(Application::OnWindowClosed));

		if (e.GetType() != EventType::WindowClosedEventType) FL_CORE_TRACE("{0}", e);
		for (auto it = _layerStack.rbegin(); it != _layerStack.rend(); ++it)
		{
			(*it)->OnEvent(e);
			if (e.IsHandled()) break;
		}
	}

	inline void Application::PushLayer(Layer* layer) { _layerStack.PushLayer(layer); }
	inline void Application::PushOverlay(Layer* overlay) { _layerStack.PushOverlay(overlay);}

	bool Application::OnWindowClosed(const WindowClosedEvent& e)
	{
		FL_CORE_INFO("{0}", e);
		_isRunning = false;
		return true;
	}
}