#pragma once

#include "Camera.h"

#include <glm/glm.hpp>

namespace FarLight
{
	class OrthographicCamera final
		: public Camera
	{
	public:
		explicit OrthographicCamera(float left, float right, float bottom, float top, float nearZone = -1.0f, float farZone = 100.0f) noexcept;

		virtual const glm::vec3& GetPosition() const noexcept override { return m_Position; }
		virtual void SetPosition(const glm::vec3& position) noexcept override;

		virtual float GetPitch() const noexcept override { return m_Pitch; }
		virtual void SetPitch(float pitch) noexcept override { m_Pitch = pitch; }

		virtual float GetYaw() const noexcept override { return m_Yaw; }
		virtual void SetYaw(float yaw) noexcept override { m_Yaw = yaw; }

		virtual float GetRoll() const noexcept override { return m_Roll;}
		virtual void SetRoll(float roll) noexcept override;

		virtual const glm::vec3& GetFrontDirection() const noexcept override { return m_CameraFront; }
		virtual void SetFrontDirection(const glm::vec3& frontDir) noexcept override;

		virtual const glm::vec3& GetRightDirection() const noexcept override { return m_CameraRight; }
		virtual void SetRightDirection(const glm::vec3& rightDir) noexcept override;

		virtual const glm::vec3& GetUpDirection() const noexcept override { return m_CameraUp; }
		virtual void SetUpDirection(const glm::vec3& upDir) noexcept override;

		virtual const glm::mat4& GetProjectionMatrix() const noexcept override { return m_ProjectionMatrix; }
		virtual void SetProjectionMatrix(float left, float right, float up, float down, float nearZone = -1.0f, float farZone = 100.0f) noexcept override;

		virtual const glm::mat4& GetViewMatrix() const noexcept override { return m_ViewMatrix; }

	private:
		void RecalculateCameraVectors() noexcept;

		glm::vec3 m_WorldUp;

		glm::vec3 m_Position;
		glm::vec3 m_CameraFront;
		glm::vec3 m_CameraRight;
		glm::vec3 m_CameraUp;

		float m_Pitch;   // around x
		float m_Yaw;     // around y
		float m_Roll;    // around z

		glm::mat4 m_ProjectionMatrix;
		glm::mat4 m_ViewMatrix;
	};
}