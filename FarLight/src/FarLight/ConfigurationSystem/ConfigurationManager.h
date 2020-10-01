#pragma once

#include "FarLight/Core/Core.h"

#include "FarLight/Abstraction/Singleton/Singleton.h"

#include "FarLight/ConfigurationSystem/LocalConfigurations/Application/ApplicationConfiguration.h"
#include "FarLight/ConfigurationSystem/LocalConfigurations/Directories/DirectoriesConfiguration.h"

#include "FarLight/ConfigurationSystem/LocalConfigurations/Libraries/ShaderLibrary/ShaderLibraryConfiguration.h"

#include "FarLight/ConfigurationSystem/LocalConfigurations/Serializers/Component/ComponentSerializerConfiguration.h"
#include "FarLight/ConfigurationSystem/LocalConfigurations/Serializers/Entity/EntitySerializerConfiguration.h"
#include "FarLight/ConfigurationSystem/LocalConfigurations/Serializers/Scene/SceneSerializerConfiguration.h"

namespace FarLight
{
    class ConfigurationManager
        : public Singleton<ConfigurationManager>
    {
        friend class Singleton<ConfigurationManager>;

    public:
        Ref<ApplicationConfiguration> GetApplicationConfiguration() noexcept { return m_ApplicationConfig; }
        Ref<DirectoriesConfiguration> GetDirectoriesConfiguration() noexcept { return m_DirectoriesConfig; }

        Ref<ShaderLibraryConfiguration> GetShaderLibraryConfiguration() noexcept { return m_ShaderLibraryConfig; }

        // Entity Component System serialization
        Ref<ComponentSerializerConfiguration> GetComponentSerializerConfiguration() noexcept { return m_ComponentSerializerConfig; }
        Ref<EntitySerializerConfiguration> GetEntitySerializerConfiguration() noexcept { return m_EntitySerializerConfig; }
        Ref<SceneSerializerConfiguration> GetSceneSerializerConfiguration() noexcept { return m_SceneSerializerConfig; }

    private:
        explicit ConfigurationManager() noexcept
            : m_ApplicationConfig(CreateRef<ApplicationConfiguration>())
            , m_DirectoriesConfig(CreateRef<DirectoriesConfiguration>())
            , m_ShaderLibraryConfig(CreateRef<ShaderLibraryConfiguration>())
            , m_ComponentSerializerConfig(CreateRef<ComponentSerializerConfiguration>())
            , m_EntitySerializerConfig(CreateRef<EntitySerializerConfiguration>())
            , m_SceneSerializerConfig(CreateRef<SceneSerializerConfiguration>())
        { }

        Ref<ApplicationConfiguration> m_ApplicationConfig;
        Ref<DirectoriesConfiguration> m_DirectoriesConfig;

        Ref<ShaderLibraryConfiguration> m_ShaderLibraryConfig;

        Ref<ComponentSerializerConfiguration> m_ComponentSerializerConfig;
        Ref<EntitySerializerConfiguration> m_EntitySerializerConfig;
        Ref<SceneSerializerConfiguration> m_SceneSerializerConfig;
    };
}
