// This is an open source non-commercial project. Dear PVS-Studio, please check it.
// PVS-Studio Static Code Analyzer for C, C++ and C#: http://www.viva64.com

#include "flpch.h"

#include "OrthographicCameraController.h"
#include "FarLight/EventSystem/EventDispatcher.h"
#include "FarLight/InputSystem/Input.h"

namespace FarLight
{
	OrthographicCameraController::OrthographicCameraController(float aspectRatio)
		: m_AspectRatio(aspectRatio)
		, m_ZoomLevel(1.0f)
		, m_MovementSpeed(5.0f)
		, m_RotationSpeed(180.0f)
		, m_Sensitivity(0.5f)
		, m_Camera(-aspectRatio, aspectRatio, -1.0f, 1.0f)
		, m_ForwardCode(KeyboardKeyCodes::FL_KEY_W)
		, m_BackwardCode(KeyboardKeyCodes::FL_KEY_S)
		, m_LeftCode(KeyboardKeyCodes::FL_KEY_A)
		, m_RightCode(KeyboardKeyCodes::FL_KEY_D)
		, m_ClockwiseCode(KeyboardKeyCodes::FL_KEY_E)
		, m_CounterclockwiseCode(KeyboardKeyCodes::FL_KEY_Q)
	{ }

	void OrthographicCameraController::OnUpdate(const Timestep& ts)
	{
		HandleMovement(ts);
		HandleRotation(ts);
	}

	void OrthographicCameraController::OnEvent(Event& e)
	{
		EventDispatcher dispatcher(e);
		dispatcher.Dispatch<MouseScrolledEvent>(FL_BIND_EVENT_FUNC(OrthographicCameraController::OnMouseScrolledEvent));
		dispatcher.Dispatch<WindowResizedEvent>(FL_BIND_EVENT_FUNC(OrthographicCameraController::OnWindowResizedEvent));
	}

	void OrthographicCameraController::HandleMovement(const Timestep& ts)
	{
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

	void OrthographicCameraController::HandleRotation(const Timestep& ts)
	{
		float velocity = m_RotationSpeed * static_cast<float>(ts);
		if (Input::IsKeyPressed(m_ClockwiseCode))
			m_Camera.SetRoll(m_Camera.GetRoll() - velocity);
		else if (Input::IsKeyPressed(m_CounterclockwiseCode))
			m_Camera.SetRoll(m_Camera.GetRoll() + velocity);
	}

	const bool OrthographicCameraController::OnMouseScrolledEvent(const MouseScrolledEvent& e)
	{
		m_ZoomLevel -= static_cast<float>(e.GetYOffset()) * m_Sensitivity;
		m_ZoomLevel = std::max(m_ZoomLevel, 0.25f);
		m_Camera.SetProjectionMatrix(-m_AspectRatio * m_ZoomLevel, m_AspectRatio * m_ZoomLevel, -m_ZoomLevel, m_ZoomLevel);
		m_MovementSpeed = 5.0f * m_ZoomLevel;
		return false;
	}

	const bool OrthographicCameraController::OnWindowResizedEvent(const WindowResizedEvent& e)
	{
		m_AspectRatio = static_cast<float>(e.GetWidth()) / static_cast<float>(e.GetHeight());
		m_Camera.SetProjectionMatrix(-m_AspectRatio * m_ZoomLevel, m_AspectRatio * m_ZoomLevel, -m_ZoomLevel, m_ZoomLevel);
		return false;
	}
}



