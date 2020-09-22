#pragma once

#include <string>

#include "FarLight/ResourceSystem/Resource.h"

#include "FarLight/Core/Core.h"

#include "FarLight/RenderSystem/Shader/Shader.h"

#include "FarLight/SerializationSystem/Serialization.h"

namespace FarLight
{
    class ShaderResource
        : public Resource
    {
        FL_REGISTER_SERIALIZABLE;

    public:
        explicit ShaderResource(const std::string& name, const std::string& vertexShader, const std::string& fragmentShader) noexcept
            : Resource(ResourceType::Shader)
            , m_Name(name)
            , m_VertexShaderPath(vertexShader)
            , m_FragmentShaderPath(fragmentShader)
            , m_Shader(Shader::Create(vertexShader, fragmentShader))
        { }

        explicit ShaderResource(const boost::uuids::uuid& id, const std::string& name, const std::string& vertexShader, const std::string& fragmentShader) noexcept
            : Resource(id, ResourceType::Shader)
            , m_Name(name)
            , m_VertexShaderPath(vertexShader)
            , m_FragmentShaderPath(fragmentShader)
            , m_Shader(Shader::Create(vertexShader, fragmentShader))
        { }

        const std::string& GetName() const noexcept { return m_Name; }

        const std::string& GetVertexShaderPath() const noexcept { return m_VertexShaderPath; }

        const std::string& GetFragmentShaderPath() const noexcept { return m_FragmentShaderPath; }

        const Ref<Shader>& GetShader() const noexcept { return m_Shader; }

    private:
        template<class Archive>
        void save(Archive& ar, const unsigned int version) const
        {
            ar & FL_SERIALIZE_DERIVED(Resource)
               & FL_SERIALIZE_NAMED("VertexShader", m_VertexShaderPath)
               & FL_SERIALIZE_NAMED("FragmentShader", m_FragmentShaderPath);
        }

        template<class Archive>
        void load(Archive& ar, const unsigned int version)
        {
            ar & FL_SERIALIZE_DERIVED(Resource)
               & FL_SERIALIZE_NAMED("VertexShader", m_VertexShaderPath)
               & FL_SERIALIZE_NAMED("FragmentShader", m_FragmentShaderPath);
        }

        std::string m_Name;

        std::string m_VertexShaderPath;
        std::string m_FragmentShaderPath;

        Ref<Shader> m_Shader;
    };
}

FL_REGISTER_CLASS_VERSION(FarLight::ShaderResource, 0);
