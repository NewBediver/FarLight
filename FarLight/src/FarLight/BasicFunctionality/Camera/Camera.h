#pragma once

#include <glm/glm.hpp>

namespace FarLight
{
    class Camera
    {
    public:
        virtual ~Camera() noexcept = default;

        virtual void SetResolutionWidth(unsigned width) noexcept = 0;
        virtual unsigned GetResolutionWidth() const noexcept = 0;

        virtual void SetResolutionHeight(unsigned height) noexcept = 0;
        virtual unsigned GetResolutionHeight() const noexcept = 0;

        virtual float GetAspectRatio() const noexcept = 0;

        virtual void SetZoom(float zoom) noexcept = 0;
        virtual float GetZoom() const noexcept = 0;

        virtual void SetLeftBound(float left) noexcept = 0;
        virtual float GetLeftBound() const noexcept = 0;

        virtual void SetRightBound(float right) noexcept = 0;
        virtual float GetRightBound() const noexcept = 0;

        virtual void SetTopBound(float top) noexcept = 0;
        virtual float GetTopBound() const noexcept = 0;

        virtual void SetBottomBound(float bottom) noexcept = 0;
        virtual float GetBottomBound() const noexcept = 0;

        virtual void SetNearBound(float _near) noexcept = 0;
        virtual float GetNearBound() const noexcept = 0;

        virtual void SetFarBound(float _far) noexcept = 0;
        virtual float GetFarBound() const noexcept = 0;

        virtual const glm::vec3& GetFrontDirection() const noexcept = 0;
        virtual const glm::vec3& GetRightDirection() const noexcept = 0;
        virtual const glm::vec3& GetUpDirection() const noexcept = 0;

        virtual void SetProjectionMatrix(float left, float right, float bottom, float top, float nearZone, float farZone) noexcept = 0;
        virtual const glm::mat4& GetProjectionMatrix() const noexcept = 0;

        virtual void SetViewMatrix(const glm::vec3& cameraPosition, const glm::vec3& cameraRotationRadians) noexcept = 0;
        virtual const glm::mat4& GetViewMatrix() const noexcept = 0;

        virtual void SetBackgroundColor(const glm::vec4& color) noexcept = 0;
        virtual const glm::vec4& GetBackgroundColor() const noexcept = 0;
    };
}
