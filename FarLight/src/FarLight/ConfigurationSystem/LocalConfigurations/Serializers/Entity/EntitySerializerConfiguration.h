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

        bool IsEntityExists(const boost::uuids::uuid& id) const noexcept;
        Ref<Entity> GetEntity(const boost::uuids::uuid& id, Ref<Scene> scene) const noexcept;
        void SetEntity(Ref<Entity> entity) noexcept;
        void EraseEntity(const boost::uuids::uuid& id) noexcept;

    private:
        std::string m_EntityNodeName;
    };
}
