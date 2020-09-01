#pragma once

#include "FarLight/BasicFunctionality/Timestep.h"

#include "FarLight/EventSystem/Event.h"
#include "FarLight/EventSystem/MouseEvents/MouseScrolledEvent.h"
#include "FarLight/EventSystem/WindowEvents/WindowResizedEvent.h"

#include "FarLight/RenderSystem/Camera/OrthographicCamera.h"

#include "FarLight/InputSystem/KeyboardKeyCodes.h"

namespace FarLight
{
    class OrthographicCameraController final
    {
    public:
        explicit OrthographicCameraController(float aspectRation) noexcept;

        const OrthographicCamera& GetCamera() const noexcept { return m_Camera; }

        void OnUpdate(const Timestep& ts) noexcept;
        void OnEvent(Event& e) noexcept;
        void OnResize(float width, float height) noexcept;

    private:
        void HandleMovement(const Timestep& ts) noexcept;
        void HandleRotation(const Timestep& ts) noexcept;

        const bool OnMouseScrolledEvent(const MouseScrolledEvent& e) noexcept;
        const bool OnWindowResizedEvent(const WindowResizedEvent& e) noexcept;

        OrthographicCamera m_Camera;

        float m_AspectRatio;

        float m_MovementSpeed;
        float m_RotationSpeed;
        float m_ZoomLevel;
        float m_Sensitivity;

        KeyboardKeyCode m_ForwardCode;
        KeyboardKeyCode m_BackwardCode;
        KeyboardKeyCode m_RightCode;
        KeyboardKeyCode m_LeftCode;
        KeyboardKeyCode m_ClockwiseCode;
        KeyboardKeyCode m_CounterclockwiseCode;
    };
}
