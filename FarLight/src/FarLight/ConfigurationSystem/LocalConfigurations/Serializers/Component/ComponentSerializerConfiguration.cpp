#include "flpch.h"

#include "FarLight/ConfigurationSystem/LocalConfigurations/Serializers/Component/ComponentSerializerConfiguration.h"

namespace FarLight
{
    bool ComponentSerializerConfiguration::IsComponentExists(const boost::uuids::uuid& id) const noexcept
    {
        return IsExists<std::string>("Components.Component.EngineObject.Id", boost::lexical_cast<std::string>(id));
    }
}
