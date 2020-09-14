#pragma once

#include <string>

#include "FarLight/SerializationSystem/Serialization.h"

#include <boost/uuid/uuid.hpp>

namespace FarLight
{
    enum class ResourceType
    {
        Unknown = 0,
        Shader,
        Image
    };

    class Resource
    {
        FL_REGISTER_SERIALIZABLE;

    public:
        explicit Resource() noexcept;
        explicit Resource(const std::string& name, ResourceType type, const std::string& filePath) noexcept;

        virtual ~Resource() = default;

        virtual void Initialize() noexcept = 0;

        const std::string& GetName() const noexcept { return m_Name; }
        void SetName(const std::string& name) noexcept { m_Name = name; }

        ResourceType GetType() const noexcept { return m_Type; }
        const std::string& GetFilePath() const noexcept { return m_FilePath; }
        const boost::uuids::uuid& GetId() { return m_Id; }
        bool IsInitialized() const noexcept { return m_IsInitialized; }

    private:
        void GenerateAndSetId() noexcept;

        std::string m_Name;
        ResourceType m_Type;
        boost::uuids::uuid m_Id;
        std::string m_FilePath;

        bool m_IsInitialized;

        template<class Archive>
        void save(Archive& ar, const unsigned int version) const
        {
            ar & FL_SERIALIZE_NAMED("Name", m_Name);
            ar & FL_SERIALIZE_NAMED("Type", m_Type);
            ar & FL_SERIALIZE_NAMED("UUID", m_Id);
            ar & FL_SERIALIZE_NAMED("Path", m_FilePath);
        }

        template<class Archive>
        void load(Archive& ar, const unsigned int version)
        {
            ar & FL_SERIALIZE_NAMED("Name", m_Name);
            ar & FL_SERIALIZE_NAMED("Type", m_Type);
            ar & FL_SERIALIZE_NAMED("UUID", m_Id);
            ar & FL_SERIALIZE_NAMED("Path", m_FilePath);
        }
    };
}

FL_REGISTER_CLASS_VERSION(FarLight::Resource, 0);
