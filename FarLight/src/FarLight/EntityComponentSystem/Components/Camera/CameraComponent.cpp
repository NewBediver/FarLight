// This is an open source non-commercial project. Dear PVS-Studio, please check it.
// PVS-Studio Static Code Analyzer for C, C++ and C#: http://www.viva64.com

#include "flpch.h"

#include "FarLight/EntityComponentSystem/Components/Camera/CameraComponent.h"

#include <imgui.h>

#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtc/type_ptr.hpp>

namespace FarLight
{
    CameraComponent::CameraComponent(unsigned width, unsigned height, float zoom, bool isPrimary, bool isFixedAspectRatio) noexcept
        : m_AspectRatio(static_cast<float>(width) / static_cast<float>(height))
        , m_Zoom(zoom)
        , m_Left(0.0f)
        , m_Right(1.0f)
        , m_Top(1.0f)
        , m_Bottom(0.0f)
        , m_Near(-0.1f)
        , m_Far(100.0f)
        , m_CameraFront(glm::vec3(0.0f, 0.0f, -1.0f))
        , m_CameraUp(glm::vec3(0.0f, 1.0f, 0.0f))
        , m_CameraRight(glm::vec3(1.0f, 0.0f, 0.0f))
        , m_IsPrimary(isPrimary)
        , m_IsFixedAspectRatio(isFixedAspectRatio)
        , m_IsProjectionChanged(true)
        , m_ProjectionMatrix(glm::mat4(1.0f))
        , m_ViewMatrix(glm::mat4(1.0f))
    { }

    void CameraComponent::SetAspectRatio(unsigned width, unsigned height) noexcept
    {
        m_AspectRatio = static_cast<float>(width) / static_cast<float>(height);
        m_IsProjectionChanged = true;
    }

    void CameraComponent::SetLeftBound(float left) noexcept
    {
        m_Left = left;
        m_IsProjectionChanged = true;
    }

    void CameraComponent::SetRightBound(float right) noexcept
    {
        m_Right = right;
        m_IsProjectionChanged = true;
    }

    void CameraComponent::SetTopBound(float top) noexcept
    {
        m_Top = top;
        m_IsProjectionChanged = true;
    }

    void CameraComponent::SetBottomBound(float bottom) noexcept
    {
        m_Bottom = bottom;
        m_IsProjectionChanged = true;
    }

    void CameraComponent::SetNearBound(float _near) noexcept
    {
        m_Near = _near;
        m_IsProjectionChanged = true;
    }

    void CameraComponent::SetFarBound(float _far) noexcept
    {
        m_Far = _far;
        m_IsProjectionChanged = true;
    }

    void CameraComponent::SetZoom(float zoom) noexcept
    {
        m_Zoom = zoom;
        m_IsProjectionChanged = true;
    }

    void CameraComponent::SetProjectionMatrix(float left, float right, float bottom, float top, float _near, float _far) noexcept
    {
        m_Left = left;
        m_Right = right;
        m_Bottom = bottom;
        m_Top = top;
        m_Near = _near;
        m_Far = _far;
        m_IsProjectionChanged = true;
    }

    const glm::mat4& CameraComponent::GetViewMatrix(const glm::vec3& position, const glm::vec3& rotation) noexcept
    {
        glm::vec3 cameraUp = glm::vec3(sin(rotation.z), cos(rotation.z), 0.0f);
        glm::vec3 cameraRight = glm::vec3(cos(rotation.z), -sin(rotation.z), 0.0f);
        m_CameraUp = glm::normalize(cameraUp);
        m_CameraRight = glm::normalize(cameraRight);
        RecalculateViewMatrix(position);
        return m_ViewMatrix;
    }

    void CameraComponent::RecalculateViewMatrix(const glm::vec3& position) noexcept
    {
        m_ViewMatrix = glm::lookAt(position, position + m_CameraFront, m_CameraUp);
    }

    const glm::mat4& CameraComponent::GetProjectionMatrix() noexcept
    {
        if (m_IsProjectionChanged)
            RecalculateProjectionMatrix();
        return m_ProjectionMatrix;
    }

    void CameraComponent::RecalculateProjectionMatrix() noexcept
    {
        float deltaX = m_Right - m_Left;
        float deltaY = m_Top - m_Bottom;

        float left = -deltaX * 0.5 * m_AspectRatio * m_Zoom;
        float right = deltaX * 0.5 * m_AspectRatio * m_Zoom;
        float bottom = -deltaY * 0.5 * m_Zoom;
        float top = deltaY * 0.5 * m_Zoom;

        m_ProjectionMatrix = glm::ortho(left, right, bottom, top, m_Near, m_Far);
        m_IsProjectionChanged = false;
    }

    void CameraComponent::OnUserInterfaceDraw() noexcept
    {
        ImGui::Checkbox("Is primary", &m_IsPrimary);
        ImGui::Checkbox("Is fixed aspect ratio", &m_IsFixedAspectRatio);
        ImGui::SliderFloat("AspectRatio", &m_AspectRatio, 0.1f, 2.0f, "%.3f", ImGuiSliderFlags_None);
        ImGui::DragFloat("Zoom", &m_Zoom, 0.1f, 0.0, std::numeric_limits<float>::max(), "%.1f", ImGuiSliderFlags_None);
        ImGui::DragFloat("Left", &m_Left, 0.1f, 0.0, std::numeric_limits<float>::max(), "%.1f", ImGuiSliderFlags_None);
        ImGui::DragFloat("Right", &m_Right, 0.1f, 0.0, std::numeric_limits<float>::max(), "%.1f", ImGuiSliderFlags_None);
        ImGui::DragFloat("Top", &m_Top, 0.1f, 0.0, std::numeric_limits<float>::max(), "%.1f", ImGuiSliderFlags_None);
        ImGui::DragFloat("Bottom", &m_Bottom, 0.1f, 0.0, std::numeric_limits<float>::max(), "%.1f", ImGuiSliderFlags_None);
        ImGui::DragFloat("Near", &m_Near, 0.1f, 0.0, std::numeric_limits<float>::max(), "%.1f", ImGuiSliderFlags_None);
        ImGui::DragFloat("Far", &m_Far, 0.1f, 0.0, std::numeric_limits<float>::max(), "%.1f", ImGuiSliderFlags_None);
        m_IsProjectionChanged = true;
    }
}
