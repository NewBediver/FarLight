// This is an open source non-commercial project. Dear PVS-Studio, please check it.
// PVS-Studio Static Code Analyzer for C, C++ and C#: http://www.viva64.com

#include "flpch.h"

#include "FarLight/BasicFunctionality/Camera/OrthographicCameraController.h"

#include "FarLight/EventSystem/EventDispatcher.h"

#include "FarLight/InputSystem/Input.h"

namespace FarLight
{
    OrthographicCameraController::OrthographicCameraController(unsigned width, unsigned height) noexcept
        : m_Position(glm::vec3(0.0f))
        , m_Rotation(glm::vec3(0.0f))
        , m_MovementSpeed(500.0f)
        , m_RotationSpeed(180.0f)
        , m_Sensitivity(0.5f)
        , m_Camera(CreateScope<RenderOrthoCamera>(width, height))
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

    void OrthographicCameraController::OnResize(unsigned width, unsigned height) noexcept
    {
        if (height > 0 && width > 0 && (m_Camera->GetResolutionWidth() != width || m_Camera->GetResolutionHeight() != width))
        {
            m_Camera->SetResolutionWidth(width);
            m_Camera->SetResolutionHeight(height);
        }
    }

    void OrthographicCameraController::HandleMovement(const Timestep& ts) noexcept
    {
        FL_PROFILE_FUNCTION();

        float velocity = m_MovementSpeed * static_cast<float>(ts);

        if (Input::IsKeyPressed(m_ForwardCode))
            m_Position += m_Camera->GetUpDirection() * velocity;
        else if (Input::IsKeyPressed(m_BackwardCode))
            m_Position -= m_Camera->GetUpDirection() * velocity;

        if (Input::IsKeyPressed(m_RightCode))
            m_Position += m_Camera->GetRightDirection() * velocity;
        else if (Input::IsKeyPressed(m_LeftCode))
            m_Position -= m_Camera->GetRightDirection() * velocity;

        m_Camera->SetViewMatrix(m_Position, m_Rotation);
    }

    void OrthographicCameraController::HandleRotation(const Timestep& ts) noexcept
    {
        FL_PROFILE_FUNCTION();

        float velocity = glm::radians(m_RotationSpeed) * static_cast<float>(ts);

        if (Input::IsKeyPressed(m_ClockwiseCode))
            m_Rotation.z += velocity;
        else if (Input::IsKeyPressed(m_CounterclockwiseCode))
            m_Rotation.z -= velocity;

        m_Camera->SetViewMatrix(m_Position, m_Rotation);
    }

    const bool OrthographicCameraController::OnMouseScrolledEvent(const MouseScrolledEvent& e) noexcept
    {
        FL_PROFILE_FUNCTION();

        float zoomLevel = m_Camera->GetZoom();
        zoomLevel -= static_cast<float>(e.GetYOffset()) * m_Sensitivity;
        zoomLevel = std::max(zoomLevel, 0.25f);
        m_Camera->SetZoom(zoomLevel);

        m_MovementSpeed = 500.0f * zoomLevel;

        return false;
    }

    const bool OrthographicCameraController::OnWindowResizedEvent(const WindowResizedEvent& e) noexcept
    {
        FL_PROFILE_FUNCTION();

        OnResize(static_cast<float>(e.GetWidth()), static_cast<float>(e.GetHeight()));
        return false;
    }
}
