#pragma once

#include <string>

#include "FarLight/ResourceSystem/ResourceLibrary.h"

#include "FarLight/ResourceSystem/Resources/ShaderResource.h"

namespace FarLight
{
    class ShaderLibrary final
        : public ResourceLibrary<ShaderResource>
    {
    public:
        explicit ShaderLibrary() noexcept;

        bool IsExistsByName(const std::string& name) const noexcept;
        const Ref<ShaderResource>& GetByName(const std::string& name) const noexcept;
        void SetByName(const std::string& key, const Ref<ShaderResource>& value) noexcept;
        void RemoveByName(const std::string& name) noexcept;

    private:
        std::unordered_map<std::string, boost::uuids::uuid> m_NameToUUID;
    };
}
