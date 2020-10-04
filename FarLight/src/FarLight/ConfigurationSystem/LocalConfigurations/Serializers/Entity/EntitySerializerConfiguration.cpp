#include "flpch.h"

#include "FarLight/ConfigurationSystem/LocalConfigurations/Serializers/Entity/EntitySerializerConfiguration.h"

#include "FarLight/ConfigurationSystem/ConfigurationManager.h"

#include "FarLight/EntityComponentSystem/Components/Tag/TagComponent.h"
#include "FarLight/EntityComponentSystem/Components/Transform/TransformComponent.h"
#include "FarLight/EntityComponentSystem/Components/Render/RenderComponent.h"
#include "FarLight/EntityComponentSystem/Components/Camera/CameraComponent.h"

namespace FarLight
{
    bool EntitySerializerConfiguration::IsEntityExists(const boost::uuids::uuid& id) const noexcept
    {
        for (auto& node = m_PropertyTree.begin(); node != m_PropertyTree.end(); ++node)
        {
            if (node->first == m_EntityNodeName && node->second.get<std::string>("<xmlattr>.id") == boost::lexical_cast<std::string>(id))
                return true;
        }
        return false;
    }

    Ref<Entity> EntitySerializerConfiguration::GetEntity(const boost::uuids::uuid& id, Ref<Scene> scene) const noexcept
    {
        if (!IsEntityExists(id))
        {
            FL_CORE_ERROR("Entity with id = \"{0}\" doesn't exists!", boost::lexical_cast<std::string>(id));
            return nullptr;
        }

        Ref<Entity> entity = scene->CreateEntity(id);
        for (auto& node = m_PropertyTree.begin(); node != m_PropertyTree.end(); ++node)
        {
            if (node->first == m_EntityNodeName && node->second.get<std::string>("<xmlattr>.id") == boost::lexical_cast<std::string>(id))
            {
                if (node->second.find("TagComponent") != node->second.not_found() && ConfigurationManager::GetInstance().GetComponentSerializerConfiguration()->IsComponentExists(boost::lexical_cast<boost::uuids::uuid>(node->second.get<std::string>("TagComponent"))))
                {
                    auto tag = ConfigurationManager::GetInstance().GetComponentSerializerConfiguration()->GetComponent<TagComponent>(boost::lexical_cast<boost::uuids::uuid>(node->second.get<std::string>("TagComponent")));
                    entity->ReplaceComponent<TagComponent>(*(tag.get()));
                }
                if (node->second.find("TransformComponent") != node->second.not_found() && ConfigurationManager::GetInstance().GetComponentSerializerConfiguration()->IsComponentExists(boost::lexical_cast<boost::uuids::uuid>(node->second.get<std::string>("TransformComponent"))))
                {
                    auto transform = ConfigurationManager::GetInstance().GetComponentSerializerConfiguration()->GetComponent<TransformComponent>(boost::lexical_cast<boost::uuids::uuid>(node->second.get<std::string>("TransformComponent")));
                    entity->ReplaceComponent<TransformComponent>(*(transform.get()));
                }
                if (node->second.find("RenderComponent") != node->second.not_found() && ConfigurationManager::GetInstance().GetComponentSerializerConfiguration()->IsComponentExists(boost::lexical_cast<boost::uuids::uuid>(node->second.get<std::string>("RenderComponent"))))
                {
                    auto render = ConfigurationManager::GetInstance().GetComponentSerializerConfiguration()->GetComponent<RenderComponent>(boost::lexical_cast<boost::uuids::uuid>(node->second.get<std::string>("RenderComponent")));
                    entity->AddComponent<RenderComponent>(*(render.get()));
                }
                /* TODO: Camera should be Ref
                if (node->second.find("CameraComponent") != node->second.not_found() && ConfigurationManager::GetInstance().GetComponentSerializerConfiguration()->IsComponentExists(boost::lexical_cast<boost::uuids::uuid>(node->second.get<std::string>("CameraComponent"))))
                {
                    auto camera = ConfigurationManager::GetInstance().GetComponentSerializerConfiguration()->GetComponent<CameraComponent>(boost::lexical_cast<boost::uuids::uuid>(node->second.get<std::string>("CameraComponent")));
                    entity->AddComponent<CameraComponent>(*(camera.get()));
                }*/
                break;
            }
        }
        return entity;
    }

    void EntitySerializerConfiguration::SetEntity(Ref<Entity> entity) noexcept
    {
        EraseEntity(entity->GetId<boost::uuids::uuid>());

        std::string id = entity->GetId<std::string>();
        boost::property_tree::ptree tmpTree;
        tmpTree.put<std::string>(m_EntityNodeName + ".<xmlattr>.id", id);

        if (entity->HasAllComponents<TagComponent>())
        {
            tmpTree.put<std::string>(m_EntityNodeName + ".TagComponent", entity->GetComponent<TagComponent>().GetId<std::string>());
            ConfigurationManager::GetInstance().GetComponentSerializerConfiguration()->SetComponent<TagComponent>(CreateRef<TagComponent>(entity->GetComponent<TagComponent>()));
        }
        if (entity->HasAllComponents<TransformComponent>())
        {
            tmpTree.put<std::string>(m_EntityNodeName + ".TransformComponent", entity->GetComponent<TransformComponent>().GetId<std::string>());
            ConfigurationManager::GetInstance().GetComponentSerializerConfiguration()->SetComponent<TransformComponent>(CreateRef<TransformComponent>(entity->GetComponent<TransformComponent>()));
        }
        if (entity->HasAllComponents<RenderComponent>())
        {
            tmpTree.put<std::string>(m_EntityNodeName + ".RenderComponent", entity->GetComponent<RenderComponent>().GetId<std::string>());
            ConfigurationManager::GetInstance().GetComponentSerializerConfiguration()->SetComponent<RenderComponent>(CreateRef<RenderComponent>(entity->GetComponent<RenderComponent>()));
        }
        /* TODO: Camera should be Ref
        if (entity->HasAllComponents<CameraComponent>())
        {
            tmpTree.put<std::string>(m_EntityNodeName + ".CameraComponent", entity->GetComponent<CameraComponent>().GetId<std::string>());
            ConfigurationManager::GetInstance().GetComponentSerializerConfiguration()->SetComponent<CameraComponent>(CreateRef<CameraComponent>(entity->GetComponent<CameraComponent>()));
        }*/
        ConfigurationManager::GetInstance().GetComponentSerializerConfiguration()->Save();

        m_PropertyTree.add_child(m_EntityNodeName, tmpTree.get_child(m_EntityNodeName));
    }

    void EntitySerializerConfiguration::EraseEntity(const boost::uuids::uuid& id) noexcept
    {
        if (!IsEntityExists(id))
        {
            FL_CORE_ERROR("Entity with id = \"{0}\" doesn't exists!", boost::lexical_cast<std::string>(id));
            return;
        }

        for (auto& node = m_PropertyTree.begin(); node != m_PropertyTree.end(); ++node)
        {
            if (node->first == m_EntityNodeName && node->second.get<std::string>("<xmlattr>.id") == boost::lexical_cast<std::string>(id))
            {
                node = m_PropertyTree.erase(node);
                break;
            }
        }
    }
}
