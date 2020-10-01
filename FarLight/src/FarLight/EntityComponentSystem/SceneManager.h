#pragma once

#include <unordered_map>

#include "FarLight/Core/Core.h"

#include "FarLight/Abstraction/Singleton/Singleton.h"
#include "FarLight/Abstraction/CRUD/CRUD.h"

#include "FarLight/ConfigurationSystem/ConfigurationManager.h"

#include "FarLight/EntityComponentSystem/Scene.h"

#include <boost/functional/hash/hash.hpp>

namespace FarLight
{
    class SceneManager
        : public Singleton<SceneManager>
        , public CRUD<Scene>
    {
    public:
        virtual Ref<Scene> Get(const boost::uuids::uuid& id) const noexcept override;
        virtual void Set(const Ref<Scene> entity) noexcept override;
        virtual bool Has(const boost::uuids::uuid& id) const noexcept override;
        virtual void Erase(const boost::uuids::uuid& id) noexcept override;

    private:
        std::unordered_map<boost::uuids::uuid, Ref<Scene>, boost::hash<boost::uuids::uuid>> m_SceneMap;
    };
}
