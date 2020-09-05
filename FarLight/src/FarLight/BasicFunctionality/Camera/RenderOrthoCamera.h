#pragma once

#include "FarLight/BasicFunctionality/Camera/Camera.h"

namespace FarLight
{
    class RenderOrthoCamera
        : public Camera
    {
    public:
        explicit RenderOrthoCamera(unsigned width, unsigned height, const glm::vec4& backgroundColor = glm::vec4(0.1f, 0.1f, 0.1f, 1.0f)) noexcept;

        virtual void SetResolutionWidth(unsigned width) noexcept override;
        virtual unsigned GetResolutionWidth() const noexcept override { return m_ResolutionWidth; }

        virtual void SetResolutionHeight(unsigned height) noexcept override;
        virtual unsigned GetResolutionHeight() const noexcept override { return m_ResolutionHeight; }

        virtual float GetAspectRatio() const noexcept override { return m_AspectRatio; }

        virtual void SetZoom(float zoom) noexcept override;
        virtual float GetZoom() const noexcept override { return m_Zoom; }

        virtual void SetLeftBound(float left) noexcept override;
        virtual float GetLeftBound() const noexcept override { return m_HorizontalBounds.x; }

        virtual void SetRightBound(float right) noexcept override;
        virtual float GetRightBound() const noexcept override { return m_HorizontalBounds.y; }

        virtual void SetTopBound(float top) noexcept override;
        virtual float GetTopBound() const noexcept override { return m_VerticalBounds.y; }

        virtual void SetBottomBound(float bottom) noexcept override;
        virtual float GetBottomBound() const noexcept override { return m_VerticalBounds.x; }

        virtual void SetNearBound(float _near) noexcept override;
        virtual float GetNearBound() const noexcept override { return m_ClippingPlanes.x; }

        virtual void SetFarBound(float _far) noexcept override;
        virtual float GetFarBound() const noexcept override { return m_ClippingPlanes.y; }

        virtual const glm::vec3& GetFrontDirection() const noexcept override { return m_CameraFrontDirection; }
        virtual const glm::vec3& GetRightDirection() const noexcept override { return m_CameraRightDirection; }
        virtual const glm::vec3& GetUpDirection() const noexcept override { return m_CameraUpDirection; }

        virtual void SetProjectionMatrix(float left, float right, float bottom, float top, float nearZone, float farZone) noexcept override;
        virtual const glm::mat4& GetProjectionMatrix() const noexcept override { return m_ProjectionMatrix; }

        virtual void SetViewMatrix(const glm::vec3& cameraPosition, const glm::vec3& cameraRotationRadians) noexcept override;
        virtual const glm::mat4& GetViewMatrix() const noexcept override { return m_ViewMatrix; }

        virtual void SetBackgroundColor(const glm::vec4& color) noexcept override { m_BackgroundColor = color; }
        virtual const glm::vec4& GetBackgroundColor() const noexcept override { return m_BackgroundColor; }

    private:
        void RecalculateAspectRatio() noexcept;

        unsigned m_ResolutionWidth, m_ResolutionHeight;
        float m_AspectRatio;
        float m_Zoom;

        glm::vec2 m_HorizontalBounds; // left, right
        glm::vec2 m_VerticalBounds;   // bottom, top
        glm::vec2 m_ClippingPlanes;   // near, far

        glm::vec3 m_CameraFrontDirection;
        glm::vec3 m_CameraUpDirection;
        glm::vec3 m_CameraRightDirection;

        glm::mat4 m_ProjectionMatrix;
        glm::mat4 m_ViewMatrix;

        glm::vec4 m_BackgroundColor;
    };
}
