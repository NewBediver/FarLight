#pragma once
#pragma once

#include <unordered_map>

#include "FarLight/Core/Core.h"

#include <boost/uuid/uuid.hpp>
#include <boost/functional/hash/hash.hpp>

namespace FarLight
{
    template<typename T>
    class ResourceLibrary
    {
    public:
        virtual ~ResourceLibrary() noexcept = default;

        bool IsExists(const boost::uuids::uuid& id) const noexcept
        {
            return m_Library.find(id) != m_Library.end();
        }

        const Ref<T>& Get(const boost::uuids::uuid& id) const noexcept
        {
            FL_CORE_ASSERT(IsExists(id), "Library doesn't contain resource with the given id!");

            return m_Library.at(id);
        }

        void Set(const boost::uuids::uuid& key, const Ref<T>& value) noexcept
        {
            m_Library[key] = value;
        }

        void Remove(const boost::uuids::uuid& key) noexcept
        {
            m_Library.erase(key);
        }

    private:
        std::unordered_map<boost::uuids::uuid, Ref<T>, boost::hash<boost::uuids::uuid>> m_Library;
    };
}
