#include "flpch.h"

#include "OrthographicCamera.h"

#include <glm/gtc/matrix_transform.hpp>

namespace FarLight
{
	OrthographicCamera::OrthographicCamera(const float left, const float right, const float bottom, const float top, const float nearZone, const float farZone)
		: _worldUp(0.0f, 1.0f, 0.0f)
		, _position(0.0f)
		, _cameraFront(0.0f, 0.0f, -1.0f)
		, _cameraRight(1.0f, 0.0f, 0.0f)
		, _cameraUp(0.0f, 1.0f, 0.0f)
		, _movementSpeed(5.0f)
		, _rotationSpeed(90.0f)
		, _roll(0.0f)
		, _viewMatrix(1.0f)
		, _projectionMatrix(glm::ortho(left, right, bottom, top, nearZone, farZone))
		, _viewProjectionMatrix(_projectionMatrix)
	{ }

	void OrthographicCamera::SetRoll(const float roll)
	{
		_roll = roll;
		RecalculateCameraVectors();
	}

	void OrthographicCamera::ProcessCameraMovement(const MovementDirection direction, const float delta)
	{
		float velocity = _movementSpeed * delta;
		switch (direction)
		{
			case MovementDirection::Up:
			{
				_position += _cameraUp * velocity;
				break;
			}
			case MovementDirection::Down:
			{
				_position -= _cameraUp * velocity;
				break;
			}
			case MovementDirection::Right:
			{
				_position += _cameraRight * velocity;
				break;
			}
			case MovementDirection::Left:
			{
				_position -= _cameraRight * velocity;
				break;
			}
		}
	}

	void OrthographicCamera::ProcessCameraRotation(const float delta)
	{
		_roll += _rotationSpeed * delta;
		RecalculateCameraVectors();
	}

	const glm::mat4& OrthographicCamera::GetViewMatrix() const
	{
		return glm::lookAt(_position, _position + _cameraFront, _cameraUp);
	}

	void OrthographicCamera::RecalculateCameraVectors()
	{
		glm::vec3 cameraUp = glm::vec3(-sin(glm::radians(_roll)), cos(glm::radians(_roll)), 0.0f);
		glm::vec3 cameraRight = glm::vec3(cos(glm::radians(_roll)), sin(glm::radians(_roll)), 0.0f);
		_cameraUp = glm::normalize(cameraUp);
		_cameraRight = glm::normalize(cameraRight);
	}
}