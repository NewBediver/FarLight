#include "flpch.h"

#include "FarLight/EditorSystem/EditorPanels/ComponentsPanel/ComponentsPanel.h"

namespace FarLight
{
    ComponentsPanel::ComponentsPanel(const Ref<Entity>& entity, bool show, const std::string& title) noexcept
        : m_Entity(entity)
        , m_IsShown(show)
        , m_Title(title)
    { }

    void ComponentsPanel::ShowContent() noexcept
    {
        if (m_IsShown)
        {
            ImGui::Begin(m_Title.c_str(), &m_IsShown, ImGuiWindowFlags_AlwaysAutoResize);

            ShowComponent<TagComponent>("Name");
            ShowComponent<TransformComponent>("Transform");
            ShowComponent<RenderComponent>("Render");
            ShowComponent<CameraComponent>("Camera");

            ShowAddComponentButton();

            ImGui::End();
        }
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



