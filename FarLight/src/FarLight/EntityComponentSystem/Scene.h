#pragma once

#include <unordered_map>

#include "FarLight/Core/Core.h"

#include "FarLight/Abstraction/EngineObject/EngineObject.h"

#include "FarLight/BasicFunctionality/Timer/Timestep.h"
#include "FarLight/BasicFunctionality/Camera/OrthographicCameraController.h"

#include <entt/entt.hpp>
#include <boost/functional/hash/hash.hpp>

namespace FarLight
{
    class Entity;

    class Scene final
        : public EngineObject
    {
        friend class Entity;
        friend class SceneSerializerConfiguration;

    public:
        explicit Scene(boost::uuids::uuid id) noexcept
            : EngineObject(std::move(id))
            , m_EditorCameraController(1280, 720)
            , m_IsRenderViewportHovered(true)
            , m_IsRenderViewportFocused(true)
        { }

        explicit Scene() noexcept
            : m_EditorCameraController(1280, 720)
            , m_IsRenderViewportHovered(true)
            , m_IsRenderViewportFocused(true)
        { }

        Ref<Entity> CreateEntity() noexcept;
        Ref<Entity> CreateEntity(const boost::uuids::uuid& id) noexcept;
        Ref<Entity> GetEntity(const boost::uuids::uuid& id) noexcept;
        void AddEntity(Ref<Entity> entity) noexcept;
        bool HasEntity(const boost::uuids::uuid& id) const noexcept;
        void EraseEntity(const boost::uuids::uuid& id) noexcept;

        const std::unordered_map<boost::uuids::uuid, entt::entity, boost::hash<boost::uuids::uuid>>& GetEntityMap() noexcept;

        void CreateSquare() noexcept;
        void CreateCamera() noexcept;


        void OnUpdate(const Timestep& ts) noexcept;
        void OnViewportResize(unsigned width, unsigned height) noexcept;
        void OnEvent(Event& e) noexcept;

        template<typename... Components>
        std::vector<Entity> GetEntities() noexcept
        {
            std::vector<Entity> res;
            for (const auto& elm : m_IdToEntity)
            {
                Entity entity(elm.first, this, elm.second);
                if (entity.HasAllComponents<Components...>()) res.push_back(entity);
            }
            return res;
        }

        void SetIsRenderViewportHovered(bool status) { m_IsRenderViewportHovered = status; }
        void SetIsRenderViewportFocused(bool status) { m_IsRenderViewportFocused = status; }

    private:
        entt::registry m_Registry;
        std::unordered_map<boost::uuids::uuid, entt::entity, boost::hash<boost::uuids::uuid>> m_IdToEntity;

        OrthographicCameraController m_EditorCameraController;

        bool m_IsRenderViewportHovered;
        bool m_IsRenderViewportFocused;
    };
}
