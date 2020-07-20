#pragma once

#include <glm/glm.hpp>

namespace FarLight
{
	class FARLIGHT_API OrthographicCamera
	{
	public:
		explicit OrthographicCamera(float left, float right, float bottom, float top, float nearZone, float farZone);

		const glm::vec3& GetPosition() const { return _position; }
		void SetPosition(const glm::vec3& position);

		float GetZRotation() const { return _zRotation; }
		void SetZRotation(float zRotation);

		const glm::mat4& GetProjectionMatrix() const { return _projectionMatrix; }
		const glm::mat4& GetViewMatrix() const { return _viewMatrix; }
		const glm::mat4& GetViewProjectionMatrix() const { return _viewProjectionMatrix; }

	private:
		void RecalculateViewProjectionMatrix();

		glm::mat4 _projectionMatrix;
		glm::mat4 _viewMatrix;
		glm::mat4 _viewProjectionMatrix;

		glm::vec3 _position;
		float _zRotation;
	};
}