#pragma once

#include "FarLight/Core/Core.h"

#include <boost/uuid/uuid.hpp>

namespace FarLight
{
    template<typename T>
    class CRUD
    {
    public:
        virtual ~CRUD() noexcept = default;

        virtual Ref<T> Get(const boost::uuids::uuid& id) const noexcept = 0;
        virtual void Set(const Ref<T> entity) noexcept = 0;
        virtual bool Has(const boost::uuids::uuid& id) const noexcept = 0;
        virtual void Erase(const boost::uuids::uuid& id) noexcept = 0;
    };
}
