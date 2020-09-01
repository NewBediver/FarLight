#include "SceneHierarchyPanel.h"

#include "imgui.h"

namespace FarLight
{
    SceneHierarchyPanel::SceneHierarchyPanel(const Ref<Scene>& scene, bool show, const std::string& title) noexcept
        : m_Scene(scene)
        , m_IsShown(show)
        , m_Title(title)
    { }

    void SceneHierarchyPanel::ShowContent() noexcept
    {
        if (m_IsShown)
        {
            ImGui::Begin(m_Title.c_str(), &m_IsShown);

            ShowCreateButton();

            auto entities = m_Scene->GetEntities<TagComponent>();
            for (int i = 0; i < entities.size(); ++i)
            {
                ImGui::PushID(i);

                auto& tagComp = entities[i].GetComponent<TagComponent>();
                if (ImGui::TreeNode("%s", tagComp.Tag.c_str()))
                {
                    tagComp.OnUserInterfaceDraw();

                    ShowComponent<TransformComponent>(entities[i], "Transform");
                    ShowComponent<Camera2DComponent>(entities[i], "Camera 2D");
                    ShowComponent<RenderComponent>(entities[i], "Render");

                    ImGui::TreePop();
                }

                ImGui::PopID();
            }

            ImGui::End();
        }
    }

    void SceneHierarchyPanel::ShowCreateButton() noexcept
    {
        if (ImGui::Button("Create square", { ImGui::GetContentRegionAvail().x, 25 }))
        {
            auto tmp = m_Scene->CreateEntity();
            tmp.AddComponent<RenderComponent>();
        }
    }
}
