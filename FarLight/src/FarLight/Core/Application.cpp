// This is an open source non-commercial project. Dear PVS-Studio, please check it.
// PVS-Studio Static Code Analyzer for C, C++ and C#: http://www.viva64.com

#include "flpch.h"

#include "Application.h"

#include "Timestep.h"

#include "FarLight/EventSystem/EventDispatcher.h"

#include "FarLight/InputSystem/Input.h"

#include "FarLight/RenderSystem/Renderer/Renderer2D.h"

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
		: _isRunning(true)
		, _isMinimized(false)
		, _lastFrameTime(0.0f)
	{
		_window = Window::Create();
		_userInterfaceLayer = CreateRef<ImGuiLayer>();
	}

	void Application::Run()
	{
		_window->SetEventCallback(FL_BIND_EVENT_FUNC(Application::OnEvent));
		_layerStack.PushOverlay(_userInterfaceLayer);

		Renderer2D::Init();

		while (_isRunning)
		{
			float time = static_cast<float>(glfwGetTime());
			Timestep ts(time - _lastFrameTime);
			_lastFrameTime = time;

			if (!_isMinimized)
			{
				for (auto& layer = _layerStack.cbegin(); layer != _layerStack.cend(); ++layer)
					(*layer)->OnUpdate(ts);
			}

			_userInterfaceLayer->Begin();
			for (auto& layer = _layerStack.cbegin(); layer != _layerStack.cend(); ++layer)
				(*layer)->OnUserInterfaceRender();
			_userInterfaceLayer->End();

			_window->OnUpdate();
		}

		Renderer2D::Shutdown();
	}

	void Application::OnEvent(Event& e)
	{
		EventDispatcher dispatcher(e);
		dispatcher.Dispatch<WindowClosedEvent>(FL_BIND_EVENT_FUNC(Application::OnWindowClosed));
		dispatcher.Dispatch<WindowResizedEvent>(FL_BIND_EVENT_FUNC(Application::OnWindowResized));

		//FL_CORE_TRACE("{0}", e);
		for (auto it = _layerStack.crbegin(); it != _layerStack.crend(); ++it)
		{
			(*it)->OnEvent(e);
			if (e.IsHandled()) break;
		}
	}

	const bool Application::OnWindowClosed(const WindowClosedEvent& e)
	{
		_isRunning = false;
		return true;
	}

	const bool Application::OnWindowResized(const WindowResizedEvent& e)
	{
		if (e.GetWidth() == 0 || e.GetHeight() == 0) _isMinimized = true;
		else _isMinimized = false;
		Renderer2D::SetViewport(e.GetWidth(), e.GetHeight());
		return false;
	}

}