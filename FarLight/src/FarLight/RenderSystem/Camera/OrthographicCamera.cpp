// This is an open source non-commercial project. Dear PVS-Studio, please check it.
// PVS-Studio Static Code Analyzer for C, C++ and C#: http://www.viva64.com

#include "flpch.h"

#include "OrthographicCamera.h"

#include <glm/gtc/matrix_transform.hpp>

namespace FarLight
{
	OrthographicCamera::OrthographicCamera(float left, float right, float bottom, float top, float nearZone, float farZone)
		: m_WorldUp(0.0f, 1.0f, 0.0f)
		, m_Position(0.0f)
		, m_CameraFront(0.0f, 0.0f, -1.0f)
		, m_CameraRight(1.0f, 0.0f, 0.0f)
		, m_CameraUp(0.0f, 1.0f, 0.0f)
		, m_Roll(0.0f)
		, m_Pitch(0.0f)
		, m_Yaw(-90.0f)
		, m_ViewMatrix(glm::lookAt(m_Position, m_Position + m_CameraFront, m_CameraUp))
		, m_ProjectionMatrix(glm::ortho(left, right, bottom, top, nearZone, farZone))
	{ }

	void OrthographicCamera::SetPosition(const glm::vec3& position)
	{
		m_Position = position;
		RecalculateCameraVectors();
	}

	void OrthographicCamera::SetRoll(float roll)
	{
		m_Roll = roll;
		RecalculateCameraVectors();
	}

	void OrthographicCamera::SetFrontDirection(const glm::vec3& frontDir)
	{
		m_CameraFront = frontDir;
		RecalculateCameraVectors();
	}

	void OrthographicCamera::SetRightDirection(const glm::vec3& rightDir)
	{
		m_CameraRight = rightDir;
		RecalculateCameraVectors();
	}

	void OrthographicCamera::SetUpDirection(const glm::vec3& upDir)
	{
		m_CameraUp = upDir;
		RecalculateCameraVectors();
	}

	void OrthographicCamera::SetProjectionMatrix(float left, float right, float bottom, float top, float nearZone, float farZone)
	{
		FL_PROFILE_FUNCTION();

		m_ProjectionMatrix = glm::ortho(left, right, bottom, top, nearZone, farZone);
	}

	void OrthographicCamera::RecalculateCameraVectors()
	{
		FL_PROFILE_FUNCTION();

		glm::vec3 cameraUp = glm::vec3(-sin(glm::radians(m_Roll)), cos(glm::radians(m_Roll)), 0.0f);
		glm::vec3 cameraRight = glm::vec3(cos(glm::radians(m_Roll)), sin(glm::radians(m_Roll)), 0.0f);
		m_CameraUp = glm::normalize(cameraUp);
		m_CameraRight = glm::normalize(cameraRight);
		m_ViewMatrix = glm::lookAt(m_Position, m_Position + m_CameraFront, m_CameraUp);
	}
}