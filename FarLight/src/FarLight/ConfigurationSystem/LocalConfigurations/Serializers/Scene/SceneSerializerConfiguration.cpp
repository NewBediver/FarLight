#include "flpch.h"

#include "FarLight/ConfigurationSystem/LocalConfigurations/Serializers/Scene/SceneSerializerConfiguration.h"

namespace FarLight
{
    bool SceneSerializerConfiguration::IsSceneExists(const boost::uuids::uuid& id) const noexcept
    {
        for (auto& node = m_PropertyTree.get_child(m_RootName).begin(); node != m_PropertyTree.get_child(m_RootName).end(); ++node)
        {
            if (node->first == m_SceneNodeName && node->second.get<std::string>("<xmlattr>.id") == boost::lexical_cast<std::string>(id))
                return true;
        }
        return false;
    }

    Ref<Scene> SceneSerializerConfiguration::GetScene(const boost::uuids::uuid& id) const noexcept
    {
        if (!IsSceneExists(id))
        {
            FL_CORE_ERROR("Scene with id = \"{0}\" doesn't exists!", boost::lexical_cast<std::string>(id));
            return nullptr;
        }

        for (auto& node = m_PropertyTree.get_child(m_RootName).begin(); node != m_PropertyTree.get_child(m_RootName).end(); ++node)
        {
            if (node->first == m_SceneNodeName && node->second.get<std::string>("<xmlattr>.id") == boost::lexical_cast<std::string>(id))
            {
                // TODO: return scene
                return nullptr;
            }
        }

        return nullptr;
    }

    void SceneSerializerConfiguration::SetScene(Ref<Scene> scene) noexcept
    {
        EraseScene(scene->GetId<boost::uuids::uuid>());

        std::string id = scene->GetId<std::string>();
        boost::property_tree::ptree tmpTree;
        tmpTree.put<std::string>(m_SceneNodeName + ".<xmlattr>.id", id);
        // TODO: create scene tree

        m_PropertyTree.add_child(m_RootName, tmpTree);
    }

    void SceneSerializerConfiguration::EraseScene(const boost::uuids::uuid& id) noexcept
    {
        if (!IsSceneExists(id))
        {
            FL_CORE_ERROR("Scene with id = \"{0}\" doesn't exists!", boost::lexical_cast<std::string>(id));
            return;
        }

        for (auto& node = m_PropertyTree.get_child(m_RootName).begin(); node != m_PropertyTree.get_child(m_RootName).end(); ++node)
        {
            if (node->first == m_SceneNodeName && node->second.get<std::string>("<xmlattr>.id") == boost::lexical_cast<std::string>(id))
            {
                node = m_PropertyTree.erase(node);
                break;
            }
        }
    }
}
