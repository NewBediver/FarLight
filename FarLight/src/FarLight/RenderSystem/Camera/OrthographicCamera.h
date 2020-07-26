#pragma once

#include "Camera.h"

#include <glm/glm.hpp>

namespace FarLight
{
	class FARLIGHT_API OrthographicCamera
		: public Camera
	{
	public:
		OrthographicCamera::OrthographicCamera(const float left, const float right, const float bottom, const float top, const float nearZone = -1.0f, const float farZone = 100.0f);

		virtual const glm::vec3& GetPosition() const override { return _position; }
		virtual void SetPosition(const glm::vec3& position) override;

		virtual const float GetPitch() const override { return _pitch; }
		virtual void SetPitch(const float pitch) override { _pitch = pitch; }

		virtual const float GetYaw() const override { return _yaw; }
		virtual void SetYaw(const float yaw) override { _yaw = yaw; }

		virtual const float GetRoll() const override { return _roll;}
		virtual void SetRoll(const float roll) override;

		virtual const glm::vec3& GetFrontDirection() const override { return _cameraFront; }
		virtual void SetFrontDirection(const glm::vec3& frontDir) override;

		virtual const glm::vec3& GetRightDirection() const override { return _cameraRight; }
		virtual void SetRightDirection(const glm::vec3& rightDir) override;

		virtual const glm::vec3& GetUpDirection() const override { return _cameraUp; }
		virtual void SetUpDirection(const glm::vec3& upDir) override;

		virtual const glm::mat4& GetProjectionMatrix() const override { return _projectionMatrix; }
		virtual void SetProjectionMatrix(const float left, const float right, const float up, const float down, const float nearZone = -1.0f, const float farZone = 100.0f) override;

		virtual const glm::mat4& GetViewMatrix() const override { return _viewMatrix; }

	private:
		void RecalculateCameraVectors();

		glm::vec3 _worldUp;

		glm::vec3 _position;
		glm::vec3 _cameraFront;
		glm::vec3 _cameraRight;
		glm::vec3 _cameraUp;

		float _pitch;   // around x
		float _yaw;     // around y
		float _roll;    // around z

		glm::mat4 _projectionMatrix;
		glm::mat4 _viewMatrix;
	};
}