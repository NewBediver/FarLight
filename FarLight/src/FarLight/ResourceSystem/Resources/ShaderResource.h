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
        explicit ShaderResource() noexcept
            : Resource("", ResourceType::Shader, "")
        {}

        explicit ShaderResource(const std::string& name, const std::string& filePath)
            : Resource(name, ResourceType::Shader, filePath)
        { }

        virtual void Initialize() noexcept override;

        const std::string& GetVertexShaderPath() const noexcept { return m_VertexShaderPath; }
        void SetVertexShaderPath(const std::string& path) noexcept { m_VertexShaderPath = path; }

        const std::string& GetFragmentShaderPath() const noexcept { return m_FragmentShaderPath; }
        void SetFragmentShaderPath(const std::string& path) noexcept { m_FragmentShaderPath = path; }

        const Ref<Shader>& GetShader() const noexcept { return m_Shader; }

    private:
        std::string m_VertexShaderPath;
        std::string m_FragmentShaderPath;

        Ref<Shader> m_Shader;

        template<class Archive>
        void save(Archive& ar, const unsigned int version) const
        {
            ar & FL_SERIALIZE_DERIVED(Resource);
            ar & FL_SERIALIZE_NAMED("VertexShader", m_VertexShaderPath);
            ar & FL_SERIALIZE_NAMED("FragmentShader", m_FragmentShaderPath);
        }

        template<class Archive>
        void load(Archive& ar, const unsigned int version)
        {
            ar & FL_SERIALIZE_DERIVED(Resource);
            ar & FL_SERIALIZE_NAMED("VertexShader", m_VertexShaderPath);
            ar & FL_SERIALIZE_NAMED("FragmentShader", m_FragmentShaderPath);
        }
    };
}

FL_REGISTER_CLASS_VERSION(FarLight::ShaderResource, 0);
