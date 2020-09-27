#include "flpch.h"

#include "FarLight/EditorSystem/EditorPanels/SceneHierarchyPanel/SceneHierarchyPanel.h"

#include <imgui.h>

namespace FarLight
{
    void SceneHierarchyPanel::ShowContent() noexcept
    {
        auto entities = m_Scene->GetEntities<TagComponent>();

        ImGui::Begin(GetTitle().c_str());

        for (int i = 0; i < entities.size(); ++i)
        {
            ImGui::PushID(i);

            auto& tagComp = entities[i].GetComponent<TagComponent>();

            bool open = false;
            if (i == m_SelectedEntity) open = ImGui::TreeNodeEx(tagComp.GetTag().c_str(), ImGuiTreeNodeFlags_OpenOnArrow | ImGuiTreeNodeFlags_Selected);
            else open = ImGui::TreeNodeEx(tagComp.GetTag().c_str(), ImGuiTreeNodeFlags_OpenOnArrow);

            if (ImGui::IsItemClicked(ImGuiMouseButton_Left))
            {
                m_SelectedEntity = i;
                m_ComponentsPanel = CreateScope<ComponentsPanel>(CreateRef<Entity>(entities[i]));
            }

            if (open) ImGui::TreePop();

            ImGui::PopID();
        }

        bool created = ShowAddEntityButton();
        if (m_SelectedEntity != -1)
        {
            ImGui::SameLine();
            if (ShowDeleteEntityButton(entities[m_SelectedEntity]))
            {
                m_SelectedEntity = -1;
                m_ComponentsPanel.reset();
                created = false;
            }
        }
        if (created) ++m_SelectedEntity;

        ImGui::End();

        if (m_ComponentsPanel != nullptr) m_ComponentsPanel->ShowContent();
    }

    // Returns true if entity was deleted
    //         false otherwise
    bool SceneHierarchyPanel::ShowDeleteEntityButton(Entity ent) noexcept
    {
        if (ImGui::Button("Delete"))
        {
            m_Scene->DestroyEntity(ent);
            return true;
        }
        return false;
    }

    // Returns true if entity was created
    //         false otherwise
    bool SceneHierarchyPanel::ShowAddEntityButton() noexcept
    {
        bool created = false;
        if (ImGui::Button("Add Entity")) ImGui::OpenPopup("Entity Popup");
        if (ImGui::BeginPopup("Entity Popup"))
        {
            if (ImGui::Selectable("Empty"))
            {
                m_Scene->CreateEntity();
                created = true;
            }
            if (ImGui::Selectable("Square"))
            {
                m_Scene->CreateSquare();
                created = true;
            }
            if (ImGui::Selectable("Camera"))
            {
                m_Scene->CreateCamera();
                created = true;
            }
            ImGui::EndPopup();
        }
        return created;
    }
}
