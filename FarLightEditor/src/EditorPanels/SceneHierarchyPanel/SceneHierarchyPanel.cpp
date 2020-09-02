
#include "EditorPanels/SceneHierarchyPanel/SceneHierarchyPanel.h"

#include <imgui.h>

namespace FarLight
{
    SceneHierarchyPanel::SceneHierarchyPanel(const Ref<Scene>& scene, bool show, const std::string& title) noexcept
        : m_Scene(scene)
        , m_IsShown(show)
        , m_Title(title)
        , m_ComponentsPanel(nullptr)
    { }

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
                if (ImGui::TreeNodeEx(tagComp.GetTag().c_str(), ImGuiTreeNodeFlags_OpenOnArrow))
                    ImGui::TreePop();

                if (ImGui::IsItemClicked())
                    m_ComponentsPanel = CreateRef<ComponentsPanel>(CreateRef<Entity>(entities[i]), true);

                ImGui::PopID();
            }

            if (m_ComponentsPanel != nullptr)
                m_ComponentsPanel->ShowContent();

            ImGui::End();
        }
    }
}
