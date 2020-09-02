// This is an open source non-commercial project. Dear PVS-Studio, please check it.
// PVS-Studio Static Code Analyzer for C, C++ and C#: http://www.viva64.com

#include "flpch.h"

#include "FarLight/EntityComponentSystem/Components/Tag/TagComponent.h"

#include "FarLight/Core/Core.h"

#include <imgui.h>

namespace FarLight
{
    TagComponent::TagComponent(const std::string& tag) noexcept
        : m_Tag(tag)
    { }

    void TagComponent::OnUserInterfaceDraw() noexcept
    {
        ImGui::InputText("Tag", m_Tag.data(), m_Tag.capacity() + 1, ImGuiInputTextFlags_CallbackResize,
            [](ImGuiInputTextCallbackData* data)
            {
                std::string* str = static_cast<std::string*>(data->UserData);
                str->resize(data->BufTextLen);
                data->Buf = str->data();
                return 0;
            }, &m_Tag);
    }
}
