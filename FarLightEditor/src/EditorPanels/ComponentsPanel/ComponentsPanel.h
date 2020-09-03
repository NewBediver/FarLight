#pragma once

#include <FarLight.h>

#include "EditorPanels/Interfaces/IPanel.h"

#include <imgui.h>

namespace FarLight
{
    class ComponentsPanel final
        : public IPanel
    {
    public:
        explicit ComponentsPanel(const Ref<Entity>& entity, bool show = false, const std::string& title = "Components") noexcept;

        virtual void ShowContent() noexcept override;

        virtual bool IsShown() const noexcept override { return m_IsShown; }
        virtual void SetShown(bool show) noexcept override { m_IsShown = show; }

        virtual const std::string& GetTitle() const noexcept override { return m_Title; }
        virtual void SetTitle(const std::string& title) noexcept override { m_Title = title; }

    private:
        template<typename Comp>
        void ShowComponent(const std::string& title) noexcept
        {
            if (m_Entity->HasAllComponents<Comp>())
            {
                if (ImGui::CollapsingHeader(title.c_str()))
                {
                    m_Entity->GetComponent<Comp>().OnUserInterfaceDraw();
                    if (ImGui::Button(("Remove " + title + " component").c_str()))
                        m_Entity->RemoveComponent<Comp>();
                }
            }
        }

        template<>
        void ShowComponent<TagComponent>(const std::string& title) noexcept
        {
            if (m_Entity->HasAllComponents<TagComponent>())
            {
                if (ImGui::CollapsingHeader(title.c_str()))
                    m_Entity->GetComponent<TagComponent>().OnUserInterfaceDraw();
            }
        }

        template<>
        void ShowComponent<TransformComponent>(const std::string& title) noexcept
        {
            if (m_Entity->HasAllComponents<TransformComponent>())
            {
                if (ImGui::CollapsingHeader(title.c_str()))
                    m_Entity->GetComponent<TransformComponent>().OnUserInterfaceDraw();
            }
        }

        template<typename Comp>
        void AddComponentButton(const std::string& title) noexcept
        {
            if (!m_Entity->HasAllComponents<Comp>())
            {
                if (ImGui::Button(("Add " + title + " component").c_str()))
                    m_Entity->AddComponent<Comp>();
            }
        }

        Ref<Entity> m_Entity;

        bool m_IsShown;
        std::string m_Title;
    };
}
