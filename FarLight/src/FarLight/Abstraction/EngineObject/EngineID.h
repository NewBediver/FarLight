#pragma once

#include <string>

#include <boost/uuid/uuid.hpp>
#include <boost/uuid/uuid_io.hpp>
#include <boost/uuid/random_generator.hpp>
#include <boost/functional/hash/hash.hpp>

#include <boost/lexical_cast.hpp>

namespace FarLight
{
    class EngineID final
    {
        friend std::hash<FarLight::EngineID>;

    public:
        ~EngineID() noexcept = default;

        explicit EngineID() noexcept
            : m_Id(boost::uuids::random_generator_mt19937()())
        { }

        explicit EngineID(std::string&& id) noexcept
            : m_Id(boost::lexical_cast<boost::uuids::uuid>(id))
        { }

        bool operator==(const EngineID& other) const noexcept { return m_Id == other.m_Id; }
        bool operator!=(const EngineID& other) const noexcept { return !(*this == other); }

        std::string ToString() const noexcept { return boost::lexical_cast<std::string>(m_Id); }

    private:
        boost::uuids::uuid m_Id;
    };
}

// Hash-function for EngineID objects
namespace std
{
    template <>
    struct hash<FarLight::EngineID>
    {
        std::size_t operator()(const FarLight::EngineID& key) const
        {
            return boost::hash<boost::uuids::uuid>()(key.m_Id);
        }
    };
}
