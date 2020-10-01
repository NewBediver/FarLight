#pragma once

#include <sstream>
#include <vector>

#include "FarLight/ConfigurationSystem/Configuration.h"

#include "FarLight/EntityComponentSystem/Scene.h"

#include "FarLight/SerializationSystem/Serialization.h"

namespace FarLight
{
    class SceneSerializerConfiguration
        : public Configuration
    {
    public:
        explicit SceneSerializerConfiguration() noexcept
            : Configuration("Scenes")
        { }

        bool IsSceneExists(const boost::uuids::uuid& id) const noexcept;

        Scene GetScene(const boost::uuids::uuid& id) const noexcept;
        void SetScene(const Scene& scene) noexcept;

    private:
        template <typename Tree>
        auto FindChildren(Tree& pt, std::string const& key)
        {
            std::vector<typename Tree::iterator> matches;
            for (auto it = pt.begin(); it != pt.end(); ++it)
                if (it->first == key) matches.push_back(it);
            return matches;
        }

        template<typename T>
        void AddMultipleData(boost::property_tree::ptree& pt, const Scene& scene, const std::string& name) const
        {
            std::stringstream ss;
            scene.m_Registry.view<T>().each([&](auto entity, T& comp)
                {
                    ss << comp.GetId<std::string>();
                });
            pt.put<std::string>(name, ss.str());
        }

        std::vector<boost::uuids::uuid> GetMultipleData(boost::property_tree::ptree& pt, const std::string& name);
    };
}
