#pragma once

#include <string>

#include "FarLight/SerializationSystem/Serialization.h"

#include <boost/uuid/uuid.hpp>
#include <boost/uuid/uuid_serialize.hpp>
#include <boost/uuid/random_generator.hpp>

#include <boost/lexical_cast.hpp>

namespace FarLight
{
    class EngineObject
    {
        FL_REGISTER_SERIALIZABLE;

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
        //=Serialization part======================================
        template<class Archive>
        void save(Archive& ar, const unsigned int version) const
        {
            ar & FL_SERIALIZE_NAMED("Id", m_Id);
        }

        template<class Archive>
        void load(Archive& ar, const unsigned int version)
        {
            ar & FL_SERIALIZE_NAMED("Id", m_Id);
        }
        //=========================================================

        boost::uuids::uuid m_Id;
    };
}

FL_REGISTER_CLASS_VERSION(FarLight::EngineObject, 0);
