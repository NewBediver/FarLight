#include "flpch.h"

#include "FarLight/ConfigurationSystem/LocalConfigurations/Serializers/Entity/EntitySerializerConfiguration.h"

#include "FarLight/ConfigurationSystem/ConfigurationManager.h"

#include "FarLight/EntityComponentSystem/Components/Tag/TagComponent.h"
#include "FarLight/EntityComponentSystem/Components/Transform/TransformComponent.h"
#include "FarLight/EntityComponentSystem/Components/Render/RenderComponent.h"
#include "FarLight/EntityComponentSystem/Components/Camera/CameraComponent.h"

namespace FarLight
{
    bool EntitySerializerConfiguration::IsEntityExists(const EngineID& id) const noexcept
    {
        for (auto& node = m_PropertyTree.begin(); node != m_PropertyTree.end(); ++node)
        {
            if (node->first == m_EntityNodeName && node->second.get<std::string>("<xmlattr>.id") == id.ToString())
            {
                return true;
            }
        }
        return false;
    }

    void EntitySerializerConfiguration::EraseEntity(const EngineID& id) noexcept
    {
        if (!IsEntityExists(id)) return;

        for (auto& node = m_PropertyTree.begin(); node != m_PropertyTree.end(); ++node)
        {
            if (node->first == m_EntityNodeName && node->second.get<std::string>("<xmlattr>.id") == id.ToString())
            {
                node = m_PropertyTree.erase(node);
                break;
            }
        }
    }

    Ref<Entity> EntitySerializerConfiguration::LoadEntity(const EngineID& id, Ref<Scene> scene) const noexcept
    {
        if (!IsEntityExists(id))
        {
            FL_CORE_ERROR("Entity with id = \"{0}\" doesn't exists!", id.ToString());
            return nullptr;
        }

        Ref<Entity> entity = scene->CreateEntity(id);
        for (auto& node = m_PropertyTree.begin(); node != m_PropertyTree.end(); ++node)
        {
            if (node->first == m_EntityNodeName && node->second.get<std::string>("<xmlattr>.id") == id.ToString())
            {
                LoadComponentIfExist<TagComponent>(node->second, "TagComponent", entity);
                LoadComponentIfExist<TransformComponent>(node->second, "TransformComponent", entity);
                LoadComponentIfExist<RenderComponent>(node->second, "RenderComponent", entity);
                LoadComponentIfExist<CameraComponent>(node->second, "CameraComponent", entity);
                break;
            }
        }
        return entity;
    }

    void EntitySerializerConfiguration::SaveEntity(Ref<Entity> entity) noexcept
    {
        if (IsEntityExists(entity->GetId()))
        {
            FL_CORE_WARN("Try to save entity with the existent id = \"{0}\"!", entity->GetId().ToString());
            EraseEntity(entity->GetId());
        }

        std::string id = entity->GetId().ToString();
        boost::property_tree::ptree tmpTree;
        tmpTree.put<std::string>(m_EntityNodeName + ".<xmlattr>.id", id);

        SaveComponentIfExist<TagComponent>(tmpTree, "TagComponent", entity);
        SaveComponentIfExist<TransformComponent>(tmpTree, "TransformComponent", entity);
        SaveComponentIfExist<RenderComponent>(tmpTree, "RenderComponent", entity);
        SaveComponentIfExist<CameraComponent>(tmpTree, "CameraComponent", entity);
        
        ConfigurationManager::GetInstance().GetComponentSerializerConfiguration()->Save();

        m_PropertyTree.add_child(m_EntityNodeName, tmpTree.get_child(m_EntityNodeName));
    }

    template<typename T>
    inline void EntitySerializerConfiguration::LoadComponentIfExist(const boost::property_tree::ptree& tree, const std::string& name, Ref<Entity> entity) const noexcept
    {
        if (tree.find(name) != tree.not_found() && ConfigurationManager::GetInstance().GetComponentSerializerConfiguration()->IsComponentExists(EngineID(tree.get<std::string>(name))))
        {
            Ref<T> component = ConfigurationManager::GetInstance().GetComponentSerializerConfiguration()->LoadComponent<T>(EngineID(tree.get<std::string>(name)));
            if (entity->HasAllComponents<T>())
            {
                entity->ReplaceComponent<T>(*(component.get()));
            }
            else
            {
                entity->AddComponent<T>(*(component.get()));
            }
        }
    }

    template<typename T>
    inline void EntitySerializerConfiguration::SaveComponentIfExist(boost::property_tree::ptree& tree, const std::string& name, Ref<Entity> entity) noexcept
    {
        if (entity->HasAllComponents<T>())
        {
            tree.put<std::string>(m_EntityNodeName + "." + name, entity->GetComponent<T>().GetId().ToString());
            ConfigurationManager::GetInstance().GetComponentSerializerConfiguration()->SaveComponent<T>(CreateRef<T>(entity->GetComponent<T>()));
        }
    }
}
