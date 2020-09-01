#pragma once

#include "FarLight.h"

#include "EditorPanels/Interfaces/IPanel.h"

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

        void ShowCreateButton() noexcept;

    private:
        template<typename Comp>
        void ShowComponent(const Entity& entity, const std::string& title = "Component") noexcept
        {
            if (entity.HasAllComponents<Comp>())
            {
                if (ImGui::CollapsingHeader(title.c_str()))
                    entity.GetComponent<Comp>().OnUserInterfaceDraw();
            }
        }

        Ref<Scene> m_Scene;
        mutable bool m_IsShown;

        std::string m_Title;
    };
}
