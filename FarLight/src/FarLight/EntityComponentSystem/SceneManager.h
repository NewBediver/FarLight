#pragma once

#include <unordered_map>

#include "FarLight/Core/Core.h"

#include "FarLight/Abstraction/Singleton/Singleton.h"

#include "FarLight/ConfigurationSystem/ConfigurationManager.h"

#include "FarLight/EntityComponentSystem/Scene.h"

#include <boost/functional/hash/hash.hpp>

namespace FarLight
{
    class SceneManager
        : public Singleton<SceneManager>
    {
    public:
        Ref<Scene> CreateScene() noexcept;
        Ref<Scene> CreateScene(const boost::uuids::uuid& id) noexcept;
        Ref<Scene> GetScene(const boost::uuids::uuid& id) noexcept;
        void AddScene(Ref<Scene> scene) noexcept;
        bool HasScene(const boost::uuids::uuid& id) const noexcept;
        void EraseScene(const boost::uuids::uuid& id) noexcept;

        const std::unordered_map<boost::uuids::uuid, Ref<Scene>, boost::hash<boost::uuids::uuid>>& GetSceneMap() const noexcept { return m_SceneMap; }

    private:
        std::unordered_map<boost::uuids::uuid, Ref<Scene>, boost::hash<boost::uuids::uuid>> m_SceneMap;
    };
}
