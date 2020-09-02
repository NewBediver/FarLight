#include "EditorPanels/ComponentsPanel/ComponentsPanel.h"

#include <imgui.h>

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

            //AddComponentButton();

            ShowComponent<TagComponent>("Tag");
            ShowComponent<TransformComponent>("Transform");
            ShowComponent<RenderComponent>("Render");
            ShowComponent<CameraComponent>("Camera");

            ImGui::End();
        }
    }
}



