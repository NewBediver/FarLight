#pragma once

#include <FarLight.h>

#include "EditorPanels/Interfaces/IPanel.h"

#include <imgui.h>
#include <imgui_internal.h>

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
                bool isShown = true;
                bool isOpened = ImGui::CollapsingHeader(title.c_str(), &isShown, ImGuiTreeNodeFlags_DefaultOpen);

                auto& style = ImGui::GetStyle();
                auto positionMin = ImGui::GetItemRectMin();
                auto positionMax = ImGui::GetItemRectMax();

                if (isOpened)
                {
                    m_Entity->GetComponent<Comp>().OnUserInterfaceDraw();
                    positionMax.y = ImGui::GetItemRectMax().y + style.FramePadding.y;
                }

                ImGui::GetWindowDrawList()->AddRect(positionMin, positionMax, ImGui::ColorConvertFloat4ToU32(style.Colors[ImGuiCol_Border]), style.FrameRounding);

                if (!isShown)
                {
                    m_Entity->RemoveComponent<Comp>();
                }
            }
        }

        template<>
        void ShowComponent<TagComponent>(const std::string& title) noexcept
        {
            if (m_Entity->HasAllComponents<TagComponent>())
            {
                bool isOpened = ImGui::CollapsingHeader(title.c_str(), nullptr, ImGuiTreeNodeFlags_DefaultOpen);

                auto& style = ImGui::GetStyle();
                auto positionMin = ImGui::GetItemRectMin();
                auto positionMax = ImGui::GetItemRectMax();

                if (isOpened)
                {
                    m_Entity->GetComponent<TagComponent>().OnUserInterfaceDraw();
                    positionMax.y = ImGui::GetItemRectMax().y + style.FramePadding.y;
                }

                ImGui::GetWindowDrawList()->AddRect(positionMin, positionMax, ImGui::ColorConvertFloat4ToU32(style.Colors[ImGuiCol_Border]), style.FrameRounding);
            }
        }

        template<>
        void ShowComponent<TransformComponent>(const std::string& title) noexcept
        {
            bool isOpened = ImGui::CollapsingHeader(title.c_str(), nullptr, ImGuiTreeNodeFlags_DefaultOpen);

            auto& style = ImGui::GetStyle();
            auto positionMin = ImGui::GetItemRectMin();
            auto positionMax = ImGui::GetItemRectMax();

            if (isOpened)
            {
                m_Entity->GetComponent<TransformComponent>().OnUserInterfaceDraw();
                positionMax.y = ImGui::GetItemRectMax().y + style.FramePadding.y;
            }

            ImGui::GetWindowDrawList()->AddRect(positionMin, positionMax, ImGui::ColorConvertFloat4ToU32(style.Colors[ImGuiCol_Border]), style.FrameRounding);
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
