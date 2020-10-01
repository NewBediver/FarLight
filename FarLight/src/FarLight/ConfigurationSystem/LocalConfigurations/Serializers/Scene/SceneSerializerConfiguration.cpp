#include "flpch.h"

#include "FarLight/ConfigurationSystem/LocalConfigurations/Serializers/Scene/SceneSerializerConfiguration.h"

#include "FarLight/EntityComponentSystem/Components/Tag/TagComponent.h"
#include "FarLight/EntityComponentSystem/Components/Transform/TransformComponent.h"
#include "FarLight/EntityComponentSystem/Components/Render/RenderComponent.h"
#include "FarLight/EntityComponentSystem/Components/Camera/CameraComponent.h"

#include <boost/property_tree/xml_parser.hpp>
#include <boost/lexical_cast.hpp>

namespace FarLight
{
    bool SceneSerializerConfiguration::IsSceneExists(const boost::uuids::uuid& id) const noexcept
    {
        return IsExists<std::string>("Scenes.Scene.EngineObject.Id", boost::lexical_cast<std::string>(id));
    }

    Scene SceneSerializerConfiguration::GetScene(const boost::uuids::uuid& id) const noexcept
    {
        FL_CORE_ASSERT(IsSceneExists(id), "Current scene should exist!");

        Scene scene;
        for (const auto& node : m_PropertyTree.get_child("Scenes"))
        {
            if (node.second.get<std::string>("EngineObject.Id") == boost::lexical_cast<std::string>(id))
            {
                scene.m_Id = id;
                std::stringstream ss;
                ss << GetValue<std::string>("Entities");

                break;
            }
        }

        return scene;
    }

    void SceneSerializerConfiguration::SetScene(const Scene& scene) noexcept
    {
        if (IsSceneExists(scene.GetId<boost::uuids::uuid>()))
        {
            auto root = m_PropertyTree.get_child("Scenes");
            for (auto node : FindChildren(root, scene.GetId<std::string>()))
            {
                if (node->second.get<std::string>("EngineObject.Id") == scene.GetId<std::string>())
                {
                    root.erase(node);
                    break;
                }
            }
            Save();
        }

        boost::property_tree::ptree tmpTree;
        tmpTree.put<std::string>("EngineObject.Id", scene.GetId<std::string>());
        /*std::stringstream ss;
        scene.m_Registry.view<TagComponent>().each([&](auto entity, TagComponent& comp)
            {
                ss << entity;
            });
        tmpTree.put<std::string>("Entities", ss.str());*/

        m_PropertyTree.add_child("Scenes.Scene", tmpTree);
    }

    std::vector<boost::uuids::uuid> SceneSerializerConfiguration::GetMultipleData(boost::property_tree::ptree& pt, const std::string& name)
    {
        std::vector<boost::uuids::uuid> res;
        std::stringstream ss;
        ss << pt.get<std::string>(name);
        boost::uuids::uuid id;
        while (ss >> id)
            res.push_back(boost::lexical_cast<boost::uuids::uuid>(id));
        return res;
    }
}
