#pragma once

#include <string>

#include <libs/uuid/include/boost/uuid/uuid.hpp>

namespace FarLight
{
    enum class ResourceType
    {
        Unknown = 0,
        VertexShader,
        FragmentShader,
        Image
    };

    class Resource
    {
    public:
        explicit Resource(const std::string& name, ResourceType type) noexcept;
        explicit Resource(const std::string& name, ResourceType type, const std::string& filePath) noexcept;

        virtual ~Resource() = default;

        const std::string& GetName() const noexcept { return m_Name; }
        void SetName(const std::string& name) noexcept { m_Name = name; }

        ResourceType GetType() const noexcept { return m_Type; }
        const std::string& GetFilePath() const noexcept { return m_FilePath; }
        boost::uuids::uuid GetId() { return m_Id; }


    private:
        void GenerateAndSetId() noexcept;

        std::string m_Name;
        ResourceType m_Type;
        boost::uuids::uuid m_Id;
        std::string m_FilePath;
    };
}
