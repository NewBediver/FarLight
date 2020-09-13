#include "flpch.h"
#include "ShaderResource.h"

#include <boost/filesystem.hpp>

namespace fs = boost::filesystem;

namespace FarLight
{
    void ShaderResource::Initialize() noexcept
    {
        fs::path vertexShaderPath(GetVertexShaderPath());
        fs::path shaderDirectory = vertexShaderPath.parent_path();

        fs::path rawShaderName = fs::change_extension(vertexShaderPath, "");
        if (GetName().empty())
        {
            SetName(rawShaderName.string());
        }

        fs::path fragmentShaderPath = rawShaderName.append(".fs");
        if (fs::exists(fragmentShaderPath))
        {
            SetFragmentShaderPath(fragmentShaderPath.string());
        }
    }
}


