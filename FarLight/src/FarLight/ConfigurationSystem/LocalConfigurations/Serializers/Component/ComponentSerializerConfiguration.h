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

        bool IsComponentExists(const EngineID& id) const noexcept;
        void EraseComponent(const EngineID& id) noexcept;

        //////////////////// Deserialize Section
        template<typename T>
        Ref<T> LoadComponent(const EngineID& id) const noexcept { return nullptr; }

        template<>
        Ref<TagComponent> LoadComponent<TagComponent>(const EngineID& id) const noexcept
        {
            if (!IsComponentExists(id))
            {
                FL_CORE_ERROR("Component with id = \"{0}\" doesn't exists!", id.ToString());
                return nullptr;
            }

            return CreateTagComponent(id);
        }

        template<>
        Ref<TransformComponent> LoadComponent<TransformComponent>(const EngineID& id) const noexcept
        {
            if (!IsComponentExists(id))
            {
                FL_CORE_ERROR("Component with id = \"{0}\" doesn't exists!", id.ToString());
                return nullptr;
            }

            return CreateTransformComponent(id);
        }

        template<>
        Ref<RenderComponent> LoadComponent<RenderComponent>(const EngineID& id) const noexcept
        {
            if (!IsComponentExists(id))
            {
                FL_CORE_ERROR("Component with id = \"{0}\" doesn't exists!", id.ToString());
                return nullptr;
            }

            return CreateRenderComponent(id);
        }

        template<>
        Ref<CameraComponent> LoadComponent<CameraComponent>(const EngineID& id) const noexcept
        {
            if (!IsComponentExists(id))
            {
                FL_CORE_ERROR("Component with id = \"{0}\" doesn't exists!", id.ToString());
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
            if (IsComponentExists(component->GetId()))
            {
                FL_CORE_WARN("Try to save component with the existent id = \"{0}\"!", component->GetId().ToString());
                EraseComponent(component->GetId());
            }
            
            m_PropertyTree.add_child(m_ComponentNodeName, CreateTagComponentTree(component).get_child(m_ComponentNodeName));
        }

        template<>
        void SaveComponent<TransformComponent>(Ref<TransformComponent> component) noexcept
        {
            if (IsComponentExists(component->GetId()))
            {
                FL_CORE_WARN("Try to save component with the existent id = \"{0}\"!", component->GetId().ToString());
                EraseComponent(component->GetId());
            }

            m_PropertyTree.add_child(m_ComponentNodeName, CreateTransformComponentTree(component).get_child(m_ComponentNodeName));
        }

        template<>
        void SaveComponent<RenderComponent>(Ref<RenderComponent> component) noexcept
        {
            if (IsComponentExists(component->GetId()))
            {
                FL_CORE_WARN("Try to save component with the existent id = \"{0}\"!", component->GetId().ToString());
                EraseComponent(component->GetId());
            }

            m_PropertyTree.add_child(m_ComponentNodeName, CreateRenderComponentTree(component).get_child(m_ComponentNodeName));
        }

        template<>
        void SaveComponent<CameraComponent>(Ref<CameraComponent> component) noexcept
        {
            if (IsComponentExists(component->GetId()))
            {
                FL_CORE_WARN("Try to save component with the existent id = \"{0}\"!", component->GetId().ToString());
                EraseComponent(component->GetId());
            }

            m_PropertyTree.add_child(m_ComponentNodeName, CreateCameraComponentTree(component).get_child(m_ComponentNodeName));
        }
        ////////////////////////////////////////////////////

    private:
        boost::property_tree::ptree CreateTagComponentTree(Ref<TagComponent> component) const noexcept;
        boost::property_tree::ptree CreateTransformComponentTree(Ref<TransformComponent> component) const noexcept;
        boost::property_tree::ptree CreateRenderComponentTree(Ref<RenderComponent> component) const noexcept;
        boost::property_tree::ptree CreateCameraComponentTree(Ref<CameraComponent> component) const noexcept;

        Ref<TagComponent> CreateTagComponent(const EngineID& id) const noexcept;
        Ref<TransformComponent> CreateTransformComponent(const EngineID& id) const noexcept;
        Ref<RenderComponent> CreateRenderComponent(const EngineID& id) const noexcept;
        Ref<CameraComponent> CreateCameraComponent(const EngineID& id) const noexcept;

        std::string m_ComponentNodeName;
    };
}
