#pragma once

#include "FarLight/ConfigurationSystem/LocalConfigurations/Application/ApplicationConfiguration.h"

namespace FarLight
{
    struct WindowProps final
    {
        std::string Title;
        unsigned Width;
        unsigned Height;

        explicit WindowProps(/*std::string&& title = "FarLight Engine", unsigned&& width = 1280, unsigned&& height = 720*/) noexcept
            /*: Title(std::move(title))
            , Width(std::move(width))
            , Height(std::move(height))*/
        {
            ApplicationConfiguration config;
            Title = config.GetTitle();
            Width = config.GetWidth();
            Height = config.GetHeight();
        }
    };
}
