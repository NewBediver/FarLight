#include "flpch.h"

#include "FarLight/ConfigurationSystem/LocalConfigurations/Serializers/Entity/EntitySerializerConfiguration.h"

#include "FarLight/EntityComponentSystem/Components/Tag/TagComponent.h"
#include "FarLight/EntityComponentSystem/Components/Transform/TransformComponent.h"
#include "FarLight/EntityComponentSystem/Components/Render/RenderComponent.h"
#include "FarLight/EntityComponentSystem/Components/Camera/CameraComponent.h"

#include <boost/lexical_cast.hpp>

namespace FarLight
{
    bool EntitySerializerConfiguration::IsEntityExists(const boost::uuids::uuid& id) const noexcept
    {
        return IsExists<std::string>("Entities.Entity.EngineObject.Id", boost::lexical_cast<std::string>(id));
    }

    /*Entity EntitySerializerConfiguration::GetEntity(const boost::uuids::uuid& id) const noexcept
    {
        FL_CORE_ASSERT(IsEntityExists(id), "Current entity should exist!");

        Entity entity;
        for (const auto& node : m_PropertyTree.get_child("Components"))
        {
            if (node.second.get<std::string>("EngineObject.Id") == boost::lexical_cast<std::string>(id))
            {
                boost::property_tree::ptree tmp;
                tmp.add_child("Component", node.second);
                std::stringstream result;
                boost::property_tree::xml_writer_settings<std::string> settings(' ', 4);
                boost::property_tree::xml_parser::write_xml_element(result, boost::property_tree::ptree::key_type(), tmp, -1, settings);
                //FL_CORE_TRACE("Deserialized component: {0}", result.str());
                boost::archive::xml_iarchive ia(result, boost::archive::archive_flags::no_header);
                ia >> FL_SERIALIZE_NAMED("Component", comp);
                break;
            }
        }

        return entity;
    }*/

    void EntitySerializerConfiguration::SetEntity(Entity& entity) noexcept
    {
        if (IsEntityExists(entity.GetId<boost::uuids::uuid>()))
        {
            auto root = m_PropertyTree.get_child("Entities");
            for (auto node : FindChildren(root, entity.GetId<std::string>()))
            {
                if (node->second.get<std::string>("Id") == entity.GetId<std::string>())
                {
                    root.erase(node);
                    break;
                }
            }
            Save();
        }

        boost::property_tree::ptree tmp;
        tmp.put<std::string>("Id", entity.GetId<std::string>());
        tmp.put<std::string>("Scene", entity.m_ScenePtr->GetId<std::string>());
        if (entity.HasAllComponents<TagComponent>()) tmp.put<std::string>("TagComponent", entity.GetComponent<TagComponent>().GetId<std::string>());
        if (entity.HasAllComponents<TransformComponent>()) tmp.put<std::string>("TransformComponent", entity.GetComponent<TransformComponent>().GetId<std::string>());
        if (entity.HasAllComponents<RenderComponent>()) tmp.put<std::string>("RenderComponent", entity.GetComponent<RenderComponent>().GetId<std::string>());
        if (entity.HasAllComponents<CameraComponent>()) tmp.put<std::string>("CameraComponent", entity.GetComponent<CameraComponent>().GetId<std::string>());

        m_PropertyTree.add_child("Entities.Entity", tmp);
    }
}
