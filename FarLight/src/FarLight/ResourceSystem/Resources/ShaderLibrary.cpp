#include "flpch.h"

#include "FarLight/Core/Core.h"

#include "FarLight/ResourceSystem/Resources/ShaderLibrary.h"

#include "FarLight/ConfigurationSystem/ConfigurationManager.h"

namespace FarLight
{
    ShaderLibrary::ShaderLibrary() noexcept
    {
        auto shaders = ConfigurationManager::GetInstance().GetShaderLibraryConfiguration()->GetSavedShaders();
        for (const auto& elm : shaders)
        {
            SetByName(elm->GetName(), elm);
        }
    }

    bool ShaderLibrary::IsExistsByName(const std::string& name) const noexcept
    {
        return m_NameToUUID.find(name) != m_NameToUUID.end();
    }

    const Ref<ShaderResource>& ShaderLibrary::GetByName(const std::string& name) const noexcept
    {
        FL_CORE_ASSERT(IsExistsByName(name), "Library doesn't contain resource with the given id!");
        return Get(m_NameToUUID.at(name));
    }

    void ShaderLibrary::SetByName(const std::string& key, const Ref<ShaderResource>& value) noexcept
    {
        m_NameToUUID[key] = value->GetId();
        Set(value->GetId(), value);
    }

    void ShaderLibrary::RemoveByName(const std::string& name) noexcept
    {
        if (m_NameToUUID.find(name) != m_NameToUUID.end())
        {
            Remove(m_NameToUUID[name]);
            m_NameToUUID.erase(name);
        }
    }
}
