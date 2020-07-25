// This is an open source non-commercial project. Dear PVS-Studio, please check it.
// PVS-Studio Static Code Analyzer for C, C++ and C#: http://www.viva64.com

#include "flpch.h"

#include "Application.h"

#include "FarLight/Core/Timestep.h"

#include "FarLight/EventSystem/EventDispatcher.h"

#include "InputSystem/Input.h"

#include "FarLight/RenderSystem/Renderer.h"
#include "FarLight/RenderSystem/RenderCommand/RenderCommand.h"

#include <GLFW/glfw3.h>

namespace FarLight
{
	Scope<Application> Application::_instance = nullptr;

	const Scope<Application>& Application::GetInstance()
	{
		if (_instance == nullptr) _instance = Scope<Application>(new Application());
		return _instance;
	}

	Application::Application()
		: _isRunning(true), _lastFrameTime(0.0f)
	{
		_window = Window::Create();
		_userInterfaceLayer = std::make_shared<ImGuiLayer>();

		Renderer::Init();
	}

	void Application::Run()
	{
		_window->SetEventCallback(FL_BIND_EVENT_FUNC(Application::OnEvent));
		_layerStack.PushOverlay(_userInterfaceLayer);

		while (_isRunning)
		{
			FarLight::RenderCommand::SetClearColor({ 0.2f, 0.3f, 0.3f, 1.0f });
			FarLight::RenderCommand::Clear();

			float time = static_cast<float>(glfwGetTime());
			Timestep ts(time - _lastFrameTime);
			_lastFrameTime = time;

			for (auto& layer = _layerStack.cbegin(); layer != _layerStack.cend(); ++layer)
				(*layer)->OnUpdate(ts);

			_userInterfaceLayer->Begin();
			for (auto& layer = _layerStack.cbegin(); layer != _layerStack.cend(); ++layer)
				(*layer)->OnUserInterfaceRender();
			_userInterfaceLayer->End();

			_window->OnUpdate();
		}
	}

	void Application::OnEvent(Event& e)
	{
		EventDispatcher dispatcher(e);
		dispatcher.Dispatch<WindowClosedEvent>(FL_BIND_EVENT_FUNC(Application::OnWindowClosed));

		//FL_CORE_TRACE("{0}", e);
		for (auto it = _layerStack.crbegin(); it != _layerStack.crend(); ++it)
		{
			(*it)->OnEvent(e);
			if (e.IsHandled()) break;
		}
	}

	bool Application::OnWindowClosed(const WindowClosedEvent& e)
	{
		_isRunning = false;
		return true;
	}
}