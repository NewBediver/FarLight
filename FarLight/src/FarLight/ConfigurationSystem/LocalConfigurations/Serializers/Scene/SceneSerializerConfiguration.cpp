#include "flpch.h"

#include "FarLight/ConfigurationSystem/LocalConfigurations/Serializers/Scene/SceneSerializerConfiguration.h"

#include "FarLight/ConfigurationSystem/ConfigurationManager.h"

namespace FarLight
{
    bool SceneSerializerConfiguration::IsSceneExists(const EngineID& id) const noexcept
    {
        for (auto& node = m_PropertyTree.begin(); node != m_PropertyTree.end(); ++node)
        {
            if (node->first == m_SceneNodeName && node->second.get<std::string>("<xmlattr>.id") == id.ToString())
            {
                return true;
            }
        }
        return false;
    }

    void SceneSerializerConfiguration::EraseScene(const EngineID& id) noexcept
    {
        if (!IsSceneExists(id)) return;

        for (auto& node = m_PropertyTree.begin(); node != m_PropertyTree.end(); ++node)
        {
            if (node->first == m_SceneNodeName && node->second.get<std::string>("<xmlattr>.id") == id.ToString())
            {
                node = m_PropertyTree.erase(node);
                break;
            }
        }
    }

    Ref<Scene> SceneSerializerConfiguration::LoadScene(const EngineID& id) const noexcept
    {
        if (!IsSceneExists(id))
        {
            FL_CORE_ERROR("Scene with id = \"{0}\" doesn't exists!", id.ToString());
            return nullptr;
        }

        Ref<Scene> scene = CreateRef<Scene>(id);
        for (auto& node = m_PropertyTree.begin(); node != m_PropertyTree.end(); ++node)
        {
            if (node->first == m_SceneNodeName && node->second.get<std::string>("<xmlattr>.id") == id.ToString())
            {
                std::stringstream ss;
                ss << node->second.get<std::string>("Entities");
                std::string str;
                while (ss >> str)
                {
                    ConfigurationManager::GetInstance().GetEntitySerializerConfiguration()->LoadEntity(EngineID(std::move(str)), scene);
                }
                break;
            }
        }
        return scene;
    }

    void SceneSerializerConfiguration::SaveScene(Ref<Scene> scene) noexcept
    {
        if (IsSceneExists(scene->GetId()))
        {
            FL_CORE_WARN("Try to save scene with the existent id = \"{0}\"!", scene->GetId().ToString());
            EraseScene(scene->GetId());
        }

        boost::property_tree::ptree tmpTree;
        tmpTree.put<std::string>(m_SceneNodeName + ".<xmlattr>.id", scene->GetId().ToString());

        auto mp = scene->GetEntityMap();
        std::string str;
        for (const auto& p : mp)
        {
            ConfigurationManager::GetInstance().GetEntitySerializerConfiguration()->SaveEntity(CreateRef<Entity>(p.first, scene.get(), p.second));
            str += p.first.ToString() + " ";
        }
        str.pop_back();
        ConfigurationManager::GetInstance().GetEntitySerializerConfiguration()->Save();
        tmpTree.put<std::string>(m_SceneNodeName + ".Entities", str);

        m_PropertyTree.add_child(m_SceneNodeName, tmpTree.get_child(m_SceneNodeName));
    }

    std::vector<Ref<Scene>> SceneSerializerConfiguration::LoadAllScenes() const noexcept
    {
        std::vector<Ref<Scene>> res;

        for (auto& node = m_PropertyTree.begin(); node != m_PropertyTree.end(); ++node)
        {
            EngineID id(node->second.get<std::string>("<xmlattr>.id"));
            Ref<Scene> scene = CreateRef<Scene>(id);

            std::stringstream entities;
            entities << node->second.get<std::string>("Entities");
            std::string entityId;
            while (entities >> entityId)
            {
                ConfigurationManager::GetInstance().GetEntitySerializerConfiguration()->LoadEntity(EngineID(std::move(entityId)), scene);
            }

            res.push_back(scene);
        }

        return res;
    }
}
