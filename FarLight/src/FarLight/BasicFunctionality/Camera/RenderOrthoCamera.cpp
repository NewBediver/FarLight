// This is an open source non-commercial project. Dear PVS-Studio, please check it.
// PVS-Studio Static Code Analyzer for C, C++ and C#: http://www.viva64.com

#include "flpch.h"

#include "FarLight/BasicFunctionality/Camera/RenderOrthoCamera.h"

#include <glm/gtc/matrix_transform.hpp>

namespace FarLight
{
    RenderOrthoCamera::RenderOrthoCamera(unsigned width, unsigned height, const glm::vec4& backgroundColor) noexcept
        : m_ResolutionWidth(width)
        , m_ResolutionHeight(height)
        , m_Zoom(1.0f)
        , m_HorizontalBounds(glm::vec2(0.0f, 1.0f))
        , m_VerticalBounds(glm::vec2(0.0f, 1.0f))
        , m_ClippingPlanes(glm::vec2(0.0f, 100.0f))
        , m_CameraFrontDirection(glm::vec3(0.0f, 0.0f, -1.0f))
        , m_CameraUpDirection(glm::vec3(0.0f, 1.0f, 0.0f))
        , m_CameraRightDirection(glm::vec3(1.0f, 0.0f, 0.0f))
        , m_BackgroundColor(backgroundColor)
    {
        FL_CORE_ASSERT(width != 0, "Resolution width cannot be equal to zero!");
        FL_CORE_ASSERT(height != 0, "Resolution height cannot be equal to zero!");

        RecalculateAspectRatio();
        SetViewMatrix(glm::vec3(0.0f), glm::vec3(0.0f));
        SetProjectionMatrix(0.0f, 1.0f, 0.0f, 1.0f, 0.0f, 100.0f);
    }

    void RenderOrthoCamera::SetResolutionWidth(unsigned width) noexcept
    {
        FL_PROFILE_FUNCTION();

        FL_CORE_ASSERT(width != 0, "Resolution width cannot be equal to zero!");

        if (m_ResolutionWidth != width)
        {
            m_ResolutionWidth = width;
            RecalculateAspectRatio();
        }
    }

    void RenderOrthoCamera::SetResolutionHeight(unsigned height) noexcept
    {
        FL_PROFILE_FUNCTION();

        FL_CORE_ASSERT(height != 0, "Resolution height cannot be equal to zero!");

        if (m_ResolutionHeight != height)
        {
            m_ResolutionHeight = height;
            RecalculateAspectRatio();
        }
    }

    void RenderOrthoCamera::RecalculateAspectRatio() noexcept
    {
        FL_PROFILE_FUNCTION();

        m_AspectRatio = static_cast<float>(m_ResolutionWidth) / static_cast<float>(m_ResolutionHeight);
        SetProjectionMatrix(m_HorizontalBounds.x, m_HorizontalBounds.y, m_VerticalBounds.x, m_VerticalBounds.y, m_ClippingPlanes.x, m_ClippingPlanes.y);
    }

    void RenderOrthoCamera::SetZoom(float zoom) noexcept
    {
        FL_PROFILE_FUNCTION();

        FL_CORE_ASSERT(zoom >= 0.0f, "Zoom cannot be negative!");

        if (abs(m_Zoom - zoom) > 1e-6)
        {
            m_Zoom = zoom;
            SetProjectionMatrix(m_HorizontalBounds.x, m_HorizontalBounds.y, m_VerticalBounds.x, m_VerticalBounds.y, m_ClippingPlanes.x, m_ClippingPlanes.y);
        }
    }

    void RenderOrthoCamera::SetLeftBound(float left) noexcept
    {
        FL_PROFILE_FUNCTION();

        FL_CORE_ASSERT(left >= 0.0f, "Left bound cannot be less than zero!");
        FL_CORE_ASSERT(left <= 1.0f, "Left bound cannot be greater than one!");

        if (abs(m_HorizontalBounds.x - left) > 1e-6)
        {
            SetProjectionMatrix(left, m_HorizontalBounds.y, m_VerticalBounds.x, m_VerticalBounds.y, m_ClippingPlanes.x, m_ClippingPlanes.y);
        }
    }

    void RenderOrthoCamera::SetRightBound(float right) noexcept
    {
        FL_PROFILE_FUNCTION();

        FL_CORE_ASSERT(right >= 0.0f, "Right bound cannot be less than zero!");
        FL_CORE_ASSERT(right <= 1.0f, "Right bound cannot be greater than one!");

        if (abs(m_HorizontalBounds.y - right) > 1e-6)
        {
            SetProjectionMatrix(m_HorizontalBounds.x, right, m_VerticalBounds.x, m_VerticalBounds.y, m_ClippingPlanes.x, m_ClippingPlanes.y);
        }
    }

