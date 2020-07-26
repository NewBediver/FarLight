// This is an open source non-commercial project. Dear PVS-Studio, please check it.
// PVS-Studio Static Code Analyzer for C, C++ and C#: http://www.viva64.com

#include "flpch.h"

#include "OrthographicCameraController.h"
#include "FarLight/EventSystem/EventDispatcher.h"
#include "FarLight/InputSystem/Input.h"

namespace FarLight
{
	OrthographicCameraController::OrthographicCameraController(const float aspectRatio)
		: _aspectRatio(aspectRatio)
		, _zoomLevel(1.0f)
		, _movementSpeed(5.0f)
		, _rotationSpeed(180.0f)
		, _sensitivity(0.5f)
		, _camera(-aspectRatio, aspectRatio, -1.0f, 1.0f)
		, _forwardCode(KeyboardKeyCodes::FL_KEY_W)
		, _backwardCode(KeyboardKeyCodes::FL_KEY_S)
		, _leftCode(KeyboardKeyCodes::FL_KEY_A)
		, _rightCode(KeyboardKeyCodes::FL_KEY_D)
		, _clockwiseCode(KeyboardKeyCodes::FL_KEY_E)
		, _counterclockwiseCode(KeyboardKeyCodes::FL_KEY_Q)
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
		float velocity = _movementSpeed * static_cast<float>(ts);
		if (Input::IsKeyPressed(_forwardCode))
			_camera.SetPosition(_camera.GetPosition() + _camera.GetUpDirection() * velocity);
		else if (Input::IsKeyPressed(_backwardCode))
			_camera.SetPosition(_camera.GetPosition() - _camera.GetUpDirection() * velocity);

		if (Input::IsKeyPressed(_rightCode))
			_camera.SetPosition(_camera.GetPosition() + _camera.GetRightDirection() * velocity);
		else if (Input::IsKeyPressed(_leftCode))
			_camera.SetPosition(_camera.GetPosition() - _camera.GetRightDirection() * velocity);
	}

	void OrthographicCameraController::HandleRotation(const Timestep& ts)
	{
		float velocity = _rotationSpeed * static_cast<float>(ts);
		if (Input::IsKeyPressed(_clockwiseCode))
			_camera.SetRoll(_camera.GetRoll() - velocity);
		else if (Input::IsKeyPressed(_counterclockwiseCode))
			_camera.SetRoll(_camera.GetRoll() + velocity);
	}

	const bool OrthographicCameraController::OnMouseScrolledEvent(const MouseScrolledEvent& e)
	{
		_zoomLevel -= static_cast<float>(e.GetYOffset()) * _sensitivity;
		_zoomLevel = std::max(_zoomLevel, 0.25f);
		_camera.SetProjectionMatrix(-_aspectRatio * _zoomLevel, _aspectRatio * _zoomLevel, -_zoomLevel, _zoomLevel);
		_movementSpeed = 5.0f * _zoomLevel;
		return false;
	}

	const bool OrthographicCameraController::OnWindowResizedEvent(const WindowResizedEvent& e)
	{
		_aspectRatio = static_cast<float>(e.GetWidth()) / static_cast<float>(e.GetHeight());
		_camera.SetProjectionMatrix(-_aspectRatio * _zoomLevel, _aspectRatio * _zoomLevel, -_zoomLevel, _zoomLevel);
		return false;
	}
}



