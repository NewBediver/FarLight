// This is an open source non-commercial project. Dear PVS-Studio, please check it.
// PVS-Studio Static Code Analyzer for C, C++ and C#: http://www.viva64.com

#include "flpch.h"

#include "Application.h"
#include "FarLight/Core/Timestep.h"
#include "FarLight/EventSystem/EventDispatcher.h"
#include "FarLight/InputSystem/Input.h"
#include "FarLight/RenderSystem/Renderer/Renderer2D.h"

#include <GLFW/glfw3.h>

namespace FarLight
{
	Scope<Application> Application::s_Instance = nullptr;

	const Scope<Application>& Application::GetInstance()
	{
		if (s_Instance == nullptr) s_Instance = Scope<Application>(new Application());
		return s_Instance;
	}

	Application::Application()
		: m_IsRunning(true)
		, m_IsMinimized(false)
		, m_LastFrameTime(0.0f)
	{
		m_Window = Window::Create();
		m_UserInterfaceLayer = CreateRef<ImGuiLayer>();
	}

	void Application::Run()
	{
		m_Window->SetEventCallback(FL_BIND_EVENT_FUNC(Application::OnEvent));
		m_LayerStack.PushOverlay(m_UserInterfaceLayer);

		Renderer2D::Init();

		while (m_IsRunning)
		{
			float time = static_cast<float>(glfwGetTime());
			Timestep ts(time - m_LastFrameTime);
			m_LastFrameTime = time;

			if (!m_IsMinimized)
			{
				for (auto& layer = m_LayerStack.cbegin(); layer != m_LayerStack.cend(); ++layer)
					(*layer)->OnUpdate(ts);
			}

			m_UserInterfaceLayer->Begin();
			for (auto& layer = m_LayerStack.cbegin(); layer != m_LayerStack.cend(); ++layer)
				(*layer)->OnUserInterfaceRender();
			m_UserInterfaceLayer->End();

			m_Window->OnUpdate();
		}

		Renderer2D::Shutdown();
	}

	void Application::OnEvent(Event& e)
	{
		EventDispatcher dispatcher(e);
		dispatcher.Dispatch<WindowClosedEvent>(FL_BIND_EVENT_FUNC(Application::OnWindowClosed));
		dispatcher.Dispatch<WindowResizedEvent>(FL_BIND_EVENT_FUNC(Application::OnWindowResized));

		//FL_CORE_TRACE("{0}", e);
		for (auto layer = m_LayerStack.crbegin(); layer != m_LayerStack.crend(); ++layer)
		{
			(*layer)->OnEvent(e);
			if (e.IsHandled()) break;
		}
	}

	bool Application::OnWindowClosed(const WindowClosedEvent& e)
	{
		m_IsRunning = false;
		return true;
	}

	bool Application::OnWindowResized(const WindowResizedEvent& e)
	{
		if (e.GetWidth() == 0 || e.GetHeight() == 0) m_IsMinimized = true;
		else m_IsMinimized = false;
		Renderer2D::SetViewport(e.GetWidth(), e.GetHeight());
		return false;
	}

}