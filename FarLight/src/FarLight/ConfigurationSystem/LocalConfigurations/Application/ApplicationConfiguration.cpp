// This is an open source non-commercial project. Dear PVS-Studio, please check it.
// PVS-Studio Static Code Analyzer for C, C++ and C#: http://www.viva64.com

#include "flpch.h"

#include "FarLight/ConfigurationSystem/LocalConfigurations/Application/ApplicationConfiguration.h"

#include "FarLight/VirtualFileSystem/FileSystem.h"

namespace FarLight
{
    unsigned ApplicationConfiguration::GetWidth() noexcept
    {
        if (!HasOption<unsigned>("MainWindow.Width"))
            SetValue<unsigned>("MainWindow.Width", 1280);

        return GetValue<unsigned>("MainWindow.Width");
    }

    void ApplicationConfiguration::SetWidth(unsigned width) noexcept
    {
        SetValue<unsigned>("MainWindow.Width", width);
    }

    unsigned ApplicationConfiguration::GetHeight() noexcept
    {
        if (!HasOption<unsigned>("MainWindow.Height"))
            SetValue<unsigned>("MainWindow.Height", 720);

        return GetValue<unsigned>("MainWindow.Height");
    }

    void ApplicationConfiguration::SetHeight(unsigned height) noexcept
    {
        SetValue<unsigned>("MainWindow.Height", height);
    }

    std::string ApplicationConfiguration::GetTitle() noexcept
    {
        if (!HasOption<std::string>("MainWindow.Title"))
            SetValue<std::string>("MainWindow.Title", "FarLight Engine");

        return GetValue<std::string>("MainWindow.Title");
    }

    void ApplicationConfiguration::SetTitle(const std::string& title) noexcept
    {
        SetValue<std::string>("MainWindow.Title", title);
    }
}
