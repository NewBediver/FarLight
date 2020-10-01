#pragma once

#include <sstream>

#include "FarLight/ConfigurationSystem/Configuration.h"

#include "FarLight/EntityComponentSystem/Interfaces/Component.h"

#include "FarLight/EntityComponentSystem/Components/Tag/TagComponent.h"
#include "FarLight/EntityComponentSystem/Components/Transform/TransformComponent.h"
#include "FarLight/EntityComponentSystem/Components/Render/RenderComponent.h"
#include "FarLight/EntityComponentSystem/Components/Camera/CameraComponent.h"

#include "FarLight/SerializationSystem/Serialization.h"

#include <boost/property_tree/xml_parser.hpp>
#include <boost/uuid/uuid.hpp>

namespace FarLight
{
    class ComponentSerializerConfiguration
        : public Configuration
    {
    public:
        explicit ComponentSerializerConfiguration() noexcept
            : Configuration("Components")
        { }

        bool IsComponentExists(const boost::uuids::uuid& id) const noexcept;

        template<typename T>
        T GetComponent(const boost::uuids::uuid& id) const noexcept
        {
            FL_CORE_ASSERT(IsComponentExists(id), "Current component should exist!");

            T comp;
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
                else continue;
            }

            return comp;
        }

        template<typename T>
        void SetComponent(T& component) noexcept
        {
            std::stringstream result;
            boost::archive::xml_oarchive oa(result, boost::archive::archive_flags::no_header);
            oa << FL_SERIALIZE_NAMED("Component", component);
            //FL_CORE_TRACE("Serialized component: {0}", result.str());

            if (IsComponentExists(component.GetId<boost::uuids::uuid>()))
            {
                auto root = m_PropertyTree.get_child("Components");
                for (auto node : FindChildren(root, component.GetId<std::string>()))
                {
                    if (node->second.get<std::string>("EngineObject.Id") == component.GetId<std::string>())
                    {
                        root.erase(node);
                        break;
                    }
                    else continue;
                }
                Save();
            }

            boost::property_tree::ptree tmpTree;
            boost::property_tree::read_xml(result, tmpTree, boost::property_tree::xml_parser::trim_whitespace);
            m_PropertyTree.add_child("Components.Component", tmpTree.get_child("Component"));
        }

    private:
        template <typename Tree>
        auto FindChildren(Tree& pt, std::string const& key)
        {
            std::vector<typename Tree::iterator> matches;
            for (auto it = pt.begin(); it != pt.end(); ++it)
                if (it->first == key) matches.push_back(it);
            return matches;
        }
    };
}
