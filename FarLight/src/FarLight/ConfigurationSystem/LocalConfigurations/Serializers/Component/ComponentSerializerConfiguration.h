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

        template<typename T>
        Ref<T> GetComponent(const boost::uuids::uuid& id) const noexcept
        {
            return nullptr;
        }

        template<>
        Ref<TagComponent> GetComponent(const boost::uuids::uuid& id) const noexcept
        {
            if (!IsComponentExists(id))
            {
                FL_CORE_ERROR("Component with id = \"{0}\" doesn't exists!", boost::lexical_cast<std::string>(id));
                return nullptr;
            }

            return CreateTagComponent(id);
        }

        template<>
        Ref<TransformComponent> GetComponent(const boost::uuids::uuid& id) const noexcept
        {
            if (!IsComponentExists(id))
            {
                FL_CORE_ERROR("Component with id = \"{0}\" doesn't exists!", boost::lexical_cast<std::string>(id));
                return nullptr;
            }

            return CreateTransformComponent(id);
        }

        template<>
        Ref<RenderComponent> GetComponent(const boost::uuids::uuid& id) const noexcept
        {
            if (!IsComponentExists(id))
            {
                FL_CORE_ERROR("Component with id = \"{0}\" doesn't exists!", boost::lexical_cast<std::string>(id));
                return nullptr;
            }

            return CreateRenderComponent(id);
        }

        template<>
        Ref<CameraComponent> GetComponent(const boost::uuids::uuid& id) const noexcept
        {
            if (!IsComponentExists(id))
            {
                FL_CORE_ERROR("Component with id = \"{0}\" doesn't exists!", boost::lexical_cast<std::string>(id));
                return nullptr;
            }

            return CreateCameraComponent(id);
        }


        template<typename T>
        void SetComponent(Ref<T> component) noexcept
        { }

        template<>
        void SetComponent<TagComponent>(Ref<TagComponent> component) noexcept
        {
            EraseComponent(component->GetId<boost::uuids::uuid>());
            m_PropertyTree.add_child(m_ComponentNodeName, CreateTagComponentTree(component).get_child(m_ComponentNodeName));
        }

        template<>
        void SetComponent<TransformComponent>(Ref<TransformComponent> component) noexcept
        {
            EraseComponent(component->GetId<boost::uuids::uuid>());
            m_PropertyTree.add_child(m_ComponentNodeName, CreateTransformComponentTree(component).get_child(m_ComponentNodeName));
        }

        template<>
        void SetComponent<RenderComponent>(Ref<RenderComponent> component) noexcept
        {
            EraseComponent(component->GetId<boost::uuids::uuid>());
            m_PropertyTree.add_child(m_ComponentNodeName, CreateRenderComponentTree(component).get_child(m_ComponentNodeName));
        }

        template<>
        void SetComponent<CameraComponent>(Ref<CameraComponent> component) noexcept
        {
            EraseComponent(component->GetId<boost::uuids::uuid>());
            m_PropertyTree.add_child(m_ComponentNodeName, CreateCameraComponentTree(component).get_child(m_ComponentNodeName));
        }

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
