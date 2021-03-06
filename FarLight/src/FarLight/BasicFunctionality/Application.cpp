// This is an open source non-commercial project. Dear PVS-Studio, please check it.
// PVS-Studio Static Code Analyzer for C, C++ and C#: http://www.viva64.com

#include "flpch.h"

#include "FarLight/BasicFunctionality/Application.h"
#include "FarLight/BasicFunctionality/Timer/Timestep.h"

#include "FarLight/EventSystem/EventDispatcher.h"

#include "FarLight/InputSystem/InputManager.h"

#include "FarLight/RenderSystem/Renderer/Renderer2D.h"

#include "FarLight/BasicFunctionality/Timer/Timer.h"

namespace FarLight
{
    Application::Application() noexcept
        : m_IsRunning(true)
        , m_IsMinimized(false)
        , m_LastFrameTime(0.0f)
    {
        FL_PROFILE_FUNCTION();

        m_Window = Window::Create();
        m_Window->SetEventCallback(FL_BIND_EVENT_FUNC(Application::OnEvent));
    }

    void Application::Run() noexcept
    {
        FL_PROFILE_FUNCTION();

        m_EditorLayer = CreateRef<ImGuiLayer>();
        m_LayerStack.PushOverlay(m_EditorLayer);

        Timer::Create();

        FL_CORE_INFO("Program execution entered the [Main Loop].");
        while (m_IsRunning)
        {
            {
                FL_PROFILE_SCOPE("Main loop");

                Timer::GetInstance().Update();
                Timestep ts(Timer::GetInstance().GetDelta());

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

                    m_EditorLayer->Begin();
                    for (auto& layer = m_LayerStack.crbegin(); layer != m_LayerStack.crend(); ++layer)
                        (*layer)->OnUserInterfaceRender();
                    m_EditorLayer->End();
                }

                m_Window->OnUpdate();
            }
        }
        FL_CORE_INFO("Program execution left the [Main Loop].");

        Timer::Destroy();
    }

    void Application::OnEvent(Event& e) noexcept
    {
        FL_PROFILE_FUNCTION();
        FL_CORE_INFO("Event arised [{0}]", e.ToString());

        EventDispatcher dispatcher(e);
        dispatcher.Dispatch<WindowClosedEvent>(FL_BIND_EVENT_FUNC(Application::OnWindowClosed));
        dispatcher.Dispatch<WindowResizedEvent>(FL_BIND_EVENT_FUNC(Application::OnWindowResized));

        {
            FL_PROFILE_SCOPE("Events dispatching loop");

            for (auto& layer = m_LayerStack.crbegin(); layer != m_LayerStack.crend(); ++layer)
            {
                if (e.IsHandled()) break;
                (*layer)->OnEvent(e);
            }
        }
    }

    bool Application::OnWindowClosed(const WindowClosedEvent& e) noexcept
    {
        FL_PROFILE_FUNCTION();

        Close();
        return true;
    }

    bool Application::OnWindowResized(const WindowResizedEvent& e) noexcept
    {
        FL_PROFILE_FUNCTION();

        if (e.GetWidth() == 0 || e.GetHeight() == 0) m_IsMinimized = true;
        else m_IsMinimized = false;
        Renderer2D::SetViewport(e.GetWidth(), e.GetHeight());
        return false;
    }
}
