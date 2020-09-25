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
        ImGui::Columns(2, nullptr, false);
        ImGui::SetColumnWidth(0, 180);
        {
            std::string text = "Is primary";
            ImGui::SetCursorPosX(ImGui::GetCursorPosX() + ImGui::GetColumnWidth() - ImGui::CalcTextSize(text.c_str()).x - ImGui::GetScrollX() - 2 * ImGui::GetStyle().ItemSpacing.x);
            ImGui::Text("%s", text.c_str());
            ImGui::NextColumn();

            ImGui::Checkbox("##IsPrimary", &m_IsPrimary);
            ImGui::NextColumn();
        }

        {
            std::string text = "Is Fixed Aspect Ratio";
            ImGui::SetCursorPosX(ImGui::GetCursorPosX() + ImGui::GetColumnWidth() - ImGui::CalcTextSize(text.c_str()).x - ImGui::GetScrollX() - 2 * ImGui::GetStyle().ItemSpacing.x);
            ImGui::Text("%s", text.c_str());
            ImGui::NextColumn();

            ImGui::Checkbox("##IsFixedAspectRatio", &m_IsFixedAspectRatio);
            ImGui::NextColumn();
        }

        ImGui::Columns(2, nullptr, false);
        ImGui::SetColumnWidth(0, GetTitleWidth());
        {
            std::string text = "Zoom level";
            ImGui::SetCursorPosX(ImGui::GetCursorPosX() + ImGui::GetColumnWidth() - ImGui::CalcTextSize(text.c_str()).x - ImGui::GetScrollX() - 2 * ImGui::GetStyle().ItemSpacing.x);
            ImGui::Text("%s", text.c_str());
            ImGui::NextColumn();

            ImGui::PushItemWidth(ImGui::GetColumnWidth() - 2 * ImGui::GetStyle().ItemSpacing.x);
            float zoom = m_Camera->GetZoom();
            if (ImGui::DragFloat("##ZoomLevel", &zoom, 0.001f, 0.0f, std::numeric_limits<float>::max(), "%.3f", ImGuiSliderFlags_None))
                m_Camera->SetZoom(zoom);
            ImGui::PopItemWidth();
            ImGui::NextColumn();
        }

        {
            ImGui::Columns(1, nullptr, false);
            std::string text = "Resolution";
            ImGui::SetCursorPosX((ImGui::GetCursorPosX() + ImGui::GetColumnWidth() - 2 * ImGui::GetStyle().ItemSpacing.x - ImGui::CalcTextSize(text.c_str()).x - ImGui::GetScrollX()) / 2 );
            ImGui::Text("%s", text.c_str());

            ImGui::Columns(2, nullptr, false);
            ImGui::SetColumnWidth(0, GetTitleWidth());

            text = "Width";
            ImGui::SetCursorPosX(ImGui::GetCursorPosX() + ImGui::GetColumnWidth() - ImGui::CalcTextSize(text.c_str()).x - ImGui::GetScrollX() - 2 * ImGui::GetStyle().ItemSpacing.x);
            ImGui::Text("%s", text.c_str());
            ImGui::NextColumn();

            int width = m_Camera->GetResolutionWidth();
            ImGui::PushItemWidth(ImGui::GetColumnWidth() - 2 * ImGui::GetStyle().ItemSpacing.x);
            if (ImGui::DragInt("##Width", &width, 1, 0, std::numeric_limits<int>::max()))
                m_Camera->SetResolutionWidth(width);
            ImGui::PopItemWidth();
            ImGui::NextColumn();

            text = "Height";
            ImGui::SetCursorPosX(ImGui::GetCursorPosX() + ImGui::GetColumnWidth() - ImGui::CalcTextSize(text.c_str()).x - ImGui::GetScrollX() - 2 * ImGui::GetStyle().ItemSpacing.x);
            ImGui::Text("%s", text.c_str());
            ImGui::NextColumn();

            int height = m_Camera->GetResolutionHeight();
            ImGui::PushItemWidth(ImGui::GetColumnWidth() - 2 * ImGui::GetStyle().ItemSpacing.x);
            if (ImGui::DragInt("##Height", &height, 1, 0, std::numeric_limits<int>::max()))
                m_Camera->SetResolutionHeight(height);
            ImGui::PopItemWidth();
            ImGui::NextColumn();
        }



        ImGui::Columns(1, nullptr, false);

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
