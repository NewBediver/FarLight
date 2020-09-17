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

        // first level dirs
        DirectoryInitialization(GetAssetsDirectory());
        DirectoryInitialization(GetSettingsDirectory());

        // second level dirs
        DirectoryInitialization(GetEditorDirectory());
        DirectoryInitialization(GetResourcesDirectory());

        // third level dirs
        DirectoryInitialization(GetShadersDirectory());

        LoadShaders(GetShadersDirectory());
    }

    void FileSystem::WriteToFile(const std::string& path, const std::string& str) const noexcept
    {
        std::ofstream ofs(path);
        ofs << str;
        ofs.close();
    }

    std::string FileSystem::ReadFromFile(const std::string& path) const noexcept
    {
        if (!IsFileExists(path)) return "";
        std::ifstream ifs;
        ifs.exceptions(std::ifstream::failbit | std::ifstream::badbit);
        try
        {
            ifs.open(path);
            std::stringstream ss;
            ss << ifs.rdbuf();
            ifs.close();
            return ss.str();
        }
        catch (const std::ifstream::failure& e)
        {
            FL_CORE_ERROR("Error when try to write to the file: {0}", path);
            FL_CORE_ERROR("Error massage: {0}", e.what());
            FL_CORE_ASSERT(false, "Critical error in file writing!");
        }
        return "";
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


