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
	Application* Application::GetInstance()
	{
		static Application* s_Instance = new Application();
		return s_Instance;
	}

	Application::Application()
		: m_IsRunning(true)
		, m_IsMinimized(false)
		, m_LastFrameTime(0.0f)
	{
		FL_PROFILE_FUNCTION();

		m_Window = Window::Create();
		m_Window->SetEventCallback(FL_BIND_EVENT_FUNC(Application::OnEvent));

		Renderer2D::Init();
	}

	Application::~Application()
	{
		FL_PROFILE_FUNCTION();

		Renderer2D::Shutdown();
	}

	void Application::Run()
	{
		FL_PROFILE_FUNCTION();

		m_UserInterfaceLayer = CreateRef<ImGuiLayer>();
		m_LayerStack.PushOverlay(m_UserInterfaceLayer);

		{
			FL_PROFILE_SCOPE("Main loop");

			while (m_IsRunning)
			{
				float time = static_cast<float>(glfwGetTime());
				Timestep ts(time - m_LastFrameTime);
				m_LastFrameTime = time;

				if (!m_IsMinimized)
				{
					{
						FL_PROFILE_SCOPE("Layers OnUpdate");

						for (auto& layer = m_LayerStack.cbegin(); layer != m_LayerStack.cend(); ++layer)
							(*layer)->OnUpdate(ts);
					}
				}

				{
					FL_PROFILE_SCOPE("UserIntarface OnUpdate");

					m_UserInterfaceLayer->Begin();
					for (auto& layer = m_LayerStack.cbegin(); layer != m_LayerStack.cend(); ++layer)
						(*layer)->OnUserInterfaceRender();
					m_UserInterfaceLayer->End();
				}

				m_Window->OnUpdate();
			}
		}
	}

	void Application::OnEvent(Event& e)
	{
		FL_PROFILE_FUNCTION();

		EventDispatcher dispatcher(e);
		dispatcher.Dispatch<WindowClosedEvent>(FL_BIND_EVENT_FUNC(Application::OnWindowClosed));
		dispatcher.Dispatch<WindowResizedEvent>(FL_BIND_EVENT_FUNC(Application::OnWindowResized));

		{
			FL_PROFILE_SCOPE("Events dispatching loop");

			//FL_CORE_TRACE("{0}", e);
			for (auto layer = m_LayerStack.crbegin(); layer != m_LayerStack.crend(); ++layer)
			{
				(*layer)->OnEvent(e);
				if (e.IsHandled()) break;
			}
		}
	}

	bool Application::OnWindowClosed(const WindowClosedEvent& e)
	{
		FL_PROFILE_FUNCTION();

		m_IsRunning = false;
		return true;
	}

	bool Application::OnWindowResized(const WindowResizedEvent& e)
	{
		FL_PROFILE_FUNCTION();

		if (e.GetWidth() == 0 || e.GetHeight() == 0) m_IsMinimized = true;
		else m_IsMinimized = false;
		Renderer2D::SetViewport(e.GetWidth(), e.GetHeight());
		return false;
	}

}