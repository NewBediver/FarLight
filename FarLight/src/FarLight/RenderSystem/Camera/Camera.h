#pragma once

#include <glm/glm.hpp>

namespace FarLight
{
    class Camera
    {
    public:
        explicit Camera() noexcept = default;

        virtual ~Camera() noexcept = default;

        /*virtual const glm::vec3& GetPosition() const noexcept = 0;
        virtual void SetPosition(const glm::vec3& position) noexcept = 0;

        virtual float GetPitch() const noexcept = 0;
        virtual void SetPitch(float pitch) noexcept = 0;

        virtual float GetYaw() const noexcept = 0;
        virtual void SetYaw(float yaw) noexcept = 0;

        virtual float GetRoll() const noexcept = 0;
        virtual void SetRoll(float roll) noexcept = 0;*/

        virtual const glm::vec3& GetFrontDirection() const noexcept = 0;
        virtual void SetFrontDirection(const glm::vec3& frontDir) noexcept = 0;

        virtual const glm::vec3& GetRightDirection() const noexcept = 0;
        virtual void SetRightDirection(const glm::vec3& rightDir) noexcept = 0;

        virtual const glm::vec3& GetUpDirection() const noexcept = 0;
        virtual void SetUpDirection(const glm::vec3& upDir) noexcept = 0;

        virtual const glm::mat4& GetProjectionMatrix() const noexcept = 0;
        virtual void SetProjectionMatrix(float left, float right, float up, float down, float nearZone, float farZone) noexcept = 0;

        virtual const glm::mat4& GetViewMatrix() const noexcept = 0;
    };
}
