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
        for (auto& node = m_PropertyTree.get_child(m_RootName).begin(); node != m_PropertyTree.get_child(m_RootName).end(); ++node)
        {
            if (node->first == m_EntityNodeName && node->second.get<std::string>("<xmlattr>.id") == boost::lexical_cast<std::string>(id))
                return true;
        }
        return false;
    }

    Ref<Entity> EntitySerializerConfiguration::GetEntity(const boost::uuids::uuid& id) const noexcept
    {
        if (!IsEntityExists(id))
        {
            FL_CORE_ERROR("Entity with id = \"{0}\" doesn't exists!", boost::lexical_cast<std::string>(id));
            return nullptr;
        }

        Ref<Entity> entity = CreateRef<Entity>(id, nullptr, (entt::entity)0);
        for (auto& node = m_PropertyTree.get_child(m_RootName).begin(); node != m_PropertyTree.get_child(m_RootName).end(); ++node)
        {
            if (node->first == m_EntityNodeName && node->second.get<std::string>("<xmlattr>.id") == boost::lexical_cast<std::string>(id))
            {
                if (!node->second.get_optional<bool>("Scene").is_initialized())
                {
                    FL_CORE_ERROR("Entity with id = \"{0}\" doesn't have a scene!", boost::lexical_cast<std::string>(id));
                    return nullptr;
                }
                // TODO: Add scene pointer

                if (node->second.get_optional<bool>("TagComponent").is_initialized() && ConfigurationManager::GetInstance().GetComponentSerializerConfiguration()->IsComponentExists(boost::lexical_cast<boost::uuids::uuid>(node->second.get<std::string>("TagComponent"))))
                {
                    auto tag = ConfigurationManager::GetInstance().GetComponentSerializerConfiguration()->GetComponent<TagComponent>(boost::lexical_cast<boost::uuids::uuid>(node->second.get<std::string>("TagComponent")));
                    entity->AddComponent<TagComponent>(tag->GetId<boost::uuids::uuid>(), tag->GetTag());
                }
                if (node->second.get_optional<bool>("TransformComponent").is_initialized() && ConfigurationManager::GetInstance().GetComponentSerializerConfiguration()->IsComponentExists(boost::lexical_cast<boost::uuids::uuid>(node->second.get<std::string>("TransformComponent"))))
                {
                    auto transform = ConfigurationManager::GetInstance().GetComponentSerializerConfiguration()->GetComponent<TransformComponent>(boost::lexical_cast<boost::uuids::uuid>(node->second.get<std::string>("TransformComponent")));
                    entity->AddComponent<TransformComponent>(transform->GetId<boost::uuids::uuid>(), transform->GetPosition(), transform->GetSize(), transform->GetRotation());
                }
                if (node->second.get_optional<bool>("RenderComponent").is_initialized() && ConfigurationManager::GetInstance().GetComponentSerializerConfiguration()->IsComponentExists(boost::lexical_cast<boost::uuids::uuid>(node->second.get<std::string>("RenderComponent"))))
                {
                    auto render = ConfigurationManager::GetInstance().GetComponentSerializerConfiguration()->GetComponent<RenderComponent>(boost::lexical_cast<boost::uuids::uuid>(node->second.get<std::string>("RenderComponent")));
                    entity->AddComponent<TransformComponent>(render->GetId<boost::uuids::uuid>(), render->GetColor());
                }
                if (node->second.get_optional<bool>("CameraComponent").is_initialized() && ConfigurationManager::GetInstance().GetComponentSerializerConfiguration()->IsComponentExists(boost::lexical_cast<boost::uuids::uuid>(node->second.get<std::string>("CameraComponent"))))
                {
                    auto camera = ConfigurationManager::GetInstance().GetComponentSerializerConfiguration()->GetComponent<CameraComponent>(boost::lexical_cast<boost::uuids::uuid>(node->second.get<std::string>("CameraComponent")));
                    auto& comp = entity->AddComponent<CameraComponent>(camera->GetId<boost::uuids::uuid>(), camera->GetCamera()->GetResolutionWidth(), camera->GetCamera()->GetResolutionHeight(), camera->IsPrimary(), camera->IsFixedAspectRatio());
                    comp.m_Camera->SetResolutionWidth(camera->m_Camera->GetResolutionWidth());
                    comp.m_Camera->SetResolutionHeight(camera->m_Camera->GetResolutionHeight());
                    comp.m_Camera->SetZoom(camera->m_Camera->GetZoom());
                    comp.m_Camera->SetLeftBound(camera->m_Camera->GetLeftBound());
                    comp.m_Camera->SetRightBound(camera->m_Camera->GetRightBound());
                    comp.m_Camera->SetTopBound(camera->m_Camera->GetTopBound());
                    comp.m_Camera->SetBottomBound(camera->m_Camera->GetBottomBound());
                    comp.m_Camera->SetNearBound(camera->m_Camera->GetNearBound());
                    comp.m_Camera->SetFarBound(camera->m_Camera->GetFarBound());
                    comp.m_Camera->SetBackgroundColor(camera->m_Camera->GetBackgroundColor());
                }
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
        tmpTree.put<std::string>(m_EntityNodeName + ".Scene", entity->GetScenePtr()->GetId<std::string>());

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
        if (entity->HasAllComponents<CameraComponent>())
        {
            tmpTree.put<std::string>(m_EntityNodeName + ".CameraComponent", entity->GetComponent<CameraComponent>().GetId<std::string>());
            ConfigurationManager::GetInstance().GetComponentSerializerConfiguration()->SetComponent<CameraComponent>(CreateRef<CameraComponent>(entity->GetComponent<CameraComponent>()));
        }

        m_PropertyTree.add_child(m_RootName, tmpTree);
    }

    void EntitySerializerConfiguration::EraseEntity(const boost::uuids::uuid& id) noexcept
    {
        if (!IsEntityExists(id))
        {
            FL_CORE_ERROR("Entity with id = \"{0}\" doesn't exists!", boost::lexical_cast<std::string>(id));
            return;
        }

        for (auto& node = m_PropertyTree.get_child(m_RootName).begin(); node != m_PropertyTree.get_child(m_RootName).end(); ++node)
        {
            if (node->first == m_EntityNodeName && node->second.get<std::string>("<xmlattr>.id") == boost::lexical_cast<std::string>(id))
            {
                node = m_PropertyTree.erase(node);
                break;
            }
        }
    }
}
