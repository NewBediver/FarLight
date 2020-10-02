#pragma once

#include <string>

#include "FarLight/ResourceSystem/Resource.h"

#include "FarLight/Core/Core.h"

#include "FarLight/RenderSystem/Shader/Shader.h"

namespace FarLight
{
    class ShaderResource
        : public Resource
    {
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
        std::string m_Name;

        std::string m_VertexShaderPath;
        std::string m_FragmentShaderPath;

        Ref<Shader> m_Shader;
    };
}
