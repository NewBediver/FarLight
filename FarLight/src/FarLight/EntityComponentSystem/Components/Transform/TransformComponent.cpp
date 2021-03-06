// This is an open source non-commercial project. Dear PVS-Studio, please check it.
// PVS-Studio Static Code Analyzer for C, C++ and C#: http://www.viva64.com

#include "flpch.h"

#include "FarLight/EntityComponentSystem/Components/Transform/TransformComponent.h"

#include <imgui.h>

#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtc/type_ptr.hpp>

namespace FarLight
{
    const glm::mat4& TransformComponent::GetTransformationMatrix() noexcept
    {
        if (m_IsDataChanged)
            RecalculateTransformMatix();
        return m_Transform;
    }

    void TransformComponent::SetPosition(const glm::vec3& position) noexcept
    {
        if (m_Position != position)
        {
            m_Position = position;
            m_IsDataChanged = true;
        }
    }

    void TransformComponent::SetSize(const glm::vec3& size) noexcept
    {
        FL_CORE_ASSERT(size.x >= 0.0f && size.y >= 0.0f && size.z >= 0.0f, "Size cannot be less than zero!");

        if (size.x >= 0.0f && size.y >= 0.0f && size.z >= 0.0f && m_Size != size)
        {
            m_Size = size;
            m_IsDataChanged = true;
        }
    }

    void TransformComponent::SetRotation(const glm::vec3& rotation) noexcept
    {
        if (m_Rotation != rotation)
        {
            m_Rotation = rotation;
            m_IsDataChanged = true;
        }
    }

    void TransformComponent::RecalculateTransformMatix() noexcept
    {
        m_Transform = glm::translate(glm::mat4(1.0f), m_Position)
            * glm::rotate(glm::mat4(1.0f), m_Rotation.x, glm::vec3(1.0f, 0.0f, 0.0f))
            * glm::rotate(glm::mat4(1.0f), m_Rotation.y, glm::vec3(0.0f, 1.0f, 0.0f))
            * glm::rotate(glm::mat4(1.0f), m_Rotation.z, glm::vec3(0.0f, 0.0f, 1.0f))
            * glm::scale(glm::mat4(1.0f), m_Size);
        m_IsDataChanged = false;
    }

    void TransformComponent::OnUserInterfaceDraw() noexcept
    {
        ImGui::Columns(2, nullptr, false);
        ImGui::SetColumnWidth(0, GetTitleWidth());

        {
            std::string text = "Unique ID";
            ImGui::SetCursorPosX(ImGui::GetCursorPosX() + ImGui::GetColumnWidth() - ImGui::CalcTextSize(text.c_str()).x - ImGui::GetScrollX() - 2 * ImGui::GetStyle().ItemSpacing.x);
            ImGui::Text("%s", text.c_str());
            ImGui::NextColumn();

            ImGui::PushItemWidth(-1);
            ImGui::Text(GetId().ToString().c_str());
            ImGui::PopItemWidth();
            ImGui::NextColumn();
        }

        {
            std::string text = "Position";
            ImGui::SetCursorPosX(ImGui::GetCursorPosX() + ImGui::GetColumnWidth() - ImGui::CalcTextSize(text.c_str()).x - ImGui::GetScrollX() - 2 * ImGui::GetStyle().ItemSpacing.x);
            ImGui::Text("%s", text.c_str());
            ImGui::NextColumn();

            ImGui::PushItemWidth(-1);
            if (ImGui::DragFloat3("##Position", glm::value_ptr(m_Position), 0.001f, 0.0f))
                m_IsDataChanged = true;
            ImGui::PopItemWidth();
            ImGui::NextColumn();
        }
        
        {
            std::string text = "Size";
            ImGui::SetCursorPosX(ImGui::GetCursorPosX() + ImGui::GetColumnWidth() - ImGui::CalcTextSize(text.c_str()).x - ImGui::GetScrollX() - 2 * ImGui::GetStyle().ItemSpacing.x);
            ImGui::Text("%s", text.c_str());
            ImGui::NextColumn();

            ImGui::PushItemWidth(-1);
            if (ImGui::DragFloat3("##Size", glm::value_ptr(m_Size), 0.001f, 0.0f, std::numeric_limits<float>::max(), "%.3f", ImGuiSliderFlags_None))
                m_IsDataChanged = true;
            ImGui::PopItemWidth();
            ImGui::NextColumn();
        }

        {
            std::string text = "Rotation";
            ImGui::SetCursorPosX(ImGui::GetCursorPosX() + ImGui::GetColumnWidth() - ImGui::CalcTextSize(text.c_str()).x - ImGui::GetScrollX() - 2 * ImGui::GetStyle().ItemSpacing.x);
            ImGui::Text("%s", text.c_str());
            ImGui::NextColumn();

            ImGui::PushItemWidth(-1);
            glm::vec3 degrees = glm::vec3(glm::degrees(m_Rotation.x), glm::degrees(m_Rotation.y), glm::degrees(m_Rotation.z));
            if (ImGui::DragFloat3("##Rotation", glm::value_ptr(degrees)))
            {
                m_IsDataChanged = true;
                m_Rotation = glm::vec3(glm::radians(degrees.x), glm::radians(degrees.y), glm::radians(degrees.z));
            }
            ImGui::PopItemWidth();
            ImGui::NextColumn();
        }
        
        ImGui::Columns(1, nullptr, false);
    }
}
