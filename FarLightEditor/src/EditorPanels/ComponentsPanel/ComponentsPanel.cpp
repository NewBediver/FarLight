#include "EditorPanels/ComponentsPanel/ComponentsPanel.h"

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
            ImGui::Begin(m_Title.c_str(), &m_IsShown);

            ShowComponent<TagComponent>("Name");
            ShowComponent<TransformComponent>("Transform");
            ShowComponent<RenderComponent>("Render");
            ShowComponent<CameraComponent>("Camera");

            AddComponentButton<TagComponent>("Name");
            AddComponentButton<TransformComponent>("Transform");
            AddComponentButton<RenderComponent>("Render");
            AddComponentButton<CameraComponent>("Camera");

            ImGui::End();
        }
    }
}



