#pragma once

#include "FarLight/Core/Timestep.h"

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
		OrthographicCameraController(const OrthographicCameraController&) = delete;
		OrthographicCameraController(OrthographicCameraController&&) = delete;
		OrthographicCameraController& operator=(const OrthographicCameraController&) = delete;
		OrthographicCameraController& operator=(OrthographicCameraController&&) = delete;

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

		KeyboardKeyCodes m_ForwardCode;
		KeyboardKeyCodes m_BackwardCode;
		KeyboardKeyCodes m_RightCode;
		KeyboardKeyCodes m_LeftCode;
		KeyboardKeyCodes m_ClockwiseCode;
		KeyboardKeyCodes m_CounterclockwiseCode;
	};
}