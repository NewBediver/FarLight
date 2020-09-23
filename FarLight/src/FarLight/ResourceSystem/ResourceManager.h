#pragma once

#include "FarLight/Core/Core.h"

#include "FarLight/Abstraction/Singleton/Singleton.h"

#include "FarLight/ResourceSystem/Resources/ShaderLibrary.h"

namespace FarLight
{
    class ResourceManager
        : public Singleton<ResourceManager>
    {
    public:
        explicit ResourceManager() noexcept
            : m_ShaderLibrary(CreateScope<ShaderLibrary>())
        { }

        Scope<ShaderLibrary>& GetShaderLibrary() noexcept { return m_ShaderLibrary; }

    private:
        Scope<ShaderLibrary> m_ShaderLibrary;
    };
}
