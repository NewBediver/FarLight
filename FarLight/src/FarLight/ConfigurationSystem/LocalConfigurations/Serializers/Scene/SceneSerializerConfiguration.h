#pragma once

#include <string>
#include <unordered_map>

#include "FarLight/ConfigurationSystem/Configuration.h"

#include "FarLight/EntityComponentSystem/Scene.h"

namespace FarLight
{
    class SceneSerializerConfiguration
        : public Configuration
    {
    public:
        explicit SceneSerializerConfiguration() noexcept
            : Configuration("Scenes")
            , m_SceneNodeName("Scene")
        { }

        bool IsSceneExists(const boost::uuids::uuid& id) const noexcept;
        Ref<Scene> LoadScene(const boost::uuids::uuid& id) const noexcept;
        void SaveScene(Ref<Scene> scene) noexcept;
        void EraseScene(const boost::uuids::uuid& id) noexcept;

        std::vector<Ref<Scene>> LoadAllScenes() const noexcept;

    private:
        std::string m_SceneNodeName;
    };
}
