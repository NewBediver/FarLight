// This is an open source non-commercial project. Dear PVS-Studio, please check it.
// PVS-Studio Static Code Analyzer for C, C++ and C#: http://www.viva64.com

#include "flpch.h"

#include "FarLight/RenderSystem/Camera/Render2DCamera.h"

#include <glm/gtc/matrix_transform.hpp>

namespace FarLight
{
    Render2DCamera::Render2DCamera(unsigned width, unsigned height, float zoom) noexcept
        : m_Width(width)
        , m_Height(height)
        , m_ZoomLevel(zoom)
    {
        FL_CORE_ASSERT(m_Width != 0, "Width should not be assigned to zero!");
        FL_CORE_ASSERT(m_Height != 0, "Height should not be assigned to zero!");

        RecalculateProjectionMatrix();
    }

    void Render2DCamera::SetAspectRatio(unsigned width, unsigned height) noexcept
    {
        if (width != 0 && height != 0 && (m_Width != width || m_Height != height))
        {
            m_Width = width;
            m_Height = height;
            RecalculateProjectionMatrix();
        }
    }

    void Render2DCamera::SetWidth(unsigned width) noexcept
    {
        if (width != 0 && m_Width != width)
        {
            m_Width = width;
            RecalculateProjectionMatrix();
        }
    }

    void Render2DCamera::SetHeight(unsigned height) noexcept
    {
        if (height != 0 && m_Height != height)
        {
            m_Height = height;
            RecalculateProjectionMatrix();
        }
    }

    void Render2DCamera::SetZoomLevel(float zoom) noexcept
    {
        if (zoom >= 0.0f && m_ZoomLevel != zoom)
        {
            m_ZoomLevel = zoom;
            RecalculateProjectionMatrix();
        }
    }

    void Render2DCamera::RecalculateProjectionMatrix() noexcept
    {
        float aspectRatio = GetAspectRatio();

        float orthoLeft = -aspectRatio * m_ZoomLevel * 0.5;
        float orthoRight = aspectRatio * m_ZoomLevel * 0.5;
        float orthoTop = m_ZoomLevel * 0.5;
        float orthoBottom = -m_ZoomLevel * 0.5;

        m_Projection = glm::ortho(orthoLeft, orthoRight, orthoBottom, orthoTop, -1.0f, 100.0f);
    }
}
