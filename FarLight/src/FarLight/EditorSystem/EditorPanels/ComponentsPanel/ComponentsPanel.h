#pragma once

#include <FarLight.h>

#include "FarLight/EditorSystem/EditorPanels/Abstraction/Panel.h"

#include <imgui.h>
#include <imgui_internal.h>

namespace FarLight
{
    class ComponentsPanel final
        : public Panel
    {
    public:
        explicit ComponentsPanel(const Ref<Entity>& entity, bool show = false, const std::string& title = "Components") noexcept;

        virtual void ShowContent() noexcept override;

        virtual bool IsShown() const noexcept override { return m_IsShown; }
        virtual void SetShown(bool show) noexcept override { m_IsShown = show; }

        virtual const std::string& GetTitle() const noexcept override { return m_Title; }
        virtual void SetTitle(const std::string& title) noexcept override { m_Title = title; }

    private:
        void ShowAddComponentButton() noexcept;

        template<typename Comp>
        void ShowComponent(const std::string& title) noexcept
        {
            if (m_Entity->HasAllComponents<Comp>())
            {
                bool isShown = true;
                ImGui::CollapsingHeader(title.c_str(), &isShown, ImGuiTreeNodeFlags_Leaf | ImGuiTreeNodeFlags_Framed | ImGuiTreeNodeFlags_NoTreePushOnOpen);

                auto& style = ImGui::GetStyle();
                auto positionMin = ImGui::GetItemRectMin();
                auto positionMax = ImGui::GetItemRectMax();

                m_Entity->GetComponent<Comp>().OnUserInterfaceDraw();
                positionMax.y = ImGui::GetItemRectMax().y + style.FramePadding.y;

                ImGui::GetWindowDrawList()->AddRect(positionMin, positionMax, ImGui::ColorConvertFloat4ToU32(style.Colors[ImGuiCol_Border]), style.FrameRounding);

                if (!isShown)
                    m_Entity->RemoveComponent<Comp>();
            }
        }

        template<>
        void ShowComponent<TagComponent>(const std::string& title) noexcept
        {
            if (m_Entity->HasAllComponents<TagComponent>())
            {
                ImGui::CollapsingHeader(title.c_str(), nullptr, ImGuiTreeNodeFlags_Leaf | ImGuiTreeNodeFlags_Framed | ImGuiTreeNodeFlags_NoTreePushOnOpen);

                auto& style = ImGui::GetStyle();
                auto positionMin = ImGui::GetItemRectMin();
                auto positionMax = ImGui::GetItemRectMax();

                m_Entity->GetComponent<TagComponent>().OnUserInterfaceDraw();
                positionMax.y = ImGui::GetItemRectMax().y + style.FramePadding.y;

                ImGui::GetWindowDrawList()->AddRect(positionMin, positionMax, ImGui::ColorConvertFloat4ToU32(style.Colors[ImGuiCol_Border]), style.FrameRounding);
            }
        }

        template<>
        void ShowComponent<TransformComponent>(const std::string& title) noexcept
        {
            ImGui::CollapsingHeader(title.c_str(), nullptr, ImGuiTreeNodeFlags_Leaf | ImGuiTreeNodeFlags_Framed | ImGuiTreeNodeFlags_NoTreePushOnOpen);

            auto& style = ImGui::GetStyle();
            auto positionMin = ImGui::GetItemRectMin();
            auto positionMax = ImGui::GetItemRectMax();

            m_Entity->GetComponent<TransformComponent>().OnUserInterfaceDraw();
            positionMax.y = ImGui::GetItemRectMax().y + style.FramePadding.y;

            ImGui::GetWindowDrawList()->AddRect(positionMin, positionMax, ImGui::ColorConvertFloat4ToU32(style.Colors[ImGuiCol_Border]), style.FrameRounding);
        }

        Ref<Entity> m_Entity;

        bool m_IsShown;
        std::string m_Title;
    };
}
