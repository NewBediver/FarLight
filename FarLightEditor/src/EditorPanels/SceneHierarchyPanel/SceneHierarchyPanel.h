#pragma once

#include <FarLight.h>

#include "EditorPanels/Interfaces/IPanel.h"

#include "EditorPanels/ComponentsPanel/ComponentsPanel.h"

namespace FarLight
{
    class SceneHierarchyPanel final
        : public IPanel
    {
    public:
        explicit SceneHierarchyPanel(const Ref<Scene>& scene, bool show = false, const std::string& title = "Scene hierarchy") noexcept;

        virtual void ShowContent() noexcept override;

        virtual bool IsShown() const noexcept override { return m_IsShown; }
        virtual void SetShown(bool show) noexcept override { m_IsShown = show; }

        virtual const std::string& GetTitle() const noexcept override { return m_Title; }
        virtual void SetTitle(const std::string& title) noexcept override { m_Title = title; }

    private:
        Ref<Scene> m_Scene;
        Ref<ComponentsPanel> m_ComponentsPanel;

        bool m_IsShown;
        std::string m_Title;
    };
}
