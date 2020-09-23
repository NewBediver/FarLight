// This is an open source non-commercial project. Dear PVS-Studio, please check it.
// PVS-Studio Static Code Analyzer for C, C++ and C#: http://www.viva64.com

#include "flpch.h"

#include "FarLight/ConfigurationSystem/LocalConfigurations/Libraries/ShaderLibrary/ShaderLibraryConfiguration.h"

#include "FarLight/VirtualFileSystem/FileSystem.h"

#include <boost/lexical_cast.hpp>
#include <boost/uuid/uuid_io.hpp>
#include <boost/property_tree/xml_parser.hpp>

namespace FarLight
{
    bool ShaderLibraryConfiguration::IsShaderExists(const boost::uuids::uuid& id) const noexcept
    {
        return IsExists<std::string>("Shaders.Shader.Id", boost::lexical_cast<std::string>(id));
    }

    bool ShaderLibraryConfiguration::IsShaderExists(const std::string& name) const noexcept
    {
        return IsExists<std::string>("Shaders.Shader.Name", name);
    }

    Ref<ShaderResource> ShaderLibraryConfiguration::GetShader(const boost::uuids::uuid& id) const noexcept
    {
        if (!IsShaderExists(id))
            return nullptr;

        for (const auto& node : m_PropertyTree.get_child("Shaders"))
        {
            if (node.second.get<std::string>("Id") == boost::lexical_cast<std::string>(id))
            {
                std::string name = node.second.get<std::string>("Name");
                std::string vertextSrc = node.second.get<std::string>("VertexShaderSource");
                std::string fragmentSrc = node.second.get<std::string>("FragmentShaderSource");
                return CreateRef<ShaderResource>(id, name, vertextSrc, fragmentSrc);
            }
            else continue;
        }

        return nullptr;
    }

    Ref<ShaderResource> ShaderLibraryConfiguration::GetShader(const std::string& name) const noexcept
    {
        if (!IsShaderExists(name))
            return nullptr;

        for (const auto& node : m_PropertyTree.get_child("Shaders"))
        {
            if (node.second.get<std::string>("Name") == name)
            {
                boost::uuids::uuid id = boost::lexical_cast<boost::uuids::uuid>(node.second.get<std::string>("Id"));
                std::string vertextSrc = node.second.get<std::string>("VertexShaderSource");
                std::string fragmentSrc = node.second.get<std::string>("FragmentShaderSource");
                return CreateRef<ShaderResource>(id, name, vertextSrc, fragmentSrc);
            }
            else continue;
        }

        return nullptr;
    }

    void ShaderLibraryConfiguration::SetShader(const Ref<ShaderResource>& res) noexcept
    {
        boost::property_tree::ptree tmpTree;
        tmpTree.put<std::string>("Id", boost::lexical_cast<std::string>(res->GetId()));
        tmpTree.put<std::string>("Name", res->GetName());
        tmpTree.put<std::string>("VertexShaderSource", res->GetVertexShaderPath());
        tmpTree.put<std::string>("FragmentShaderSource", res->GetFragmentShaderPath());
        m_PropertyTree.add_child("Shaders.Shader", tmpTree);
    }

    std::vector<Ref<ShaderResource>> ShaderLibraryConfiguration::GetSavedShaders() const noexcept
    {
        std::vector<Ref<ShaderResource>> res;

        for (const auto& node : m_PropertyTree.get_child("Shaders"))
        {
            boost::uuids::uuid id = boost::lexical_cast<boost::uuids::uuid>(node.second.get<std::string>("Id"));
            std::string name = node.second.get<std::string>("Name");
            std::string vertextSrc = node.second.get<std::string>("VertexShaderSource");
            std::string fragmentSrc = node.second.get<std::string>("FragmentShaderSource");
            res.push_back(CreateRef<ShaderResource>(id, name, vertextSrc, fragmentSrc));
        }

        return res;
    }
}
