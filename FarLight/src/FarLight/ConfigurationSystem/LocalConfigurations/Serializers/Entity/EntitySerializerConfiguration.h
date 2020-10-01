#pragma once

#include "FarLight/ConfigurationSystem/Configuration.h"

#include "FarLight/EntityComponentSystem/Entity.h"

#include "FarLight/SerializationSystem/Serialization.h"

namespace FarLight
{
    class EntitySerializerConfiguration
        : public Configuration
    {
    public:
        explicit EntitySerializerConfiguration() noexcept
            : Configuration("Entities")
        { }

        bool IsEntityExists(const boost::uuids::uuid& id) const noexcept;

        Entity GetEntity(const boost::uuids::uuid& id) const noexcept;
        void SetEntity(Entity& entity) noexcept;

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
