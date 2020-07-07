#include "flpch.h"
#include "Application.h"

#include <glad/glad.h>

#include "Core.h"
#include "FarLight/EventSystem/EventDispatcher.h"

#include "InputSystem/Input.h"

namespace FarLight
{
	Application* Application::_instance = nullptr;

	inline Application* Application::GetInstance()
	{
		if (_instance == nullptr) _instance = new Application();
		return _instance;
	}

	inline std::unique_ptr<Window>& Application::GetWindow() { return _window; }

	Application::Application()
		: _isRunning(true)
	{
		_window = std::unique_ptr<Window>(Window::Create());
		_userInterfaceLayer = std::make_unique<ImGuiLayer>();
	}

	void Application::Run()
	{
		Init();
		while (_isRunning)
		{
			glClearColor(0.45, 0.55, 0.60, 1.00);
			glClear(GL_COLOR_BUFFER_BIT);

			for (auto& layer : _layerStack) layer->OnUpdate();

			_userInterfaceLayer->Begin();
			for (auto& layer : _layerStack) layer->OnUserInterfaceRender();
			_userInterfaceLayer->End();

			_window->OnUpdate();
		}
	}

	void Application::OnEvent(Event& e)
	{
		EventDispatcher dispatcher(e);
		dispatcher.Dispatch<WindowClosedEvent>(FL_BIND_EVENT_FUNC(Application::OnWindowClosed));

		FL_CORE_TRACE("{0}", e);
		for (auto it = _layerStack.rbegin(); it != _layerStack.rend(); ++it)
		{
			(*it)->OnEvent(e);
			if (e.IsHandled()) break;
		}
	}

	inline void Application::PushLayer(std::shared_ptr<Layer> layer) { _layerStack.PushLayer(layer); }
	inline void Application::PushOverlay(std::shared_ptr<Layer> overlay) { _layerStack.PushOverlay(overlay);}

	void Application::Init()
	{
		_window->SetEventCallback(FL_BIND_EVENT_FUNC(Application::OnEvent));
		_layerStack.PushOverlay(_userInterfaceLayer);
	}

	bool Application::OnWindowClosed(const WindowClosedEvent& e)
	{
		_isRunning = false;
		return true;
	}
}