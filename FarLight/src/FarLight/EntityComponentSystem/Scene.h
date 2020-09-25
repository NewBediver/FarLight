#pragma once

#include "FarLight/Core/Core.h"

#include "FarLight/BasicFunctionality/Timer/Timestep.h"
#include "FarLight/BasicFunctionality/Camera/OrthographicCameraController.h"

#include <entt/entt.hpp>

namespace FarLight
{
    class Entity;

    class Scene final
    {
    public:
        static Ref<Scene> Create() noexcept;

        explicit Scene() noexcept
            : m_EditorCameraController(1280, 720)
            , m_IsRenderViewportHovered(true)
            , m_IsRenderViewportFocused(true)
        { }

        void OnUpdate(const Timestep& ts) noexcept;
        void OnViewportResize(unsigned width, unsigned height) noexcept;
        void OnEvent(Event& e) noexcept;

        Entity CreateEntity(const std::string& name = std::string()) noexcept;
        void DestroyEntity(const Entity& entity) noexcept;

        void CreateSquare() noexcept;
        void CreateCamera() noexcept;

        template<typename... Components>
        std::vector<Entity> GetEntities() noexcept
        {
            std::vector<Entity> res;
            auto view = m_Registry.view<Components...>();
            for (auto entity : view) {
                res.emplace_back(this, entity);
            }
            return res;
        }

        void SetIsRenderViewportHovered(bool status) { m_IsRenderViewportHovered = status; }
        void SetIsRenderViewportFocused(bool status) { m_IsRenderViewportFocused = status; }

    private:
        entt::registry m_Registry;

        OrthographicCameraController m_EditorCameraController;

        bool m_IsRenderViewportHovered;
        bool m_IsRenderViewportFocused;

        friend class Entity;
    };
}
