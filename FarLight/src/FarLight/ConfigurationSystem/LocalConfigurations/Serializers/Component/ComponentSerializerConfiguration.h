#pragma once

#include <string>

#include "FarLight/ConfigurationSystem/Configuration.h"

#include "FarLight/EntityComponentSystem/Components/Tag/TagComponent.h"
#include "FarLight/EntityComponentSystem/Components/Transform/TransformComponent.h"
#include "FarLight/EntityComponentSystem/Components/Render/RenderComponent.h"
#include "FarLight/EntityComponentSystem/Components/Camera/CameraComponent.h"

namespace FarLight
{
    class ComponentSerializerConfiguration
        : public Configuration
    {
    public:
        explicit ComponentSerializerConfiguration() noexcept
            : Configuration("Components")
            , m_ComponentNodeName("Component")
        { }

        bool IsComponentExists(const boost::uuids::uuid& id) const noexcept;
        void EraseComponent(const boost::uuids::uuid& id) noexcept;

        //////////////////// Deserialize Section
        template<typename T>
        Ref<T> LoadComponent(const boost::uuids::uuid& id) const noexcept { return nullptr; }

        template<>
        Ref<TagComponent> LoadComponent(const boost::uuids::uuid& id) const noexcept
        {
            if (!IsComponentExists(id))
            {
                FL_CORE_ERROR("Component with id = \"{0}\" doesn't exists!", boost::lexical_cast<std::string>(id));
                return nullptr;
            }

            return CreateTagComponent(id);
        }

        template<>
        Ref<TransformComponent> LoadComponent(const boost::uuids::uuid& id) const noexcept
        {
            if (!IsComponentExists(id))
            {
                FL_CORE_ERROR("Component with id = \"{0}\" doesn't exists!", boost::lexical_cast<std::string>(id));
                return nullptr;
            }

            return CreateTransformComponent(id);
        }

        template<>
        Ref<RenderComponent> LoadComponent(const boost::uuids::uuid& id) const noexcept
        {
            if (!IsComponentExists(id))
            {
                FL_CORE_ERROR("Component with id = \"{0}\" doesn't exists!", boost::lexical_cast<std::string>(id));
                return nullptr;
            }

            return CreateRenderComponent(id);
        }

        template<>
        Ref<CameraComponent> LoadComponent(const boost::uuids::uuid& id) const noexcept
        {
            if (!IsComponentExists(id))
            {
                FL_CORE_ERROR("Component with id = \"{0}\" doesn't exists!", boost::lexical_cast<std::string>(id));
                return nullptr;
            }

            return CreateCameraComponent(id);
        }
        ////////////////////////////////////////////////////


        //////////////////// Serialize Section
        template<typename T>
        void SaveComponent(Ref<T> component) noexcept { return nullptr; }

        template<>
        void SaveComponent<TagComponent>(Ref<TagComponent> component) noexcept
        {
            if (IsComponentExists(component->GetId<boost::uuids::uuid>()))
            {
                FL_CORE_WARN("Try to save component with the existent id = \"{0}\"!", boost::lexical_cast<std::string>(component->GetId<boost::uuids::uuid>()));
                EraseComponent(component->GetId<boost::uuids::uuid>());
            }
            
            m_PropertyTree.add_child(m_ComponentNodeName, CreateTagComponentTree(component).get_child(m_ComponentNodeName));
        }

        template<>
        void SaveComponent<TransformComponent>(Ref<TransformComponent> component) noexcept
        {
            if (IsComponentExists(component->GetId<boost::uuids::uuid>()))
            {
                FL_CORE_WARN("Try to save component with the existent id = \"{0}\"!", boost::lexical_cast<std::string>(component->GetId<boost::uuids::uuid>()));
                EraseComponent(component->GetId<boost::uuids::uuid>());
            }

            m_PropertyTree.add_child(m_ComponentNodeName, CreateTransformComponentTree(component).get_child(m_ComponentNodeName));
        }

        template<>
        void SaveComponent<RenderComponent>(Ref<RenderComponent> component) noexcept
        {
            if (IsComponentExists(component->GetId<boost::uuids::uuid>()))
            {
                FL_CORE_WARN("Try to save component with the existent id = \"{0}\"!", boost::lexical_cast<std::string>(component->GetId<boost::uuids::uuid>()));
                EraseComponent(component->GetId<boost::uuids::uuid>());
            }

            m_PropertyTree.add_child(m_ComponentNodeName, CreateRenderComponentTree(component).get_child(m_ComponentNodeName));
        }

        template<>
        void SaveComponent<CameraComponent>(Ref<CameraComponent> component) noexcept
        {
            if (IsComponentExists(component->GetId<boost::uuids::uuid>()))
            {
                FL_CORE_WARN("Try to save component with the existent id = \"{0}\"!", boost::lexical_cast<std::string>(component->GetId<boost::uuids::uuid>()));
                EraseComponent(component->GetId<boost::uuids::uuid>());
            }

            m_PropertyTree.add_child(m_ComponentNodeName, CreateCameraComponentTree(component).get_child(m_ComponentNodeName));
        }
        ////////////////////////////////////////////////////

    private:
        boost::property_tree::ptree CreateTagComponentTree(Ref<TagComponent> component) const noexcept;
        boost::property_tree::ptree CreateTransformComponentTree(Ref<TransformComponent> component) const noexcept;
        boost::property_tree::ptree CreateRenderComponentTree(Ref<RenderComponent> component) const noexcept;
        boost::property_tree::ptree CreateCameraComponentTree(Ref<CameraComponent> component) const noexcept;

        Ref<TagComponent> CreateTagComponent(const boost::uuids::uuid& id) const noexcept;
        Ref<TransformComponent> CreateTransformComponent(const boost::uuids::uuid& id) const noexcept;
        Ref<RenderComponent> CreateRenderComponent(const boost::uuids::uuid& id) const noexcept;
        Ref<CameraComponent> CreateCameraComponent(const boost::uuids::uuid& id) const noexcept;

        std::string m_ComponentNodeName;
    };
}
