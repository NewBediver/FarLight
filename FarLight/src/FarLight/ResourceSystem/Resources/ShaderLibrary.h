#pragma once

#include <string>
#include <vector>
#include <unordered_map>

#include "FarLight/Core/Core.h"

#include "FarLight/ResourceSystem/ResourceLibrary.h"

#include "FarLight/ResourceSystem/Resources/ShaderResource.h"

#include <boost/lexical_cast.hpp>
#include <boost/functional/hash/hash.hpp>

namespace FarLight
{
    class ShaderLibrary
    {
    public:
        ShaderLibrary(const ShaderLibrary&) = delete;
        ShaderLibrary(ShaderLibrary&&) = delete;
        ShaderLibrary& operator=(const ShaderLibrary&) = delete;
        ShaderLibrary& operator=(ShaderLibrary&&) = delete;

        static ShaderLibrary& GetInstance() noexcept
        {
            static ShaderLibrary s_Instance;
            return s_Instance;
        }

        bool HasById(const boost::uuids::uuid& id) const noexcept
        {
            return m_ShaderResourceLibrary.HasById(id);
        }

        const Ref<ShaderResource>& GetById(const boost::uuids::uuid& id) const noexcept
        {
            FL_CORE_ASSERT(HasById(id), "Library doesn't contain resource with the given id!");

            return m_ShaderResourceLibrary.GetById(id);
        }

        void SetById(const boost::uuids::uuid& key, const Ref<ShaderResource>& value) noexcept
        {
            m_ShaderResourceLibrary.SetById(key, value);
            m_ShaderIds.push_back(boost::lexical_cast<std::string>(key));
        }

        const std::vector<std::string> GetIdsList() const noexcept { return m_ShaderIds; }

    private:
        explicit ShaderLibrary() noexcept {};

        ResourceLibrary<ShaderResource> m_ShaderResourceLibrary;

        std::vector<std::string> m_ShaderIds;
    };
}
