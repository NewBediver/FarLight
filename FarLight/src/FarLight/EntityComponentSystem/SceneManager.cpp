#include "flpch.h"

#include "FarLight/EntityComponentSystem/SceneManager.h"

namespace FarLight
{
    Ref<Scene> SceneManager::CreateScene() noexcept
    {
        Ref<Scene> scene = CreateRef<Scene>();
        while (HasScene(scene->GetId()))
        {
            scene = CreateRef<Scene>();
        }

        m_SceneMap.emplace(scene->GetId(), scene);

        return scene;
    }

    Ref<Scene> SceneManager::CreateScene(EngineID id) noexcept
    {
        Ref<Scene> scene = CreateRef<Scene>(id);
        if (HasScene(id))
        {
            FL_CORE_WARN("Scene manager already contains scene with id = \"{0}\"!", scene->GetId().ToString());
            m_SceneMap.find(scene->GetId())->second = scene;
        }
        else
        {
            m_SceneMap.emplace(id, scene);
        }
        return scene;
    }

    Ref<Scene> SceneManager::GetScene(const EngineID& id) noexcept
    {
        if (m_SceneMap.find(id) != m_SceneMap.end())
        {
            return m_SceneMap[id];
        }

        FL_CORE_WARN("Scene manager doesn't contain scene with id = \"{0}\"!", id.ToString());
        return nullptr;
    }

    void SceneManager::AddScene(Ref<Scene> scene) noexcept
    {
        if (m_SceneMap.find(scene->GetId()) != m_SceneMap.end())
        {
            FL_CORE_WARN("Scene manager already contains scene with id = \"{0}\"!", scene->GetId().ToString());
            m_SceneMap.find(scene->GetId())->second = scene;
        }
        else
        {
            m_SceneMap.emplace(scene->GetId().ToString(), scene);
        }
    }

    bool SceneManager::HasScene(const EngineID& id) const noexcept
    {
        return m_SceneMap.find(id) != m_SceneMap.end();
    }

    void SceneManager::EraseScene(const EngineID& id) noexcept
    {
        m_SceneMap.erase(id);
    }
}
