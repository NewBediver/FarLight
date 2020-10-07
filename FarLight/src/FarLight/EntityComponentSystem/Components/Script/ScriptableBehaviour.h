#pragma once

#include "FarLight/Core/Core.h"

#include "FarLight/EntityComponentSystem/Entity.h"

namespace FarLight
{
    class ScriptableBehaviour
    {
        friend class Scene;

    public:
        explicit ScriptableBehaviour(Ref<Entity> entity) noexcept
            : m_Entity(entity)
        { }

        virtual ~ScriptableBehaviour() noexcept = default;

        virtual void OnCreate() noexcept { };
        virtual void OnDestroy() noexcept { };

        virtual void OnUpdate(const Timestep& ts) noexcept { };

    protected:
        template<typename T>
        T& GetComponent() noexcept
        {
            FL_CORE_ASSERT(HasAllComponents<T>(), "Current entity does not containt this component!");

            return m_Entity->GetComponent<T>();
        }

        template<typename... Components>
        bool HasAllComponents() noexcept
        {
            return m_Entity->HasAllComponents<Components...>();
        }

        template<typename... Components>
        bool HasAnyComponents() noexcept
        {
            return m_Entity->HasAllComponents<Components...>();
        }

    private:
        Ref<Entity> m_Entity;
    };
}
