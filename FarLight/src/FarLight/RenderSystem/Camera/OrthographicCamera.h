#pragma once

#include <glm/glm.hpp>

namespace FarLight
{
	class FARLIGHT_API OrthographicCamera
	{
	public:
		enum class MovementDirection
		{
			Up,
			Down,
			Right,
			Left
		};

		explicit OrthographicCamera(const float left, const float right, const float bottom, const float top, const float nearZone, const float farZone);

		const glm::vec3& GetPosition() const { return _position; }

		const float GetRoll() const { return _roll; }
		void SetRoll(const float roll);

		const float GetMovementSpeed() const { return _movementSpeed; }
		void SetMovementSpeed(const float speed) { _movementSpeed = speed; }

		const float GetRotationSpeed() const { return _rotationSpeed; }
		void SetRotationSpeed(const float angle) { _rotationSpeed = angle; }

		void ProcessCameraMovement(const MovementDirection direction, const float delta);
		void ProcessCameraRotation(const float angle);

		const glm::mat4& GetProjectionMatrix() const { return _projectionMatrix; }
		const glm::mat4 GetViewMatrix() const;

	private:
		void RecalculateCameraVectors();

		glm::vec3 _worldUp;

		glm::vec3 _position;
		glm::vec3 _cameraFront;
		glm::vec3 _cameraRight;
		glm::vec3 _cameraUp;

		float _movementSpeed;
		float _rotationSpeed;
		// float _zoom;
		// float _sensitivity;

		// float _pitch;   // around x
		// float _yaw;     // around y
		float _roll;       // around z

		glm::mat4 _projectionMatrix;
		glm::mat4 _viewMatrix;
		glm::mat4 _viewProjectionMatrix;
	};
}