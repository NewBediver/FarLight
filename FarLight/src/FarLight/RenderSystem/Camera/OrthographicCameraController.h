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
	class FARLIGHT_API OrthographicCameraController
	{
	public:
		OrthographicCameraController(const float aspectRation);

		const OrthographicCamera& GetCamera() const { return _camera; }

		void OnUpdate(const Timestep& ts);
		void OnEvent(Event& e);

	private:
		void HandleMovement(const Timestep& ts);
		void HandleRotation(const Timestep& ts);

		const bool OnMouseScrolledEvent(const MouseScrolledEvent& e);
		const bool OnWindowResizedEvent(const WindowResizedEvent& e);

		OrthographicCamera _camera;

		float _aspectRatio;

		float _movementSpeed;
		float _rotationSpeed;
		float _zoomLevel;
		float _sensitivity;

		KeyboardKeyCodes _forwardCode;
		KeyboardKeyCodes _backwardCode;
		KeyboardKeyCodes _rightCode;
		KeyboardKeyCodes _leftCode;
		KeyboardKeyCodes _clockwiseCode;
		KeyboardKeyCodes _counterclockwiseCode;
	};
}