    void RenderOrthoCamera::SetTopBound(float top) noexcept
    {
        FL_PROFILE_FUNCTION();

        FL_CORE_ASSERT(top >= 0.0f, "Top bound cannot be less than zero!");
        FL_CORE_ASSERT(top <= 1.0f, "Top bound cannot be greater than one!");

        if (abs(m_VerticalBounds.y - top) > 1e-6)
        {
            SetProjectionMatrix(m_HorizontalBounds.x, m_HorizontalBounds.y, m_VerticalBounds.x, top, m_ClippingPlanes.x, m_ClippingPlanes.y);
        }
    }

    void RenderOrthoCamera::SetBottomBound(float bottom) noexcept
    {
        FL_PROFILE_FUNCTION();

        FL_CORE_ASSERT(bottom >= 0.0f, "Bottom bound cannot be less than zero!");
        FL_CORE_ASSERT(bottom <= 1.0f, "Bottom bound cannot be greater than one!");

        if (abs(m_VerticalBounds.x - bottom) > 1e-6)
        {
            SetProjectionMatrix(m_HorizontalBounds.x, m_HorizontalBounds.y, bottom, m_VerticalBounds.y, m_ClippingPlanes.x, m_ClippingPlanes.y);
        }
    }

    void RenderOrthoCamera::SetNearBound(float _near) noexcept
    {
        FL_PROFILE_FUNCTION();

        FL_CORE_ASSERT(_near >= 0.0f, "Near clipping plane cannot be less than zero!");

        if (abs(m_ClippingPlanes.x - _near) > 1e-6)
        {
            SetProjectionMatrix(m_HorizontalBounds.x, m_HorizontalBounds.y, m_VerticalBounds.x, m_VerticalBounds.y, _near, m_ClippingPlanes.y);
        }
    }

    void RenderOrthoCamera::SetFarBound(float _far) noexcept
    {
        FL_PROFILE_FUNCTION();

        FL_CORE_ASSERT(_far >= 0.0f, "Far clipping plane cannot be less than zero!");

        if (abs(m_ClippingPlanes.y - _far) > 1e-6)
        {
            SetProjectionMatrix(m_HorizontalBounds.x, m_HorizontalBounds.y, m_VerticalBounds.x, m_VerticalBounds.y, m_ClippingPlanes.x, _far);
        }
    }

    void RenderOrthoCamera::SetProjectionMatrix(float left, float right, float bottom, float top, float nearZone, float farZone) noexcept
    {
        FL_PROFILE_FUNCTION();

        FL_CORE_ASSERT(left >= 0.0f, "Left bound cannot be less than zero!");
        FL_CORE_ASSERT(left <= 1.0f, "Left bound cannot be greater than one!");
        FL_CORE_ASSERT(right >= 0.0f, "Right bound cannot be less than zero!");
        FL_CORE_ASSERT(right <= 1.0f, "Right bound cannot be greater than one!");
        FL_CORE_ASSERT(top >= 0.0f, "Top bound cannot be less than zero!");
        FL_CORE_ASSERT(top <= 1.0f, "Top bound cannot be greater than one!");
        FL_CORE_ASSERT(bottom >= 0.0f, "Bottom bound cannot be less than zero!");
        FL_CORE_ASSERT(bottom <= 1.0f, "Bottom bound cannot be greater than one!");
        FL_CORE_ASSERT(nearZone >= 0.0f, "Near clipping plane cannot be less than zero!");
        FL_CORE_ASSERT(farZone >= 0.0f, "Far clipping plane cannot be less than zero!");

        m_HorizontalBounds = glm::vec2(left, right);
        m_VerticalBounds   = glm::vec2(bottom, top);
        m_ClippingPlanes   = glm::vec2(nearZone, farZone);

        float horizontalDistance = static_cast<float>(m_ResolutionWidth) * (m_HorizontalBounds.y - m_HorizontalBounds.x);
        float verticalDistance   = static_cast<float>(m_ResolutionHeight) * (m_VerticalBounds.y - m_VerticalBounds.x);

        left    = -horizontalDistance * 0.5f * m_Zoom;
        right   =  horizontalDistance * 0.5f * m_Zoom;
        bottom  = -verticalDistance * 0.5f * m_Zoom;
        top     =  verticalDistance * 0.5f * m_Zoom;

        m_ProjectionMatrix = glm::ortho(left, right, bottom, top, m_ClippingPlanes.x, m_ClippingPlanes.y);
    }

    void RenderOrthoCamera::SetViewMatrix(const glm::vec3& cameraPosition, const glm::vec3& cameraRotationRadians) noexcept
    {
        FL_PROFILE_FUNCTION();

        glm::vec3 cameraUp = glm::vec3(sin(cameraRotationRadians.z), cos(cameraRotationRadians.z), 0.0f);
        glm::vec3 cameraRight = glm::vec3(cos(cameraRotationRadians.z), -sin(cameraRotationRadians.z), 0.0f);
        m_CameraUpDirection = glm::normalize(cameraUp);
        m_CameraRightDirection = glm::normalize(cameraRight);
        m_ViewMatrix = glm::lookAt(cameraPosition, cameraPosition + m_CameraFrontDirection, m_CameraUpDirection);
    }
}
