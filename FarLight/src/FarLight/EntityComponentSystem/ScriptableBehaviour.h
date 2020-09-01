#pragma once

#include "FarLight/Core/Core.h"

#include "FarLight/EntityComponentSystem/Entity.h"

namespace FarLight
{
    class ScriptableBehaviour
    {
    public:
        virtual ~ScriptableBehaviour() = default;

        virtual void OnCreate() noexcept = 0;
        virtual void OnDestroy() noexcept = 0;

        virtual void OnUpdate(const Timestep& ts) noexcept = 0;

    protected:
        template<typename T>
        T& GetComponent() noexcept
        {
            FL_CORE_ASSERT(HasAllComponents<T>(), "Current entity does not containt this component!");

            return m_Entity.GetComponent<T>();
        }

        template<typename... Components>
        bool HasAllComponents() noexcept
        {
            return m_Entity.HasAllComponents<Components...>();
        }

        template<typename... Components>
        bool HasAnyComponents() noexcept
        {
            return m_Entity.HasAllComponents<Components...>();
        }

    private:
        Entity m_Entity = Entity(nullptr, entt::null);
        friend class Scene;
    };
}
