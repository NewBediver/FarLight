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
        Ref<Scene> CreateScene(EngineID id) noexcept;

        Ref<Scene> GetScene(const EngineID& id) noexcept;

        void AddScene(Ref<Scene> scene) noexcept;

        bool HasScene(const EngineID& id) const noexcept;

        void EraseScene(const EngineID& id) noexcept;

        const std::unordered_map<EngineID, Ref<Scene>>& GetSceneMap() const noexcept { return m_SceneMap; }

    private:
        std::unordered_map<EngineID, Ref<Scene>> m_SceneMap;
    };
}
