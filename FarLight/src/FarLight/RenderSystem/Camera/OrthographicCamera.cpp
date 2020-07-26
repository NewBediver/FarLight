// This is an open source non-commercial project. Dear PVS-Studio, please check it.
// PVS-Studio Static Code Analyzer for C, C++ and C#: http://www.viva64.com

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
		, _roll(0.0f)
		, _pitch(0.0f)
		, _yaw(-90.0f)
		, _viewMatrix(glm::lookAt(_position, _position + _cameraFront, _cameraUp))
		, _projectionMatrix(glm::ortho(left, right, bottom, top, nearZone, farZone))
	{ }

	void OrthographicCamera::SetPosition(const glm::vec3& position)
	{
		_position = position;
		RecalculateCameraVectors();
	}

	void OrthographicCamera::SetRoll(const float roll)
	{
		_roll = roll;
		RecalculateCameraVectors();
	}

	void OrthographicCamera::SetFrontDirection(const glm::vec3& frontDir)
	{
		_cameraFront = frontDir;
		RecalculateCameraVectors();
	}

	void OrthographicCamera::SetRightDirection(const glm::vec3& rightDir)
	{
		_cameraRight = rightDir;
		RecalculateCameraVectors();
	}

	void OrthographicCamera::SetUpDirection(const glm::vec3& upDir)
	{
		_cameraUp = upDir;
		RecalculateCameraVectors();
	}

	void OrthographicCamera::SetProjectionMatrix(const float left, const float right, const float bottom, const float top, const float nearZone, const float farZone)
	{
		_projectionMatrix = glm::ortho(left, right, bottom, top, nearZone, farZone);
	}

	void OrthographicCamera::RecalculateCameraVectors()
	{
		glm::vec3 cameraUp = glm::vec3(-sin(glm::radians(_roll)), cos(glm::radians(_roll)), 0.0f);
		glm::vec3 cameraRight = glm::vec3(cos(glm::radians(_roll)), sin(glm::radians(_roll)), 0.0f);
		_cameraUp = glm::normalize(cameraUp);
		_cameraRight = glm::normalize(cameraRight);
		_viewMatrix = glm::lookAt(_position, _position + _cameraFront, _cameraUp);
	}
}