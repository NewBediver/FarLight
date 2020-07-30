#pragma once

#include "Camera.h"

#include "FarLight/Core/Core.h"

#include <glm/glm.hpp>

namespace FarLight
{
	class Camera
	{
	public:
		virtual const glm::vec3& GetPosition() const = 0;
		virtual void SetPosition(const glm::vec3& position) = 0;

		virtual float GetPitch() const = 0;
		virtual void SetPitch(float pitch) = 0;

		virtual float GetYaw() const = 0;
		virtual void SetYaw(float yaw) = 0;

		virtual float GetRoll() const = 0;
		virtual void SetRoll(float roll) = 0;

		virtual const glm::vec3& GetFrontDirection() const = 0;
		virtual void SetFrontDirection(const glm::vec3& frontDir) = 0;

		virtual const glm::vec3& GetRightDirection() const = 0;
		virtual void SetRightDirection(const glm::vec3& rightDir) = 0;

		virtual const glm::vec3& GetUpDirection() const = 0;
		virtual void SetUpDirection(const glm::vec3& upDir) = 0;

		virtual const glm::mat4& GetProjectionMatrix() const = 0;
		virtual void SetProjectionMatrix(float left, float right, float up, float down, float nearZone, float farZone) = 0;

		virtual const glm::mat4& GetViewMatrix() const = 0;

		virtual ~Camera() = default;
	};
}