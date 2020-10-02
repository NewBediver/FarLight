#include "flpch.h"

#include "FarLight/ConfigurationSystem/LocalConfigurations/Serializers/Entity/EntitySerializerConfiguration.h"

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

        for (auto& node = m_PropertyTree.get_child(m_RootName).begin(); node != m_PropertyTree.get_child(m_RootName).end(); ++node)
        {
            if (node->first == m_EntityNodeName && node->second.get<std::string>("<xmlattr>.id") == boost::lexical_cast<std::string>(id))
            {
                // TODO: return entity
                return nullptr;
            }
        }

        return nullptr;
    }

    void EntitySerializerConfiguration::SetEntity(Ref<Entity> entity) noexcept
    {
        EraseEntity(entity->GetId<boost::uuids::uuid>());

        std::string id = entity->GetId<std::string>();
        boost::property_tree::ptree tmpTree;
        tmpTree.put<std::string>(m_EntityNodeName + ".<xmlattr>.id", id);
        // TODO: create entity tree

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
