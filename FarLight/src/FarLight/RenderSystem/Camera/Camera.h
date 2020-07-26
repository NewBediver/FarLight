#pragma once

#include "Camera.h"

#include "FarLight/Core/Core.h"

#include <glm/glm.hpp>

namespace FarLight
{
	class FARLIGHT_API Camera
	{
	public:
		virtual const glm::vec3& GetPosition() const = 0;
		virtual void SetPosition(const glm::vec3& position) = 0;

		virtual const float GetPitch() const = 0;
		virtual void SetPitch(const float pitch) = 0;

		virtual const float GetYaw() const = 0;
		virtual void SetYaw(const float yaw) = 0;

		virtual const float GetRoll() const = 0;
		virtual void SetRoll(const float roll) = 0;

		virtual const glm::vec3& GetFrontDirection() const = 0;
		virtual void SetFrontDirection(const glm::vec3& frontDir) = 0;

		virtual const glm::vec3& GetRightDirection() const = 0;
		virtual void SetRightDirection(const glm::vec3& rightDir) = 0;

		virtual const glm::vec3& GetUpDirection() const = 0;
		virtual void SetUpDirection(const glm::vec3& upDir) = 0;

		virtual const glm::mat4& GetProjectionMatrix() const = 0;
		virtual void SetProjectionMatrix(const float left, const float right, const float up, const float down, const float nearZone, const float farZone) = 0;

		virtual const glm::mat4& GetViewMatrix() const = 0;
	};
}