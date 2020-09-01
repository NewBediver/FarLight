// This is an open source non-commercial project. Dear PVS-Studio, please check it.
// PVS-Studio Static Code Analyzer for C, C++ and C#: http://www.viva64.com

#include "flpch.h"

#include "FarLight/RenderSystem/Camera/OrthographicCameraController.h"
#include "FarLight/EventSystem/EventDispatcher.h"
#include "FarLight/InputSystem/Input.h"

namespace FarLight
{
    OrthographicCameraController::OrthographicCameraController(float aspectRatio) noexcept
        : m_AspectRatio(aspectRatio)
        , m_ZoomLevel(1.0f)
        , m_MovementSpeed(5.0f)
        , m_RotationSpeed(180.0f)
        , m_Sensitivity(0.5f)
        , m_Camera(-aspectRatio, aspectRatio, -1.0f, 1.0f)
        , m_ForwardCode(KeyboardKeyCode::FL_KEY_W)
        , m_BackwardCode(KeyboardKeyCode::FL_KEY_S)
        , m_LeftCode(KeyboardKeyCode::FL_KEY_A)
        , m_RightCode(KeyboardKeyCode::FL_KEY_D)
        , m_ClockwiseCode(KeyboardKeyCode::FL_KEY_E)
        , m_CounterclockwiseCode(KeyboardKeyCode::FL_KEY_Q)
    { }

    void OrthographicCameraController::OnUpdate(const Timestep& ts) noexcept
    {
        FL_PROFILE_FUNCTION();

        HandleMovement(ts);
        HandleRotation(ts);
    }

    void OrthographicCameraController::OnEvent(Event& e) noexcept
    {
        FL_PROFILE_FUNCTION();

        EventDispatcher dispatcher(e);
        dispatcher.Dispatch<MouseScrolledEvent>(FL_BIND_EVENT_FUNC(OrthographicCameraController::OnMouseScrolledEvent));
        dispatcher.Dispatch<WindowResizedEvent>(FL_BIND_EVENT_FUNC(OrthographicCameraController::OnWindowResizedEvent));
    }

    void OrthographicCameraController::OnResize(float width, float height) noexcept
    {
        if (height > 0.0f && width > 0.0f && abs(m_AspectRatio - width / height) > 1e-9)
        {
            m_AspectRatio = width / height;
            m_Camera.SetProjectionMatrix(-m_AspectRatio * m_ZoomLevel, m_AspectRatio * m_ZoomLevel, -m_ZoomLevel, m_ZoomLevel);
        }
    }

    void OrthographicCameraController::HandleMovement(const Timestep& ts) noexcept
    {
        FL_PROFILE_FUNCTION();

        float velocity = m_MovementSpeed * static_cast<float>(ts);
        if (Input::IsKeyPressed(m_ForwardCode))
            m_Camera.SetPosition(m_Camera.GetPosition() + m_Camera.GetUpDirection() * velocity);
        else if (Input::IsKeyPressed(m_BackwardCode))
            m_Camera.SetPosition(m_Camera.GetPosition() - m_Camera.GetUpDirection() * velocity);

        if (Input::IsKeyPressed(m_RightCode))
            m_Camera.SetPosition(m_Camera.GetPosition() + m_Camera.GetRightDirection() * velocity);
        else if (Input::IsKeyPressed(m_LeftCode))
            m_Camera.SetPosition(m_Camera.GetPosition() - m_Camera.GetRightDirection() * velocity);
    }

    void OrthographicCameraController::HandleRotation(const Timestep& ts) noexcept
    {
        FL_PROFILE_FUNCTION();

        float velocity = m_RotationSpeed * static_cast<float>(ts);
        if (Input::IsKeyPressed(m_ClockwiseCode))
            m_Camera.SetRoll(m_Camera.GetRoll() - velocity);
        else if (Input::IsKeyPressed(m_CounterclockwiseCode))
            m_Camera.SetRoll(m_Camera.GetRoll() + velocity);
    }

    const bool OrthographicCameraController::OnMouseScrolledEvent(const MouseScrolledEvent& e) noexcept
    {
        FL_PROFILE_FUNCTION();

        m_ZoomLevel -= static_cast<float>(e.GetYOffset()) * m_Sensitivity;
        m_ZoomLevel = std::max(m_ZoomLevel, 0.25f);
        m_Camera.SetProjectionMatrix(-m_AspectRatio * m_ZoomLevel, m_AspectRatio * m_ZoomLevel, -m_ZoomLevel, m_ZoomLevel);
        m_MovementSpeed = 5.0f * m_ZoomLevel;
        return false;
    }

    const bool OrthographicCameraController::OnWindowResizedEvent(const WindowResizedEvent& e) noexcept
    {
        FL_PROFILE_FUNCTION();

        OnResize(static_cast<float>(e.GetWidth()), static_cast<float>(e.GetHeight()));
        return false;
    }
}
