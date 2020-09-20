// This is an open source non-commercial project. Dear PVS-Studio, please check it.
// PVS-Studio Static Code Analyzer for C, C++ and C#: http://www.viva64.com

#include "flpch.h"

#include "FarLight/ConfigurationSystem/LocalConfigurations/Directories/DirectoriesConfiguration.h"

#include "FarLight/VirtualFileSystem/FileSystem.h"

namespace FarLight
{
    std::string DirectoriesConfiguration::GetSettings() noexcept
    {
        if (!HasOption<std::string>("Directories.Settings"))
            SetValue<std::string>("Directories.Settings", FileSystem::GetInstance().GetDirectory("Root") + '\\' + "Settings");

        return GetValue<std::string>("Directories.Settings");
    }

    std::string DirectoriesConfiguration::GetAssets() noexcept
    {
        if (!HasOption<std::string>("Directories.Assets"))
            SetValue<std::string>("Directories.Assets", FileSystem::GetInstance().GetDirectory("Root") + '\\' + "Assets");
            
        return GetValue<std::string>("Directories.Assets");
    }

    void DirectoriesConfiguration::SetAssets(const std::string& path) noexcept
    {
        SetValue<std::string>("Directories.Assets", path);
    }

    std::string DirectoriesConfiguration::GetEditor() noexcept
    {
        if (!HasOption<std::string>("Directories.Editor"))
            SetValue<std::string>("Directories.Editor", FileSystem::GetInstance().GetDirectory("Root") + '\\' + "Editor");

        return GetValue<std::string>("Directories.Editor");
    }

    void DirectoriesConfiguration::SetEditor(const std::string& path) noexcept
    {
        SetValue<std::string>("Directories.Editor", path);
    }

    std::string DirectoriesConfiguration::GetShaders() noexcept
    {
        if (!HasOption<std::string>("Directories.Shaders"))
            SetValue<std::string>("Directories.Shaders", FileSystem::GetInstance().GetDirectory("Root") + '\\' + "Shaders");

        return GetValue<std::string>("Directories.Shaders");
    }

    void DirectoriesConfiguration::SetShaders(const std::string& path) noexcept
    {
        SetValue<std::string>("Directories.Shaders", path);
    }
}
