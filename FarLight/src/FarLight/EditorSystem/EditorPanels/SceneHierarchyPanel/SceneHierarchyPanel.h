#pragma once

#include <FarLight.h>

#include "FarLight/EditorSystem/EditorPanels/Abstraction/Panel.h"

#include "FarLight/EditorSystem/EditorPanels/ComponentsPanel/ComponentsPanel.h"

namespace FarLight
{
    class SceneHierarchyPanel final
        : public Panel
    {
    public:
        explicit SceneHierarchyPanel(Ref<Scene> scene, std::string&& title = "Scene hierarchy") noexcept
            : Panel(std::move(title))
            , m_Scene(scene)
            , m_ComponentsPanel(nullptr)
            , m_SelectedEntity(-1)
        { }

        virtual void ShowContent() noexcept override;

    private:
        bool ShowDeleteEntityButton(Entity ent) noexcept;
        bool ShowAddEntityButton() noexcept;

        Ref<Scene> m_Scene;
        Scope<ComponentsPanel> m_ComponentsPanel;
        int m_SelectedEntity;
    };
}
