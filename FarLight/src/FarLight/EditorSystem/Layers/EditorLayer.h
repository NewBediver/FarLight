#pragma once

#include <FarLight.h>

#include "FarLight/EditorSystem/EditorPanels/SceneHierarchyPanel/SceneHierarchyPanel.h"
#include "FarLight/EditorSystem/EditorPanels/SettingsPanel/SettingsPanel.h"

#include <glm/glm.hpp>

namespace FarLight
{
    class EditorLayer
        : public Layer
    {
    public:
        explicit EditorLayer() noexcept;

        virtual void OnAttach() noexcept override;
        virtual void OnDetach() noexcept override;
        virtual void OnUpdate(const Timestep& timestep) noexcept override;
        virtual void OnUserInterfaceRender() noexcept override;
        virtual void OnEvent(Event& event) noexcept override;

    private:
        void EnableDocking() noexcept;
        void UpdateMenuBar() noexcept;
        void UpdateRenderViewport() noexcept;

        void GetBatchingStatistic() noexcept;

        struct Options
        {
            bool ShowBatchStatistics = false;
            bool ShowECS = false;
        } m_Options;

        struct Panels
        {
            Scope<SceneHierarchyPanel> Hierarchy = nullptr;
            Scope<SettingsPanel> Settings = nullptr;
        } m_Panels;

        struct RenderViewportOptions
        {
            bool IsFocused = true, IsHovered = true;
            unsigned Height = 0, Width = 0;
        } m_RenderViewportOptions;

        Ref<Scene> m_Scene;

        Ref<Framebuffer> m_Framebuffer;

        Ref<AtlasMap> m_AtlasMap;
        std::unordered_map<char, glm::vec2> m_AtlasCoords;
    };
}
