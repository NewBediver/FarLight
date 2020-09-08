
#include "EditorPanels/SceneHierarchyPanel/SceneHierarchyPanel.h"

#include <imgui.h>

namespace FarLight
{
    void SceneHierarchyPanel::ShowContent() noexcept
    {
        if (m_IsShown)
        {
            ImGui::Begin(m_Title.c_str(), &m_IsShown);

            auto entities = m_Scene->GetEntities<TagComponent>();

            for (int i = 0; i < entities.size(); ++i)
            {
                ImGui::PushID(i);

                auto& tagComp = entities[i].GetComponent<TagComponent>();

                bool open = ImGui::TreeNodeEx(tagComp.GetTag().c_str(), ImGuiTreeNodeFlags_OpenOnArrow);

                if (ImGui::IsItemClicked(ImGuiMouseButton_Left))
                    m_ComponentsPanel = CreateRef<ComponentsPanel>(CreateRef<Entity>(entities[i]), true);

                ShowEntityPopupMenu(entities[i]);

                if (open)
                    ImGui::TreePop();

                ImGui::PopID();
            }

            if (m_ComponentsPanel != nullptr)
                m_ComponentsPanel->ShowContent();

            ImGui::End();
        }
    }

    void SceneHierarchyPanel::ShowEntityPopupMenu(Entity ent) noexcept
    {
        if (ImGui::BeginPopupContextItem())
        {
            if (ImGui::MenuItem("Delete entity")) m_Scene->DestroyEntity(ent);
            ImGui::EndPopup();
        }
    }
}
