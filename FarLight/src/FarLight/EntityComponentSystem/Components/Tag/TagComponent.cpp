// This is an open source non-commercial project. Dear PVS-Studio, please check it.
// PVS-Studio Static Code Analyzer for C, C++ and C#: http://www.viva64.com

#include "flpch.h"

#include "FarLight/EntityComponentSystem/Components/Tag/TagComponent.h"

#include "FarLight/Core/Core.h"

#include <imgui.h>

namespace FarLight
{
    void TagComponent::OnUserInterfaceDraw() noexcept
    {
        ImGui::Columns(2, nullptr, false);
        ImGui::SetColumnWidth(0, GetTitleWidth());

        {
            std::string text = "Unique ID";
            ImGui::SetCursorPosX(ImGui::GetCursorPosX() + ImGui::GetColumnWidth() - ImGui::CalcTextSize(text.c_str()).x - ImGui::GetScrollX() - 2 * ImGui::GetStyle().ItemSpacing.x);
            ImGui::Text("%s", "Unique ID");
            ImGui::NextColumn();

            ImGui::PushItemWidth(-1);
            ImGui::Text(GetId().ToString().c_str());
            ImGui::PopItemWidth();
            ImGui::NextColumn();
        }

        {
            std::string text = "Tag";
            ImGui::SetCursorPosX(ImGui::GetCursorPosX() + ImGui::GetColumnWidth() - ImGui::CalcTextSize(text.c_str()).x - ImGui::GetScrollX() - 2 * ImGui::GetStyle().ItemSpacing.x);
            ImGui::Text("%s", text.c_str());
            ImGui::NextColumn();

            ImGui::PushItemWidth(-1);
            ImGui::InputText("##Tag", m_Tag.data(), m_Tag.capacity() + 1, ImGuiInputTextFlags_CallbackResize,
                [](ImGuiInputTextCallbackData* data)
                {
                    std::string* str = static_cast<std::string*>(data->UserData);
                    str->resize(data->BufTextLen);
                    data->Buf = str->data();
                    return 0;
                }, &m_Tag);
            ImGui::PopItemWidth();
            ImGui::NextColumn();
        }

        ImGui::Columns(1, nullptr, false);
    }
}
