#pragma once

#include "FarLight/LayerSystem/Layer.h"

namespace FarLight
{
    class ImGuiLayer final
        : public Layer
    {
    public:
        explicit ImGuiLayer() noexcept
            : Layer("ImGuiLayer")
            , m_IsEventsBlocked(true)
        { }

        virtual void OnAttach() noexcept override;
        virtual void OnDetach() noexcept override;
        virtual void OnUpdate(const Timestep& timestamp) noexcept override { };
        virtual void OnUserInterfaceRender() noexcept override { };
        virtual void OnEvent(Event& event) noexcept override;

        void Begin() const noexcept;
        void End() const noexcept;

        constexpr bool IsEventsBlocked() const noexcept { return m_IsEventsBlocked; }
        constexpr void SetEventsBlock(bool status) noexcept { m_IsEventsBlocked = status; }

    private:
        bool m_IsEventsBlocked;
    };
}
