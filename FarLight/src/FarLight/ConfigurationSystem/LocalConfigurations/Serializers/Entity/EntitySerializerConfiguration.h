#pragma once

#include <string>

#include "FarLight/ConfigurationSystem/Configuration.h"

#include "FarLight/EntityComponentSystem/Scene.h"
#include "FarLight/EntityComponentSystem/Entity.h"

namespace FarLight
{
    class EntitySerializerConfiguration
        : public Configuration
    {
    public:
        explicit EntitySerializerConfiguration() noexcept
            : Configuration("Entities")
            , m_EntityNodeName("Entity")
        { }

        bool IsEntityExists(const EngineID& id) const noexcept;
        Ref<Entity> LoadEntity(const EngineID& id, Ref<Scene> scene) const noexcept;
        void SaveEntity(Ref<Entity> entity) noexcept;
        void EraseEntity(const EngineID& id) noexcept;

    private:
        template<typename T>
        void LoadComponentIfExist(const boost::property_tree::ptree& tree, const std::string& name, Ref<Entity> entity) const noexcept;
        template<typename T>
        void SaveComponentIfExist(boost::property_tree::ptree& tree, const std::string& name, Ref<Entity> entity) noexcept;

        std::string m_EntityNodeName;
    };
}
