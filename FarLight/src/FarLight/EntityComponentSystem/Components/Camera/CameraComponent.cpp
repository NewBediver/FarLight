// This is an open source non-commercial project. Dear PVS-Studio, please check it.
// PVS-Studio Static Code Analyzer for C, C++ and C#: http://www.viva64.com

#include "flpch.h"

#include "FarLight/EntityComponentSystem/Components/Camera/CameraComponent.h"

#include <imgui.h>
#include <imgui_internal.h>

#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtc/type_ptr.hpp>

namespace FarLight
{
    void CameraComponent::OnUserInterfaceDraw() noexcept
    {
        ImGui::Columns(2, "Is Fixed Aspect Ratio", false);
        ImGui::SetColumnWidth(0, ImGui::CalcTextSize("Is Fixed Aspect Ratio").x + 2 * ImGui::GetStyle().ItemSpacing.x);
        {
            std::string text = "Is primary";
            ImGui::SetCursorPosX(ImGui::GetCursorPosX() + ImGui::GetColumnWidth() - ImGui::CalcTextSize(text.c_str()).x - ImGui::GetScrollX() - 2 * ImGui::GetStyle().ItemSpacing.x);
            ImGui::Text("%s", text.c_str());
            ImGui::NextColumn();

            ImGui::Checkbox("##IsPrimary", &m_IsPrimary);
            ImGui::NextColumn();

            text = "Is Fixed Aspect Ratio";
            ImGui::SetCursorPosX(ImGui::GetCursorPosX() + ImGui::GetColumnWidth() - ImGui::CalcTextSize(text.c_str()).x - ImGui::GetScrollX() - 2 * ImGui::GetStyle().ItemSpacing.x);
            ImGui::Text("%s", text.c_str());
            ImGui::NextColumn();

            ImGui::Checkbox("##IsFixedAspectRatio", &m_IsFixedAspectRatio);
            ImGui::NextColumn();
        }
        ImGui::Columns(1, nullptr, false);

        ImGui::Columns(2, nullptr, false);
        ImGui::SetColumnWidth(0, GetTitleWidth());
        {
            std::string text = "Zoom level";
            ImGui::SetCursorPosX(ImGui::GetCursorPosX() + ImGui::GetColumnWidth() - ImGui::CalcTextSize(text.c_str()).x - ImGui::GetScrollX() - 2 * ImGui::GetStyle().ItemSpacing.x);
            ImGui::Text("%s", text.c_str());
            ImGui::NextColumn();

            ImGui::PushItemWidth(-1);
            float zoom = m_Camera->GetZoom();
            if (ImGui::DragFloat("##ZoomLevel", &zoom, 0.001f, 0.0f, std::numeric_limits<float>::max(), "%.3f", ImGuiSliderFlags_None))
                m_Camera->SetZoom(zoom);
            ImGui::PopItemWidth();
            ImGui::NextColumn();
        }

        ImGui::Columns(1, nullptr, false);
        {
            std::string text = "Resolution";
            ImGui::SetCursorPosX((ImGui::GetCursorPosX() + ImGui::GetColumnWidth() - 2 * ImGui::GetStyle().ItemSpacing.x - ImGui::CalcTextSize(text.c_str()).x - ImGui::GetScrollX()) / 2);
            ImGui::Text("%s", text.c_str());
        }

        ImGui::Columns(2, nullptr, false);
        ImGui::SetColumnWidth(0, GetTitleWidth());
        {
            std::string text = "Width";
            ImGui::SetCursorPosX(ImGui::GetCursorPosX() + ImGui::GetColumnWidth() - ImGui::CalcTextSize(text.c_str()).x - ImGui::GetScrollX() - 2 * ImGui::GetStyle().ItemSpacing.x);
            ImGui::Text("%s", text.c_str());
            ImGui::NextColumn();

            int width = m_Camera->GetResolutionWidth();
            ImGui::PushItemWidth(-1);
            if (ImGui::DragInt("##Width", &width, 1, 0, std::numeric_limits<int>::max()))
                m_Camera->SetResolutionWidth(width);
            ImGui::PopItemWidth();
            ImGui::NextColumn();

            text = "Height";
            ImGui::SetCursorPosX(ImGui::GetCursorPosX() + ImGui::GetColumnWidth() - ImGui::CalcTextSize(text.c_str()).x - ImGui::GetScrollX() - 2 * ImGui::GetStyle().ItemSpacing.x);
            ImGui::Text("%s", text.c_str());
            ImGui::NextColumn();

            int height = m_Camera->GetResolutionHeight();
            ImGui::PushItemWidth(-1);
            if (ImGui::DragInt("##Height", &height, 1, 0, std::numeric_limits<int>::max()))
                m_Camera->SetResolutionHeight(height);
            ImGui::PopItemWidth();
            ImGui::NextColumn();
        }

        ImGui::Columns(1, nullptr, false);
        {
            std::string text = "Clipping Plane";
            ImGui::SetCursorPosX((ImGui::GetCursorPosX() + ImGui::GetColumnWidth() - 2 * ImGui::GetStyle().ItemSpacing.x - ImGui::CalcTextSize(text.c_str()).x - ImGui::GetScrollX()) / 2);
            ImGui::Text("%s", text.c_str());
        }

        ImGui::Columns(2, nullptr, false);
        ImGui::SetColumnWidth(0, GetTitleWidth());
        {
            std::string text = "Near";
            ImGui::SetCursorPosX(ImGui::GetCursorPosX() + ImGui::GetColumnWidth() - ImGui::CalcTextSize(text.c_str()).x - ImGui::GetScrollX() - 2 * ImGui::GetStyle().ItemSpacing.x);
            ImGui::Text("%s", text.c_str());
            ImGui::NextColumn();

            float near_ = m_Camera->GetNearBound();
            ImGui::PushItemWidth(-1);
            if (ImGui::SliderFloat("##Near", &near_, 0.0f, 1000.0f))
                m_Camera->SetNearBound(near_);
            ImGui::PopItemWidth();
            ImGui::NextColumn();

            text = "Far";
            ImGui::SetCursorPosX(ImGui::GetCursorPosX() + ImGui::GetColumnWidth() - ImGui::CalcTextSize(text.c_str()).x - ImGui::GetScrollX() - 2 * ImGui::GetStyle().ItemSpacing.x);
            ImGui::Text("%s", text.c_str());
            ImGui::NextColumn();

            float far_ = m_Camera->GetFarBound();
            ImGui::PushItemWidth(-1);
            if (ImGui::SliderFloat("##Far", &far_, 0.0f, 1000.0f))
                m_Camera->SetFarBound(far_);
            ImGui::PopItemWidth();
            ImGui::NextColumn();
        }

        ImGui::Columns(1, nullptr, false);
        {
            std::string text = "Normalized Viewport Rectangle";
            ImGui::SetCursorPosX((ImGui::GetCursorPosX() + ImGui::GetColumnWidth() - 2 * ImGui::GetStyle().ItemSpacing.x - ImGui::CalcTextSize(text.c_str()).x - ImGui::GetScrollX()) / 2);
            ImGui::Text("%s", text.c_str());
        }

        ImGui::Columns(4, nullptr, false);
        {
            std::string text = "Left";
            ImGui::SetCursorPosX(ImGui::GetCursorPosX() + ImGui::GetColumnWidth() - ImGui::CalcTextSize(text.c_str()).x - ImGui::GetScrollX() - 2 * ImGui::GetStyle().ItemSpacing.x);
            ImGui::Text("%s", text.c_str());
            ImGui::NextColumn();

            float left = m_Camera->GetLeftBound();
            ImGui::PushItemWidth(-1);
            if (ImGui::SliderFloat("##Left", &left, 0.0f, 1.0f))
                m_Camera->SetLeftBound(left);
            ImGui::PopItemWidth();
            ImGui::NextColumn();

            float right = m_Camera->GetRightBound();
            ImGui::PushItemWidth(-1);
            if (ImGui::SliderFloat("##Right", &right, 0.0f, 1.0f))
                m_Camera->SetRightBound(right);
            ImGui::PopItemWidth();
            ImGui::NextColumn();

            text = "Right";
            ImGui::Text("%s", text.c_str());
            ImGui::NextColumn();

            text = "Bottom";
            ImGui::SetCursorPosX(ImGui::GetCursorPosX() + ImGui::GetColumnWidth() - ImGui::CalcTextSize(text.c_str()).x - ImGui::GetScrollX() - 2 * ImGui::GetStyle().ItemSpacing.x);
            ImGui::Text("%s", text.c_str());
            ImGui::NextColumn();

            float bottom = m_Camera->GetBottomBound();
            ImGui::PushItemWidth(-1);
            if (ImGui::SliderFloat("##Bottom", &bottom, 0.0f, 1.0f))
                m_Camera->SetBottomBound(bottom);
            ImGui::PopItemWidth();
            ImGui::NextColumn();

            float top = m_Camera->GetTopBound();
            ImGui::PushItemWidth(-1);
            if (ImGui::SliderFloat("##Top", &top, 0.0f, 1.0f))
                m_Camera->SetTopBound(top);
            ImGui::PopItemWidth();
            ImGui::NextColumn();

            text = "Top";
            ImGui::Text("%s", text.c_str());
            ImGui::NextColumn();
        }

        ImGui::Columns(2, "Background color", false);
        ImGui::SetColumnWidth(0, ImGui::CalcTextSize("Background color").x + 2 * ImGui::GetStyle().ItemSpacing.x);
        {
            std::string text = "Background color";
            ImGui::SetCursorPosX(ImGui::GetCursorPosX() + ImGui::GetColumnWidth() - ImGui::CalcTextSize(text.c_str()).x - ImGui::GetScrollX() - 2 * ImGui::GetStyle().ItemSpacing.x);
            ImGui::Text("%s", text.c_str());
            ImGui::NextColumn();

            glm::vec4 color = m_Camera->GetBackgroundColor();
            ImGui::PushItemWidth(-1);
            if (ImGui::ColorEdit4("##BackgroundColor", glm::value_ptr(color)))
                m_Camera->SetBackgroundColor(color);
            ImGui::PopItemWidth();
            ImGui::NextColumn();

            text = "Aspect Ratio";
            ImGui::SetCursorPosX(ImGui::GetCursorPosX() + ImGui::GetColumnWidth() - ImGui::CalcTextSize(text.c_str()).x - ImGui::GetScrollX() - 2 * ImGui::GetStyle().ItemSpacing.x);
            ImGui::Text("%s", text.c_str());
            ImGui::NextColumn();

            float aspectRatio = m_Camera->GetAspectRatio();
            ImGui::PushItemWidth(-1);
            ImGui::DragFloat("##AspectRatio", &aspectRatio, 0.001f, 0.0f, std::numeric_limits<float>::max(), "%.3f", ImGuiSliderFlags_NoInput);
            ImGui::PopItemWidth();
            ImGui::NextColumn();
        }

        ImGui::Columns(1, nullptr, false);
        {
            std::string text = "Camera Vectors";
            ImGui::SetCursorPosX((ImGui::GetCursorPosX() + ImGui::GetColumnWidth() - 2 * ImGui::GetStyle().ItemSpacing.x - ImGui::CalcTextSize(text.c_str()).x - ImGui::GetScrollX()) / 2);
            ImGui::Text("%s", text.c_str());
        }

        ImGui::Columns(2, "Right vector", false);
        ImGui::SetColumnWidth(0, ImGui::CalcTextSize("Right vector").x + 2 * ImGui::GetStyle().ItemSpacing.x);
        {
            std::string text = "Right vector";
            ImGui::SetCursorPosX(ImGui::GetCursorPosX() + ImGui::GetColumnWidth() - ImGui::CalcTextSize(text.c_str()).x - ImGui::GetScrollX() - 2 * ImGui::GetStyle().ItemSpacing.x);
            ImGui::Text("%s", text.c_str());
            ImGui::NextColumn();

            glm::vec3 cameraRight = m_Camera->GetRightDirection();
            ImGui::PushItemWidth(-1);
            ImGui::DragFloat3("##RightVector", glm::value_ptr(cameraRight), 0.001f, 0.0f, 1.0f, "%.3f", ImGuiSliderFlags_NoInput);
            ImGui::PopItemWidth();
            ImGui::NextColumn();

            text = "Up vector";
            ImGui::SetCursorPosX(ImGui::GetCursorPosX() + ImGui::GetColumnWidth() - ImGui::CalcTextSize(text.c_str()).x - ImGui::GetScrollX() - 2 * ImGui::GetStyle().ItemSpacing.x);
            ImGui::Text("%s", text.c_str());
            ImGui::NextColumn();

            glm::vec3 cameraUp = m_Camera->GetUpDirection();
            ImGui::PushItemWidth(-1);
            ImGui::DragFloat3("##UpVector", glm::value_ptr(cameraUp), 0.001f, 0.0f, 1.0f, "%.3f", ImGuiSliderFlags_NoInput);
            ImGui::PopItemWidth();
            ImGui::NextColumn();

            text = "Front vector";
            ImGui::SetCursorPosX(ImGui::GetCursorPosX() + ImGui::GetColumnWidth() - ImGui::CalcTextSize(text.c_str()).x - ImGui::GetScrollX() - 2 * ImGui::GetStyle().ItemSpacing.x);
            ImGui::Text("%s", text.c_str());
            ImGui::NextColumn();

            glm::vec3 cameraFront = m_Camera->GetFrontDirection();
            ImGui::PushItemWidth(-1);
            ImGui::DragFloat3("##FrontVector", glm::value_ptr(cameraFront), 0.001f, 0.0f, 1.0f, "%.3f", ImGuiSliderFlags_NoInput);
            ImGui::PopItemWidth();
            ImGui::NextColumn();
        }

        ImGui::Columns(1, nullptr, false);
    }
}
