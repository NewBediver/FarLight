#include "flpch.h"

#include "FarLight/EditorSystem/EditorPanels/ComponentsPanel/ComponentsPanel.h"

namespace FarLight
{
    void ComponentsPanel::ShowContent() noexcept
    {
        ImGui::Begin(GetTitle().c_str());

        ShowComponent<TagComponent>("Name");
        ShowComponent<TransformComponent>("Transform");
        ShowComponent<RenderComponent>("Render");
        ShowComponent<CameraComponent>("Camera");

        ShowAddComponentButton();

        ImGui::End();
    }

    void ComponentsPanel::ShowAddComponentButton() noexcept
    {
        if (ImGui::Button("Add Components")) ImGui::OpenPopup("Component Popup");
        if (ImGui::BeginPopup("Component Popup"))
        {
            if (!m_Entity->HasAllComponents<TagComponent>() && ImGui::Selectable("Tag")) m_Entity->AddComponent<TagComponent>();
            if (!m_Entity->HasAllComponents<TransformComponent>() && ImGui::Selectable("Transform")) m_Entity->AddComponent<TransformComponent>();
            if (!m_Entity->HasAllComponents<RenderComponent>() && ImGui::Selectable("Render")) m_Entity->AddComponent<RenderComponent>();
            if (!m_Entity->HasAllComponents<CameraComponent>() && ImGui::Selectable("Camera")) m_Entity->AddComponent<CameraComponent>();
            ImGui::EndPopup();
        }
    }
}



