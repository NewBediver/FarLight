// This is an open source non-commercial project. Dear PVS-Studio, please check it.
// PVS-Studio Static Code Analyzer for C, C++ and C#: http://www.viva64.com

#include "flpch.h"

#include "FarLight/EntityComponentSystem/Components/Camera/CameraComponent.h"

#include <imgui.h>

#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtc/type_ptr.hpp>

namespace FarLight
{
    void CameraComponent::OnUserInterfaceDraw() noexcept
    {
        ImGui::Checkbox("Is primary", &m_IsPrimary);
        ImGui::Checkbox("Is fixed aspect ratio", &m_IsFixedAspectRatio);
        {
            float zoom = m_Camera->GetZoom();
            if (ImGui::DragFloat("Zoom level", &zoom, 0.001f, 0.0f, std::numeric_limits<float>::max(), "%.3f", ImGuiSliderFlags_None))
                m_Camera->SetZoom(zoom);
        }
        {
            int resolution[2] = { m_Camera->GetResolutionWidth(), m_Camera->GetResolutionHeight() };
            ImGui::Text("Resolution");
            if (ImGui::DragInt2("Width / Height", resolution, 1, 0, std::numeric_limits<int>::max()))
            {
                m_Camera->SetResolutionWidth(resolution[0]);
                m_Camera->SetResolutionHeight(resolution[1]);
            }
        }
        {
            glm::vec2 clippingPlane = { m_Camera->GetNearBound(), m_Camera->GetFarBound() };
            ImGui::Text("Clipping Plane");
            if (ImGui::DragFloat2("Near / Far", glm::value_ptr(clippingPlane), 0.001f, 0.0f, std::numeric_limits<float>::max(), "%.3f", ImGuiSliderFlags_None))
            {
                m_Camera->SetNearBound(clippingPlane.x);
                m_Camera->SetFarBound(clippingPlane.y);
            }
        }
        {
            glm::vec2 leftRight = { m_Camera->GetLeftBound(), m_Camera->GetRightBound() };
            glm::vec2 bottomTop = { m_Camera->GetBottomBound(), m_Camera->GetTopBound() };
            ImGui::Text("Normalized Viewport Rectangle");
            if (ImGui::DragFloat2("Left / Right", glm::value_ptr(leftRight), 0.001f, 0.0f, 1.0f, "%.3f", ImGuiSliderFlags_None))
            {
                m_Camera->SetLeftBound(leftRight.x);
                m_Camera->SetRightBound(leftRight.y);
            }
            if (ImGui::DragFloat2("Bottom / Top", glm::value_ptr(bottomTop), 0.001f, 0.0f, 1.0f, "%.3f", ImGuiSliderFlags_None))
            {
                m_Camera->SetBottomBound(bottomTop.x);
                m_Camera->SetTopBound(bottomTop.y);
            }
        }
        {
            glm::vec4 color = m_Camera->GetBackgroundColor();
            if (ImGui::ColorEdit4("Background color", glm::value_ptr(color)))
                m_Camera->SetBackgroundColor(color);
        }
        ImGui::Separator();
        {
            float aspectRatio = m_Camera->GetAspectRatio();
            ImGui::DragFloat("Aspect Ratio", &aspectRatio, 0.001f, 0.0f, std::numeric_limits<float>::max(), "%.3f", ImGuiSliderFlags_NoInput);
        }
        {
            glm::vec3 cameraRight = m_Camera->GetRightDirection();
            glm::vec3 cameraUp = m_Camera->GetUpDirection();
            glm::vec3 cameraFront = m_Camera->GetFrontDirection();
            ImGui::Text("Camera vectors");
            ImGui::DragFloat3("Right vector", glm::value_ptr(cameraRight), 0.001f, 0.0f, 1.0f, "%.3f", ImGuiSliderFlags_NoInput);
            ImGui::DragFloat3("Up vector", glm::value_ptr(cameraUp), 0.001f, 0.0f, 1.0f, "%.3f", ImGuiSliderFlags_NoInput);
            ImGui::DragFloat3("Front vector", glm::value_ptr(cameraFront), 0.001f, 0.0f, 1.0f, "%.3f", ImGuiSliderFlags_NoInput);
        }

    }
}
