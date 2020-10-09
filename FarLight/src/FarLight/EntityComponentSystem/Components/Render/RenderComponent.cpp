// This is an open source non-commercial project. Dear PVS-Studio, please check it.
// PVS-Studio Static Code Analyzer for C, C++ and C#: http://www.viva64.com

#include "flpch.h"

#include "FarLight/EntityComponentSystem/Components/Render/RenderComponent.h"

#include <imgui.h>

#include <glm/gtc/type_ptr.hpp>

#include <boost/uuid/string_generator.hpp>

#include <vector>
#include <string>

#include "FarLight/ResourceSystem/Resources/ShaderLibrary.h"

namespace FarLight
{
    void RenderComponent::OnUserInterfaceDraw() noexcept
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
            std::string text = "Color";
            ImGui::SetCursorPosX(ImGui::GetCursorPosX() + ImGui::GetColumnWidth() - ImGui::CalcTextSize(text.c_str()).x - ImGui::GetScrollX() - 2 * ImGui::GetStyle().ItemSpacing.x);
            ImGui::Text("%s", text.c_str());
            ImGui::NextColumn();

            ImGui::PushItemWidth(-1);
            ImGui::ColorEdit4("##Color", glm::value_ptr(m_Color));
            ImGui::PopItemWidth();
            ImGui::NextColumn();
        }

        ImGui::Columns(1, nullptr, false);

        /*std::vector<std::string> items = ShaderLibrary::GetInstance().GetIdsList();
        if (ImGui::BeginCombo("shaders", (m_ShaderIndex == -1 ? "Choose shader" : items[m_ShaderIndex].c_str()))) // The second parameter is the label previewed before opening the combo.
        {
            for (int i = 0; i < items.size(); ++i)
            {
                bool isSelected = (m_ShaderIndex == i);
                if (ImGui::Selectable(items[i].c_str(), isSelected)) m_ShaderIndex = i;
                if (isSelected) ImGui::SetItemDefaultFocus();
            }
            ImGui::EndCombo();
        }*/
    }
}
