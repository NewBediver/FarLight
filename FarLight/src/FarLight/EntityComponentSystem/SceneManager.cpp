#include "flpch.h"

#include "FarLight/EntityComponentSystem/SceneManager.h"

namespace FarLight
{
    Ref<Scene> SceneManager::CreateScene() noexcept
    {
        Ref<Scene> scene = CreateRef<Scene>();
        while (HasScene(scene->GetId<boost::uuids::uuid>())) scene = CreateRef<Scene>();

        m_SceneMap.emplace(scene->GetId<boost::uuids::uuid>(), scene);

        return scene;
    }

    Ref<Scene> SceneManager::CreateScene(const boost::uuids::uuid& id) noexcept
    {
        Ref<Scene> scene = CreateRef<Scene>(id);
        if (HasScene(id))
        {
            FL_CORE_WARN("Scene manager already contains scene with id = \"{0}\"!", scene->GetId<std::string>());
            m_SceneMap.find(scene->GetId<boost::uuids::uuid>())->second = scene;
        }
        else
        {
            m_SceneMap.emplace(id, scene);
        }
        return scene;
    }

    Ref<Scene> SceneManager::GetScene(const boost::uuids::uuid& id) noexcept
    {
        if (m_SceneMap.find(id) != m_SceneMap.end())
            return m_SceneMap[id];

        FL_CORE_WARN("Scene manager doesn't contain scene with id = \"{0}\"!", boost::lexical_cast<std::string>(id));
        return nullptr;
    }

    void SceneManager::AddScene(Ref<Scene> scene) noexcept
    {
        if (m_SceneMap.find(scene->GetId<boost::uuids::uuid>()) != m_SceneMap.end())
        {
            FL_CORE_WARN("Scene manager already contains scene with id = \"{0}\"!", scene->GetId<std::string>());
            m_SceneMap.find(scene->GetId<boost::uuids::uuid>())->second = scene;
        }
        else
        {
            m_SceneMap.emplace(scene->GetId<boost::uuids::uuid>(), scene);
        }
    }

    bool SceneManager::HasScene(const boost::uuids::uuid& id) const noexcept
    {
        return m_SceneMap.find(id) != m_SceneMap.end();
    }

    void SceneManager::EraseScene(const boost::uuids::uuid& id) noexcept
    {
        m_SceneMap.erase(id);
    }
}
