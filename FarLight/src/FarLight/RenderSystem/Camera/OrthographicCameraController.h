#pragma once

#include "FarLight/Core/Core.h"
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
		OrthographicCameraController(float aspectRation);

		const OrthographicCamera& GetCamera() const { return m_Camera; }

		void OnUpdate(const Timestep& ts);
		void OnEvent(Event& e);

	private:
		void HandleMovement(const Timestep& ts);
		void HandleRotation(const Timestep& ts);

		const bool OnMouseScrolledEvent(const MouseScrolledEvent& e);
		const bool OnWindowResizedEvent(const WindowResizedEvent& e);

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