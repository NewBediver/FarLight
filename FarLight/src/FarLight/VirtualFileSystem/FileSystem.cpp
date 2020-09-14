#include "flpch.h"
#include "FileSystem.h"

#include "FarLight/VirtualFileSystem/FileType.h"

#include "FarLight/ResourceSystem/Resources/ShaderLibrary.h"

#include <boost/uuid/random_generator.hpp>

namespace FarLight
{
    void FileSystem::Initialize() const noexcept
    {
        // root
        DirectoryInitialization(GetRootDirectory());
        // assets
        DirectoryInitialization(GetAssetsDirectory());
        // first level dirs
        DirectoryInitialization(GetEditorDirectory());
        DirectoryInitialization(GetResourcesDirectory());
        // second level dirs
        DirectoryInitialization(GetShadersDirectory());

        LoadShaders(GetShadersDirectory());
    }

    void FileSystem::DirectoryInitialization(const std::string& dir) const noexcept
    {
        fs::path path(dir);
        if (!fs::exists(path)) fs::create_directory(path);
        else if (!fs::is_directory(path)) FL_CORE_ASSERT(false, "This path \"{0}\" must be a directory!", path.string());
    }

    void FileSystem::LoadShaders(const std::string& dir) const noexcept
    {
        fs::directory_iterator it(dir);
        for (fs::directory_iterator it(dir); it != fs::directory_iterator(); ++it)
        {
            if (is_directory(it->path()))
            {
                LoadShaders(it->path().string());
            }
            else
            {
                if (FarLight::GetFileType(it->path().string()) == FileType::VertexShader)
                {
                    LoadShader(it->path().string());
                }
            }
        }
    }

    void FileSystem::LoadShader(const std::string& pathToVert) const noexcept
    {
        boost::uuids::uuid id = boost::uuids::random_generator_mt19937()();
        while (ShaderLibrary::GetInstance().HasById(id)) id = boost::uuids::random_generator_mt19937()();
        Ref<ShaderResource> shaderResource = CreateRef<ShaderResource>();
        shaderResource->SetVertexShaderPath(pathToVert);
        shaderResource->SetFragmentShaderPath(pathToVert.substr(0, pathToVert.length() - 4) + "frag");
        ShaderLibrary::GetInstance().SetById(id, shaderResource);
    }
}


