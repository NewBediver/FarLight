#pragma once

#include <string>

#include "FarLight/ConfigurationSystem/Configuration.h"

namespace FarLight
{
    class ApplicationConfiguration final
        : public Configuration
    {
    public:
        explicit ApplicationConfiguration() noexcept
            : Configuration("Application")
        { }

        unsigned GetWidth() noexcept;
        void SetWidth(unsigned width) noexcept;

        unsigned GetHeight() noexcept;
        void SetHeight(unsigned height) noexcept;

        std::string GetTitle() noexcept;
        void SetTitle(const std::string& title) noexcept;
    };
}
