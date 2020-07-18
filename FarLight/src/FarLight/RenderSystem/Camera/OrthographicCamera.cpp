#include "flpch.h"

#include "OrthographicCamera.h"

#include <glm/gtc/matrix_transform.hpp>

namespace FarLight
{
	OrthographicCamera::OrthographicCamera(float left, float right, float bottom, float top)
		: _projectionMatrix(glm::ortho(left, right, bottom, top, -1.0f, 1.0f)), _viewMatrix(1.0f), _zRotation(0.0f), _position(0.0f)
	{
		RecalculateViewProjectionMatrix();
	}

	void OrthographicCamera::SetPosition(const glm::vec3& position)
	{
		_position = position;
		RecalculateViewProjectionMatrix();
	}

	void OrthographicCamera::SetZRotation(float zRotation)
	{
		_zRotation = zRotation;
		RecalculateViewProjectionMatrix();
	}

	void OrthographicCamera::RecalculateViewProjectionMatrix()
	{
		glm::mat4 transform = glm::mat4(1.0f);
		transform = glm::translate(transform, _position);
		transform = glm::rotate(transform, glm::radians(_zRotation), glm::vec3(0, 0, 1));

		_viewMatrix = glm::inverse(transform);
		_viewProjectionMatrix = _projectionMatrix * _viewMatrix;
	}
}