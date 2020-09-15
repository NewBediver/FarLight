#pragma once

#include <FarLight.h>

#include "FarLight/EditorSystem/EditorPanels/Interfaces/IPanel.h"

#include "FarLight/EditorSystem/EditorPanels/ComponentsPanel/ComponentsPanel.h"

namespace FarLight
{
    class SceneHierarchyPanel final
        : public IPanel
    {
    public:
        explicit SceneHierarchyPanel(const Ref<Scene>& scene, bool show = false, const std::string& title = "Scene hierarchy") noexcept
            : m_Scene(scene)
            , m_IsShown(show)
            , m_Title(title)
            , m_ComponentsPanel(nullptr)
        { }

        virtual void ShowContent() noexcept override;

        virtual bool IsShown() const noexcept override { return m_IsShown; }
        virtual void SetShown(bool show) noexcept override { m_IsShown = show; }

        virtual const std::string& GetTitle() const noexcept override { return m_Title; }
        virtual void SetTitle(const std::string& title) noexcept override { m_Title = title; }

    private:
        void ShowEntityPopupMenu(Entity ent) noexcept;

        Ref<Scene> m_Scene;
        Ref<ComponentsPanel> m_ComponentsPanel;

        bool m_IsShown;
        std::string m_Title;
    };
}
