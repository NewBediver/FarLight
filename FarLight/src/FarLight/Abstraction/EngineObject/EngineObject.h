#pragma once

#include <string>

#include <boost/uuid/uuid.hpp>
#include <boost/uuid/uuid_io.hpp>
#include <boost/uuid/random_generator.hpp>

#include <boost/lexical_cast.hpp>

namespace FarLight
{
    class EngineObject
    {
        friend class SceneSerializerConfiguration;
        friend class ComponentSerializerConfiguration;

    public:
        virtual ~EngineObject() noexcept = default;

        explicit EngineObject() noexcept
            : m_Id(boost::uuids::random_generator_mt19937()())
        { }

        explicit EngineObject(boost::uuids::uuid&& id) noexcept
            : m_Id(std::move(id))
        { }

        explicit EngineObject(std::string&& id) noexcept
            : m_Id(boost::lexical_cast<boost::uuids::uuid>(id))
        { }

        template<typename T>
        T GetId() const noexcept
        {
            return boost::lexical_cast<T>(m_Id);
        }

        template<>
        boost::uuids::uuid GetId<boost::uuids::uuid>() const noexcept
        {
            return m_Id;
        }

    private:
        boost::uuids::uuid m_Id;
    };
}
