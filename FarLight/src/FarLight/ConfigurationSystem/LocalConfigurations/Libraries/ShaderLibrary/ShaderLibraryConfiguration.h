#pragma once

#include <vector>

#include "FarLight/ConfigurationSystem/Configuration.h"

#include "FarLight/ResourceSystem/Resources/ShaderResource.h"

#include <boost/uuid/uuid.hpp>

namespace FarLight
{
    class ShaderLibraryConfiguration final
        : public Configuration
    {
    public:
        explicit ShaderLibraryConfiguration() noexcept
            : Configuration("ShaderLibrary")
        { }

        bool IsShaderExists(const boost::uuids::uuid& id) const noexcept;
        bool IsShaderExists(const std::string& name) const noexcept;

        Ref<ShaderResource> GetShader(const boost::uuids::uuid& id) const noexcept;
        Ref<ShaderResource> GetShader(const std::string& name) const noexcept;

        void SetShader(const Ref<ShaderResource>& res) noexcept;

        std::vector<Ref<ShaderResource>> GetSavedShaders() const noexcept;
    };
}
