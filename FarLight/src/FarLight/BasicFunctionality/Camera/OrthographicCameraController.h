#pragma once

#include "FarLight/BasicFunctionality/Timer/Timestep.h"
#include "FarLight/BasicFunctionality/Camera/RenderOrthoCamera.h"

#include "FarLight/EventSystem/Event.h"
#include "FarLight/EventSystem/MouseEvents/MouseScrolledEvent.h"
#include "FarLight/EventSystem/WindowEvents/WindowResizedEvent.h"

#include "FarLight/InputSystem/KeyboardKeyCodes.h"

namespace FarLight
{
    class OrthographicCameraController final
    {
    public:
        explicit OrthographicCameraController(unsigned width, unsigned height) noexcept;

        void OnUpdate(const Timestep& ts) noexcept;
        void OnEvent(Event& e) noexcept;
        void OnResize(unsigned width, unsigned height) noexcept;

        const Scope<Camera>& GetCamera() const noexcept { return m_Camera; }

        float GetMovementSpeed() const noexcept { return m_MovementSpeed; }
        void SetMovementSpeed(float speed) noexcept { m_MovementSpeed = speed; }
        
        float GeRotationSpeed() const noexcept { return m_RotationSpeed; }
        void SetRotationSpeed(float speed) noexcept { m_RotationSpeed = speed; }

        float GetSensitivity() const noexcept { return m_Sensitivity; }
        void SetSensitivity(float sensitivity) noexcept { m_Sensitivity = sensitivity; }

    private:
        void HandleMovement(const Timestep& ts) noexcept;
        void HandleRotation(const Timestep& ts) noexcept;

        const bool OnMouseScrolledEvent(const MouseScrolledEvent& e) noexcept;
        const bool OnWindowResizedEvent(const WindowResizedEvent& e) noexcept;

        Scope<Camera> m_Camera;

        glm::vec3 m_Position;
        glm::vec3 m_Rotation;

        float m_MovementSpeed;
        float m_RotationSpeed;
        float m_Sensitivity;

        KeyboardKeyCode m_ForwardCode;
        KeyboardKeyCode m_BackwardCode;
        KeyboardKeyCode m_RightCode;
        KeyboardKeyCode m_LeftCode;
        KeyboardKeyCode m_ClockwiseCode;
        KeyboardKeyCode m_CounterclockwiseCode;
    };
}
