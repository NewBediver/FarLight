#include "flpch.h"
#include "Application.h"

#include <glad/glad.h>

#include "Core.h"
#include "FarLight/EventSystem/EventDispatcher.h"

#include "InputSystem/Input.h"

namespace FarLight
{
	std::shared_ptr<Application> Application::_instance = nullptr;

	std::shared_ptr<Application> Application::GetInstance()
	{
		if (_instance == nullptr) _instance = std::shared_ptr<Application>(new Application());
		return _instance;
	}

	Application::Application()
		: _isRunning(true)
	{
		_window = Window::Create();
		_userInterfaceLayer = std::make_shared<ImGuiLayer>();
	}

	void Application::Run()
	{
		Init();
		while (_isRunning)
		{
			glClearColor(0.45f, 0.55f, 0.60f, 1.00f);
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