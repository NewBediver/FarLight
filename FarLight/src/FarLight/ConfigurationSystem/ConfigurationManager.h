#pragma once

#include "FarLight/Core/Core.h"

#include "FarLight/Abstraction/Singleton/Singleton.h"

#include "FarLight/ConfigurationSystem/LocalConfigurations/Application/ApplicationConfiguration.h"
#include "FarLight/ConfigurationSystem/LocalConfigurations/Directories/DirectoriesConfiguration.h"

#include "FarLight/ConfigurationSystem/LocalConfigurations/Libraries/ShaderLibrary/ShaderLibraryConfiguration.h"

namespace FarLight
{
    class ConfigurationManager
        : public Singleton<ConfigurationManager>
    {
    public:
        explicit ConfigurationManager() noexcept
            : m_ApplicationConfig(CreateScope<ApplicationConfiguration>())
            , m_DirectoriesConfig(CreateScope<DirectoriesConfiguration>())
            , m_ShaderLibraryConfig(CreateScope<ShaderLibraryConfiguration>())
        { }

        const Scope<ApplicationConfiguration>& GetApplicationConfiguration() const noexcept { return m_ApplicationConfig; }
        Scope<ApplicationConfiguration>& GetApplicationConfiguration() noexcept { return m_ApplicationConfig; }

        const Scope<DirectoriesConfiguration>& GetDirectoriesConfiguration() const noexcept { return m_DirectoriesConfig; }
        Scope<DirectoriesConfiguration>& GetDirectoriesConfiguration() noexcept { return m_DirectoriesConfig; }

        const Scope<ShaderLibraryConfiguration>& GetShaderLibraryConfiguration() const noexcept { return m_ShaderLibraryConfig; }
        Scope<ShaderLibraryConfiguration>& GetShaderLibraryConfiguration() noexcept { return m_ShaderLibraryConfig; }

    private:
        Scope<ApplicationConfiguration> m_ApplicationConfig;
        Scope<DirectoriesConfiguration> m_DirectoriesConfig;
        Scope<ShaderLibraryConfiguration> m_ShaderLibraryConfig;
    };
}
