#include "flpch.h"

#include "FarLight/EntityComponentSystem/SceneManager.h"

namespace FarLight
{
    Ref<Scene> SceneManager::Get(const boost::uuids::uuid& id) const noexcept
    {
        FL_CORE_ASSERT(Has(id), "Scene manager doesn't contain current id!");

        if (m_SceneMap.find(id) != m_SceneMap.end())
            return m_SceneMap.at(id);

        return nullptr;
    }

    void SceneManager::Set(const Ref<Scene> entity) noexcept
    {
        m_SceneMap.emplace(entity->GetId<boost::uuids::uuid>(), entity);
    }

    bool SceneManager::Has(const boost::uuids::uuid& id) const noexcept
    {
        return m_SceneMap.find(id) != m_SceneMap.end();
    }

    void SceneManager::Erase(const boost::uuids::uuid& id) noexcept
    {
        m_SceneMap.erase(id);
    }
}
