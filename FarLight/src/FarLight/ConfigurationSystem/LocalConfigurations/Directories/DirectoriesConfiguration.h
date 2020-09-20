#pragma once

#include "FarLight/ConfigurationSystem/Configuration.h"

namespace FarLight
{
    class DirectoriesConfiguration final
        : public Configuration
    {
    public:
        explicit DirectoriesConfiguration() noexcept
            : Configuration("Directories")
        { }

        std::string GetSettings() noexcept;

        std::string GetAssets() noexcept;
        void SetAssets(const std::string& path) noexcept;

        std::string GetEditor() noexcept;
        void SetEditor(const std::string& path) noexcept;

        std::string GetShaders() noexcept;
        void SetShaders(const std::string& path) noexcept;
    };
}
