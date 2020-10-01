#pragma once

#include "FarLight/Abstraction/EngineObject/EngineObject.h"

#include "FarLight/EntityComponentSystem/Scene.h"

#include "FarLight/Core/Core.h"

#include <entt/entt.hpp>

namespace FarLight
{
    class Entity final
        : public EngineObject
    {
        friend class Scene;
        friend class EntitySerializerConfiguration;

    public:
        explicit Entity(Scene* scene, entt::entity ent) noexcept
            : m_ScenePtr(scene)
            , m_Handle(ent)
        { }

        template<typename T, typename... Args>
        T& AddComponent(Args&&... args) noexcept
        {
            FL_CORE_ASSERT(!HasAllComponents<T>(), "Current component already exists!");

            return m_ScenePtr->m_Registry.emplace<T>(m_Handle, std::forward<Args>(args)...);
        }

        template<typename T>
        void RemoveComponent() noexcept
        {
            FL_CORE_ASSERT(HasAllComponents<T>(), "Current component does not exist!");

            m_ScenePtr->m_Registry.remove<T>(m_Handle);
        }

        template<typename T>
        T& GetComponent() noexcept
        {
            FL_CORE_ASSERT(HasAllComponents<T>(), "Current component does not exist!");

            return m_ScenePtr->m_Registry.get<T>(m_Handle);
        }

        template<typename... Components>
        bool HasAllComponents() const noexcept
        {
            return m_ScenePtr->m_Registry.has<Components...>(m_Handle);
        }

        template<typename... Components>
        bool HasAnyComponent() const noexcept
        {
            return m_ScenePtr->m_Registry.any<Components...>(m_Handle);
        }

        bool IsExists() const noexcept
        {
            return m_ScenePtr != nullptr && m_Handle != entt::null;
        }

    private:
        Scene* m_ScenePtr;
        entt::entity m_Handle;
    };
}
